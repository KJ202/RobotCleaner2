#include "../include/state.hpp"

namespace cleaner{
  state::state(std::vector<bool>const grid, bool base, size battery, size pose): grid(grid), base(base), battery(battery), pose(pose){}

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

  int** state::getFeatures(action a){

    int** features = new int*[2];
    for(int i = 0; i < 2; ++i)
        features[i] = new int[7];


    for (int i = 0; i < 2; ++i)
    {
      for (int j = 0; j < 7; ++j)
      {
        if (a == j)
        {
          features[i][j]= battery;
          features[i][j]= base;          
        }

        else
        {
          features[i][j]= 0;
          features[i][j]= 0;           
        }

      }
    }

    return features;
  }
}
