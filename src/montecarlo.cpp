#include "../include/montecarlo.hpp"


namespace cleaner{
    montecarlo::montecarlo(world const& w, double epsilon, double gamma, int episodes) : w(w), epsilon(epsilon), gamma(gamma), episodes(episodes){
    }

    montecarlo::~montecarlo(){
    }

    void montecarlo::plots(){
      std::cout << this->getValueAt(0) << std::endl;
  }

    void montecarlo::solve(){
      this->init();

      do{
        this->setEpisode();
        this->backup();

        this->plots();
      }while( ++this->cepisode < this->episodes );
    }


    // Return the performance
    double montecarlo::getValueAt(int s){
      double value = MIN;
      for(int a=0; a<action::END; ++a){
        value = std::max(value, this->qf[s][a]);
      } return value;
    }

    action montecarlo::greedy(int s){
      action agreedy;
      double value = MIN;
      for(int a=0; a<action::END; ++a){
        if( value < this->qf[s][a] ){
          agreedy = static_cast<action>(a);
          value = this->qf[s][a];
        }
      } return agreedy;
    }

    double montecarlo::getReturn(int pose){
      double r = 0;
      for(int i=pose; i<100; i++){
        r += pow( this->gamma, i-pose ) * std::get<2>(this->episode[i]);
      }

      return r;
    }


    void montecarlo::setEpisode(){
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

      for (int i = 0; i < 10; ++i)
      {
        std::cout << "State,action,reward : " << std::get<0>(this->episode[i]) << std::get<1>(this->episode[i])<< std::get<2>(this->episode[i]) << std::endl;
      }
    }

    void montecarlo::backup(){
      int s, a;
      double old, cumul;

      for(s=0; s<this->w.getNumStates(); ++s){
        for(a=0; a<action::END; ++a){
          if( this->pf[s][a] > -1 ){
            std::cout << "I get the return :" << this->getReturn(this->pf[s][a])<< std::endl;

/*            old = this->qf[s][a];
            cumul = this->getReturn(this->pf[s][a]);
            this->jf[s][a].second ++;
            this->jf[s][a].first += cumul;
            this->qf[s][a] = this->jf[s][a].first / this->jf[s][a].second;*/

          }
        }
      }
    }

    void montecarlo::init(){
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
    }

}
