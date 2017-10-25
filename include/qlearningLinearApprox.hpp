#include <math.h>
#include <tuple>
#include <vector>
#include <unordered_map>

#include "world.hpp"

//!
//! \file     qlearningLinearApprox.hpp
//! \author   Lisa Martini
//! \brief    qlearning class
//! \version  1.0
//! \date     18 Octobre 2017
//!
//! This class provides the qlearning's robot cleaner public interface.
//!

//! \namespace  cleaner
//!
//! Namespace grouping all tools required for the robot cleaner project.
namespace cleaner{
  class qlearningLinearApprox{
  protected:
    world w;
    int episode = 0, episodes;
    double MIN = -100000, MAX = 100000;
    int NBF = 2;//nb features
    double gamma, epsilon, learning_rate;
    //std::unordered_map<int, std::unordered_map<int, double>> qf;
    std::vector<double> teta;

    void backup(int /*current state*/, int /*action*/, int /*next state*/, double /*reward*/);
    void plots();
    void init();

  public:
    ~qlearningLinearApprox();
    qlearningLinearApprox(world const&, double, double, double, int);
    void solve();
    int greedy(int);
    double getValueAt(int);
    double approxQf(std::vector<double>const&J ); // Erreur ?
  };
}
