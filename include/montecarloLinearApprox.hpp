#include <math.h>
#include <tuple>
#include <vector>
#include <unordered_map>

#include "world.hpp"

//!
//! \file     montecarloLinearApprox.hpp
//! \author   Jilles S. Dibangoye
//! \brief    montecarloLinearApprox class
//! \version  1.0
//! \date     15 Octobre 2017
//!
//! This class provides the montecarloLinearApprox's robot cleaner public interface.
//!

//! \namespace  cleaner
//!
//! Namespace grouping all tools required for the robot cleaner project.
namespace cleaner{
    class montecarloLinearApprox{
    protected:
        world w;
        double gamma, epsilon, learning_rate=0.01;
        int NBF = 3;//nb features
        int cepisode = 0, episodes;
        double MIN = -100000, MAX = 100000;
        std::vector<std::tuple<int, int, int>> episode;

        // backup the position of a pair of state and action in the current episode
        std::unordered_map<int, std::unordered_map<int, int>> pf;

        // q-value function
        std::unordered_map<int, std::unordered_map<int, double>> qf;

        // track the mean of any pair of state and action
        std::unordered_map<int, std::unordered_map<int, std::pair<double, int>>> jf;
        std::unordered_map<int, std::unordered_map<int, std::vector<double>>> phiSA;
        std::vector<double> teta;


        double getReturn(int i);
        void setEpisode();
        void backup();
        void plots();
        void init(int);

    public:
        ~montecarloLinearApprox();
        montecarloLinearApprox(world const&, double, double, int);
        void solve();
        int greedy(int);
        double getValueAt(int);

        double approxMC( std::vector<double> phisa);

        void addFeaturesVectorsForNewS(int ns);
    };
}
