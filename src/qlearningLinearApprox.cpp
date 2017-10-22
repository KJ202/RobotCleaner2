#include "../include/qlearningLinearApprox.hpp"


namespace cleaner{
    qlearningLinearApprox::qlearningLinearApprox(world const& w, double epsilon, double learning_rate, double gamma, int episodes) : w(w), epsilon(epsilon), learning_rate(learning_rate), gamma(gamma), episodes(episodes){
    }

    qlearningLinearApprox::~qlearningLinearApprox(){
    }

    void qlearningLinearApprox::plots(){
      std::cout << this->getValueAt(0) << std::endl;
  }

    void qlearningLinearApprox::solve(){
      double r;
      int s, a, ss;
      this->init();

      do{
        s=0;
        for(int i=0; i<100; i++){
          a = greedy(s);
          w.execute(s, static_cast<action>(a), ss, r);
          this->backup(s,a,ss,r);
          s = ss;
        }

        this->plots();
      }while( ++this->episode < this->episodes );
    }

    double qlearningLinearApprox::getValueAt(int s){
      double value = MIN;
      for(int a=0; a<action::END; ++a){
        value = std::max(value, this->qf[s][a]);
      } return value;
    }

    int qlearningLinearApprox::greedy(int s){
      int agreedy;
      double value = MIN;
      double rd = rand() / ((double) RAND_MAX);

      if( rd > this->epsilon ) {
        for(int a=0; a<action::END; ++a){
          if( value < this->qf[s][a] ){
            agreedy = a;
            value = this->qf[s][a];
          }
        }
      }

      else {
        agreedy = rand() % 7;
      }

      return agreedy;
    }
    
    double qlearningLinearApprox::approxQf(int** phisa){
    	double approx=0.0;
    	for(int i = 0; i < this->NBF ;i++){
	    	for (int j = 0; j < 7; ++j)
	    	{
	    		approx += phisa[i][j]*this->teta[i]; 	
	    	}
    	}
    	return approx;
    }

    void qlearningLinearApprox::backup(int s, int a, int ss, double r){
      int i;
      int** phiSA = w.getState(s)->getFeatures(a);
      double approxQfSS = this->getValueAt(ss);
      for(i=0;i < this->NBF; ++i){
      	this->teta[i] = this->teta[i] + this->learning_rate * (r + this->gamma * approxQfSS - this->qf[s][a])*phiSA[i][a];
      	
      }
      this->qf[s][a] = this->approxQf(phiSA); //new value because teta has been updated
      std::cout << this->qf[s][a] << std::endl;
    }

    void qlearningLinearApprox::init(){
      /*init teta vector arbitrary*/
      this->teta.assign(2,0.0);
     
     	/*init qf with qpprox value*/
      for(int s=0; s<this->w.getNumStates(); ++s){
        this->qf.emplace(s,  std::unordered_map<int, double>());
        for(int a=0; a<action::END; ++a){
          int** phiSA = w.getState(s)->getFeatures(a);
          this->qf.at(s).emplace(a, this->approxQf(phiSA));
        }
      }
    }
}
