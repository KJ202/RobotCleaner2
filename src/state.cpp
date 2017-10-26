#include "../include/state.hpp"
#include "../include/world.hpp"

namespace cleaner{
  state::state(std::vector<bool>const grid, bool base, size battery, size pose, size width, size height): grid(grid), base(base), battery(battery), pose(pose), width(width),height(height){}

  state::~state(){}

  std::vector<bool>const& state::getGrid() const{
    return grid;
  }

  bool state::getBase() const{
    return base;
  }

  size state::getBattery() const{
    return battery;
  }

  size state::getPose() const{
    return pose;
  }

  int state::getDistDirt()const{ //features get distance to closer dirty cell excepting the current cell
    /*find dirt between base and position */
      int dirtPose = pose-1;
      int dist = 0;

      while(dirtPose>=0){
         if(grid[dirtPose]== false){
             dist=(int) (pose/width)-(dirtPose/width) +std::abs((int)(pose%width)-(dirtPose%width));
             break;
         }
         dirtPose--;
      }
      /*find dirt after position */
      dirtPose =pose+1;
      while(dirtPose<width*height){
          if(grid[dirtPose]== false){
              int distAft = (int) (dirtPose/width)-(pose/width) +std::abs((int)(pose%width)-(dirtPose%width));
              dist = std::min(dist,distAft);
              break;
          }
          dirtPose++;
      }
      return dist;
  }

   int  state::getCurrentDirt()const{
       int res = grid[pose] == false ? 1 : 0;
       return res;
    }

  int state::getBaseDistance()const{
    /*for simplicity basePosition = 0*/
    int b = 0;

    int dist;
    dist=(int) (pose/width)+pose%width;
    return dist;
  }

/*
* for now on 2 features only 
* battery level 
* and distance to the base 
* so the length of the vector is NBF*len(action) for now on its 14
* 
*/

  
  std::vector<double> state::getFeatures(int a){

    std::vector<double> features;

    for(int j = 0 ;j<action::END;++j){
        if (j == a){
            features.push_back((double)battery);
            features.push_back((double)this->getBaseDistance());
            features.push_back((double) this->getCurrentDirt());
           // features.push_back((double)this->getDistDirt());
        }
        else{
            features.push_back(0.0);
            features.push_back(0.0);
            features.push_back(0.0);

        }
    }
     // std::cout <<"\n" ;
     //print for testing
       /*for (auto i = features.begin(); i != features.end(); ++i)
            std::cout << *i << ' ';*/
    return features;
  }
}
