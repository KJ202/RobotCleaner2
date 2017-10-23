#include <numeric>
#include "../include/qlearningLinearApprox.hpp"


namespace cleaner{
    qlearningLinearApprox::qlearningLinearApprox(world const& w, double epsilon, double learning_rate, double gamma, int episodes) : w(w), epsilon(epsilon), learning_rate(learning_rate), gamma(gamma), episodes(episodes){
    }

    qlearningLinearApprox::~qlearningLinearApprox(){
    }

    void qlearningLinearApprox::plots(){
      std::cout << "getValueAt" << this->getValueAt(0) << std::endl;
  }

    void qlearningLinearApprox::solve(){
      double r;
      int s, a, ss;
      this->init();

      do{
        s=0;
        for(int i=0; i<100; i++){
          a = greedy(s);
          std::cout << "J'effectue le greedy" << std::endl;
          w.execute(s, static_cast<action>(a), ss, r);
          std::cout << "J'effectue le execute" << std::endl;
          this->backup(s,a,ss,r);
          std::cout << "J'effectue le backup" << std::endl;
          s = ss;
        }

        this->plots();
      }while( ++this->episode < this->episodes );
    }

    double qlearningLinearApprox::getValueAt(int s){
      double value = MIN;
      for(int a=0; a<action::END; ++a){
      	std::vector<double>const& phiSA = w.getState(s)->getFeatures(a);
      	double qfapprox = this->approxQf(phiSA);
        value = std::max(value, qfapprox);//here
      } return value;
    }

    int qlearningLinearApprox::greedy(int s){
      int agreedy;
      double value = MIN;
      double rd = rand() / ((double) RAND_MAX);

      if( rd > this->epsilon ) {
        for(int a=0; a<action::END; ++a){
          std::vector<double>const& phiSA = w.getState(s)->getFeatures(a);
          double qfapprox = this->approxQf(phiSA);
          std::cout << "qfapprox = " << qfapprox << std::endl;
          if( value < qfapprox ){ //here
            std::cout << "Je rentre dans la boucle if";
            agreedy = a;
            value = qfapprox;
          }
        }
      }

      else {
        std::cout << "Je rentre dans la boucle else";
        agreedy = rand() % 7;
      }

      std::cout << "J'ai retourné le agreedy" << std::endl;
      return agreedy;
    }
    
    double qlearningLinearApprox::approxQf(std::vector<double>const& phisa){
    	double approx=0.0;
    	approx = std::inner_product(phisa.begin(),phisa.end(),this->teta.begin(),0.0);
    	return approx;
    }

    void qlearningLinearApprox::backup(int s, int a, int ss, double r){
      std::cout << "Je suis dans la fonction backup" << std::endl;
      int i;
      std::vector<double>const& phiSA = w.getState(s)->getFeatures(a);
      double approxQfSS = this->getValueAt(ss);
      std::cout << "Je vais appliquer la fonction sensible";
      double qfapprox = this->approxQf(phiSA);
      double tDiff = this->learning_rate * (r + this->gamma * approxQfSS - qfapprox);
      
      for(i=0;i < this->teta.size(); ++i){
      	this->teta[i] = this->teta[i] + tDiff; 	
      }
      
    }

    void qlearningLinearApprox::init(){
      /*init teta vector arbitrary*/
      this->teta.assign(this->NBF*action::END,0.0);
       
    }
}
