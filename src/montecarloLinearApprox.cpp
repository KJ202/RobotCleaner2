//
// Created by Kian JAMALI on 25/10/2017.
//

#include "../include/montecarloLinearApprox.hpp"
#include <numeric>



namespace cleaner{
    montecarloLinearApprox::montecarloLinearApprox(world const& w, double epsilon, double gamma, int episodes) : w(w), epsilon(epsilon), gamma(gamma), episodes(episodes){
    }

    montecarloLinearApprox::~montecarloLinearApprox(){
    }

    void montecarloLinearApprox::plots(){
        std::cout << this->getValueAt(0) << std::endl;
    }

    void montecarloLinearApprox::solve(){
        this->init();

        do{
            this->setEpisode();
            this->backup();

            this->plots();
        }while( ++this->cepisode < this->episodes );
    }


    double montecarloLinearApprox::approxMC(std::vector<double>const& phisa){
        double approx=0.0;
        approx = std::inner_product(phisa.begin(),phisa.end(),this->teta.begin(),0.0);
        return approx;
    }


    // Return the performance
    double montecarloLinearApprox::getValueAt(int s){
        double value = MIN;
        for(int a=0; a<action::END; ++a){
            std::vector<double>const& phiSA = w.getState(s)->getFeatures(a);
            double mcapprox = this->approxMC(phiSA);
            value = std::max(value, mcapprox);
        } return value;
    }

    action montecarloLinearApprox::greedy(int s){
        action agreedy;
        double value = MIN;
        for(int a=0; a<action::END; ++a){
            std::vector<double>const& phiSA = w.getState(s)->getFeatures(a);
            double mcapprox = this->approxMC(phiSA);
            if( value < mcapprox ){
                agreedy = static_cast<action>(a);
                value = mcapprox;
            }
        } return agreedy;
    }

    double montecarloLinearApprox::getReturn(int pose){
        double r = 0;
        for(int i=pose; i<100; i++){
            r += pow( this->gamma, i-pose ) * std::get<2>(this->episode[i]);
        }

        return r;
    }


    void montecarloLinearApprox::setEpisode(){
        action a;
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

            w.execute(s, a, ss, r);

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
                    std::vector<double>const& phiSA = w.getState(s)->getFeatures(a);
                    double mcapprox = this->approxMC(phiSA);
                    double G = this->getReturn(this->pf[s][a]);

                    double tDiff = this->learning_rate * (G - mcapprox);

                    for(int i=0;i < this->teta.size(); ++i){
                        this->teta[i] = this->teta[i] + tDiff*phiSA[i];
                    }

                    std::cout << "teta[0] = " << this->teta[0] << std::endl;
                    std::cout << "teta[1] = " << this->teta[1] << std::endl;

/*            old = this->qf[s][a];
            cumul = this->getReturn(this->pf[s][a]);
            this->jf[s][a].second ++;
            this->jf[s][a].first += cumul;
            this->qf[s][a] = this->jf[s][a].first / this->jf[s][a].second;*/

                }
            }
        }
    }

    void montecarloLinearApprox::init(){
        for(int s=0; s<this->w.getNumStates(); ++s){
            this->pf.emplace(s,  std::unordered_map<int, int>());
            this->qf.emplace(s,  std::unordered_map<int, double>());
            this->jf.emplace(s,  std::unordered_map<int, std::pair<double, int>>());
            for(int a=0; a<action::END; ++a){
                this->pf.at(s).emplace(a, -1);
                this->qf.at(s).emplace(a, 0.0);
                this->jf.at(s).emplace(a, std::pair<double, int>(0.0, 0));
            }
        }

        this->teta.assign(this->NBF*action::END,0.0);
    }

}
