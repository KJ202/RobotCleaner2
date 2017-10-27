//
// Created by Kian JAMALI on 25/10/2017.
//

#include "../include/montecarloLinearApprox.hpp"
#include <numeric>



namespace cleaner{
    montecarloLinearApprox::montecarloLinearApprox(world const& w, double epsilon, double learning_rate, double gamma, int episodes, int nbf) : w(w), epsilon(epsilon), learning_rate(learning_rate), gamma(gamma), episodes(episodes), NBF(nbf){
    }

    montecarloLinearApprox::~montecarloLinearApprox(){
    }

    double montecarloLinearApprox::plots(){
        //std::cout << this->getValueAt(0) << std::endl;
        return this->getValueAt(0) ;

    }
    std::vector<double> montecarloLinearApprox::solve(){
        this->init(0);
        std::vector <double> plotVector;

        do{
            this->setEpisode();
            this->backup();

            plotVector.push_back(this->plots());
        }while( ++this->cepisode < this->episodes );
    }


    double montecarloLinearApprox::approxMC(std::vector<double> phisa){
        double approx=0.0;
        approx = std::inner_product(phisa.begin(),phisa.end(),this->teta.begin(),0.0);
        return approx;
    }


    // Return the performance
    double montecarloLinearApprox::getValueAt(int s){
        double value = MIN;
        for(int a=0; a<action::END; ++a){
            double mcapprox = this->approxMC(this->phiSA[s][a]);
            value = std::max(value, mcapprox);
        } return value;
    }

    int montecarloLinearApprox::greedy(int s){
        int agreedy;
        double value = MIN;
        double rd = rand() / ((double) RAND_MAX);
        if( rd > this->epsilon ) {
            for(int a=0; a<action::END; ++a){
                //at this point s has already been initialized
                this->addFeaturesVectorsForNewS(s);
                double mcapprox = this->approxMC(this->phiSA[s][a]);
                if( value < mcapprox ){ //here

                    agreedy = a;
                    value = mcapprox;
                }
                if(s ==0){
                    agreedy = 4;
                    value = mcapprox;
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


    double montecarloLinearApprox::getReturn(int pose){
        double r = 0;
        for(int i=pose; i<100; i++){
            r += pow( this->gamma, i-pose ) * std::get<2>(this->episode[i]);
        }

        return r;
    }


    void montecarloLinearApprox::setEpisode(){
        int a;
        double r;
        this->episode.clear();
        int s, ss;

        for(s=0; s<this->w.getNumStates(); ++s){
            for(int a=0; a<action::END; ++a){
                this->pf[s][a] = -1;
            }
        }

        s = 0;
        double rd = rand() / ((double) RAND_MAX);
        for(int i=0; i<100; i++){
            if( rd > this->epsilon ) {
                a = greedy(s);
            }else {
                a = static_cast<action>(rand() % 7);
            }

            w.execute(s, static_cast<action>(a), ss, r);

            this->episode.push_back(std::make_tuple(s, a, r));

            if(this->pf[s][a] == -1){
                this->pf[s][a] = i;
            }

            s = ss;
        }

    }

    void montecarloLinearApprox::backup(){
        int s, a;
        double old, cumul;

        for(s=0; s<this->w.getNumStates(); ++s){
            for(a=0; a<action::END; ++a){
                if( this->pf[s][a] > -1 ){
                    this->addFeaturesVectorsForNewS(s);
                    double mcapprox = this->approxMC(this->phiSA[s][a]);
                    double G = this->getReturn(this->pf[s][a]);

                    double tDiff = this->learning_rate * (G - mcapprox);

                    for(int i=0;i < this->teta.size(); ++i){
                        this->teta[i] = this->teta[i] + tDiff*this->phiSA[s][a][i];
                    }

                    for (int j = 0; j < teta.size() ; ++j) {

                    }



/*            old = this->qf[s][a];
            cumul = this->getReturn(this->pf[s][a]);
            this->jf[s][a].second ++;
            this->jf[s][a].first += cumul;
            this->qf[s][a] = this->jf[s][a].first / this->jf[s][a].second;*/

                }
            }
        }
    }



    void montecarloLinearApprox::addFeaturesVectorsForNewS(int ns){
        this->phiSA.emplace(ns,  std::unordered_map<int, std::vector<double>>());

        for(int a=0; a<action::END; ++a){

            //std::cout << "\n state " << ns << " : " << std::endl;
            this->phiSA.at(ns).emplace(a, w.getState(ns)->getFeatures(a));

        }
    }

    void montecarloLinearApprox::init(int fs) {
        /*init teta vector arbitrary*/
        int len = this->NBF * action::END;
        this->teta.assign(len, 1.0);


        this->phiSA.emplace(fs, std::unordered_map<int, std::vector<double>>());

        for (int a = 0; a < action::END; ++a) {
            //std::cout << "\n state " << fs << " : " << std::endl;
            this->phiSA.at(fs).emplace(a, w.getState(fs)->getFeatures(a));

        }
    }

}
