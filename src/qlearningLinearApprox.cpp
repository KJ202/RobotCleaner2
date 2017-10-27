#include <numeric>
#include "../include/qlearningLinearApprox.hpp"


namespace cleaner{
    qlearningLinearApprox::qlearningLinearApprox(world const& w, double epsilon, double learning_rate, double gamma, int episodes, int nbf) : w(w), epsilon(epsilon), learning_rate(learning_rate), gamma(gamma), episodes(episodes), NBF(nbf){
    }

    qlearningLinearApprox::~qlearningLinearApprox(){
    }

    double qlearningLinearApprox::plots(){
      //std::cout << this->getValueAt(0) << std::endl;
       return this->getValueAt(0) ;

  }

    std::vector<double> qlearningLinearApprox::solve(){
      double r;
      int s, a, ss;
      this->init(0);
        std::vector <double> plotVector;

      do{
        s=0;
        for(int i=0; i<100; i++){
          a = greedy(s);
          w.execute(s, static_cast<action>(a), ss, r);
            //std::cout <<"\nreturn s"<< s <<" "<< w.getState(s)->getBattery() << w.getState(s)->getPose() <<std::endl;
            //std::cout << "\nreturn ss"<< ss <<" " <<w.getState(ss)->getBattery() << w.getState(ss)->getPose() <<std::endl;
          this->backup(s,a,ss,r);
          s = ss;
        }

        plotVector.push_back(this->plots());
      }while( ++this->episode < this->episodes );
        return plotVector;
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
            if(s ==0){
                agreedy = 4;
                value = qfapprox;
                break;
            }
        }
      }

      else {
        agreedy = rand() % 7;
      }

        //std::cout << rand << " action returned " <<agreedy<< std::endl;
      return agreedy;
    }
    
    double qlearningLinearApprox::approxQf(std::vector<double> phisa){
    	double approx;
    	approx = std::inner_product(phisa.begin(),phisa.end(),this->teta.begin(),0.0);

        //std::cout << "approx : " << approx <<  std::endl;
    	return approx;
    }

    void qlearningLinearApprox::backup(int s, int a, int ss, double r){
      int i;
      this->addFeaturesVectorsForNewS(ss);
      double approxQfSS = this->getValueAt(ss);
        //std::cout << "\napproxQfss" << approxQfSS <<std::endl;
      double qfapprox = this->approxQf(this->phiSA[s][a]);
      double tDiff = this->learning_rate * (r + this->gamma * approxQfSS - qfapprox);

      for(i=0;i < this->teta.size(); ++i){
      	this->teta[i] = this->teta[i] + tDiff*this->phiSA[s][a][i];
        //std::cout << "teta"<<i<< " " << teta[i] << std::endl;
      }
      
    }

    void qlearningLinearApprox::addFeaturesVectorsForNewS(int ns){
        this->phiSA.emplace(ns,  std::unordered_map<int, std::vector<double>>());

        for(int a=0; a<action::END; ++a){

            //std::cout << "\n state " << ns << " : " << std::endl;
             this->phiSA.at(ns).emplace(a, w.getState(ns)->getFeatures(a));

        }
    }

    void qlearningLinearApprox::init(int fs){
      /*init teta vector arbitrary*/
        int len = this->NBF*action::END;
        this->teta.assign(len,1.0);


        this->phiSA.emplace(fs,  std::unordered_map<int, std::vector<double>>());

        for(int a=0; a<action::END; ++a){
            //std::cout << "\n state " << fs << " : " << std::endl;
            this->phiSA.at(fs).emplace(a, w.getState(fs)->getFeatures(a));

        }



    }
}
