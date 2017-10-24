#include <numeric>
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
            std::cout <<"\nreturn s"<< w.getState(s)->getBattery() << w.getState(s)->getPose() <<std::endl;
            std::cout << "\nreturn ss" <<w.getState(ss)->getBattery() << w.getState(ss)->getPose() <<std::endl;
          this->backup(s,a,ss,r);
          s = ss;
        }

        this->plots();
      }while( ++this->episode < this->episodes );
    }

    double qlearningLinearApprox::getValueAt(int s){
      double value = MIN;
      for(int a=0; a<action::END; ++a){
          //at this point s has already been initialized
        double qfapprox = this->approxQf(this->phiSA[s][a]);
        value = std::max(value, qfapprox);//here
      } return value;
    }

    int qlearningLinearApprox::greedy(int s){
      int agreedy;
      double value = MIN;
      double rd = rand() / ((double) RAND_MAX);
      if( rd > this->epsilon ) {
        for(int a=0; a<action::END; ++a){
            //at this point s has already been initialized
            double qfapprox = this->approxQf(this->phiSA[s][a]);
            //std::cout << "qfapprox = " << qfapprox << std::endl;
            if( value < qfapprox ){ //here

                agreedy = a;
                value = qfapprox;
            }
        }
      }

      else {
        agreedy = rand() % 7;
      }
        std::cout << rand << "action returned" <<agreedy<< std::endl;
      return agreedy;
    }
    
    double qlearningLinearApprox::approxQf(std::vector<double>const& phisa){
    	double approx=0.0;
    	approx = std::inner_product(phisa.begin(),phisa.end(),this->teta.begin(),0.0);
        std::cout << "approx : " << approx << std::endl;
    	return approx;
    }

    void qlearningLinearApprox::backup(int s, int a, int ss, double r){
      int i;
      this->addFeaturesVectorsForNewS(ss);
      double approxQfSS = this->getValueAt(ss);
      double qfapprox = this->approxQf(this->phiSA[s][a]);
      double tDiff = this->learning_rate * (r + this->gamma * approxQfSS - qfapprox);
      //std::cout << "\n diff" << tDiff << std::endl;
      for(i=0;i < this->teta.size(); ++i){
      	this->teta[i] = this->teta[i] + tDiff;
        //std::cout << "teta"<<i<< " " << teta[i] << std::endl;
      }
      
    }

    void qlearningLinearApprox::addFeaturesVectorsForNewS(int ns){
        this->phiSA.emplace(ns,  std::unordered_map<int, std::vector<double>>());

        for(int a=0; a<action::END; ++a){
             this->phiSA.at(ns).emplace(a, w.getState(ns)->getFeatures(a));
        }
    }

    void qlearningLinearApprox::init(){
      /*init teta vector arbitrary*/
        int len = this->NBF*action::END;
        this->teta.assign(len,0.0);
        this->phiSA.emplace(0,  std::unordered_map<int, std::vector<double>>());

        for(int a=0; a<action::END; ++a){
            this->phiSA.at(0).emplace(a, w.getState(0)->getFeatures(a));
        }

    }
}
