  #include <time.h>

#include "../include/dp.hpp"
#include "../include/world.hpp"
#include "../include/qlearning.hpp"
#include "../include/qlearningLinearApprox.hpp"
#include "../include/montecarlo.hpp"
#include "../matplotlib-cpp/matplotlibcpp.h"


  namespace plt = matplotlibcpp;


int main(){
  srand (time(NULL));
  int nbf = 3;
  int nbepisode = 1000;
  cleaner::world w(2,2,3,nbf);//width/height/cbattery/NBF
  std::cout << w << std::endl;

  std::vector<double> x(nbepisode);
  for(int i =0;i<nbepisode;++i){
      x.at(i)=i;
  }


  /*cleaner::dp dp_solver(w, 0.001, 0.99);
  dp_solver.solve();
  std::cout << "dp_solver("<< *w.getState(0) << ") = " << dp_solver.getValueAt(0) << std::endl;*/

 /* cleaner::montecarlo mc_solver(w, 0.1, 0.99, 100);
  mc_solver.solve();
  std::cout << "mc_solver("<< *w.getState(0) << ") = " << mc_solver.getValueAt(0) << std::endl;*/

  cleaner::qlearning q_solver(w, 0.1, 0.1, 0.99, nbepisode);
  std::vector<double> ql_plot = q_solver.solve();
  std::cout << "q_solver("<< *w.getState(0) << ") = " << q_solver.getValueAt(0) << std::endl;

  cleaner::qlearningLinearApprox qla_solver(w, 0.1, 0.1, 0.99, nbepisode,nbf);
  std::vector<double> qla_plot = qla_solver.solve();
  std::cout << "qla_solver("<< *w.getState(0) << ") = " << qla_solver.getValueAt(0) << std::endl;

   nbf = 4;
  cleaner::world w2(2,2,3,nbf);//width/height/cbattery/NBF
  std::cout << w2 << std::endl;
    cleaner::qlearningLinearApprox qla4_solver(w2, 0.1, 0.1, 0.99, nbepisode,nbf);
    std::vector<double> qla4_plot = qla4_solver.solve();
    std::cout << "qla_solver("<< *w2.getState(0) << ") = " << qla4_solver.getValueAt(0) << std::endl;


    plt::annotate("grid 2*2 battery 3", (0,0),(200,1));

    // Plot a line whose name will show up as "qla" in the legend.
    plt::named_plot("qlearning", x, ql_plot);
    plt::named_plot("qlearningApprox3features", x, qla_plot);
    plt::named_plot("qlearningApprox4features", x, qla4_plot);

    // Set x-axis to interval [0,1000]
    plt::xlim(0, 1000);
    // Enable legend.
    plt::legend();
    // Save the image (file format is determined by the extension)
    plt::save("./ql_qla3_qla4(2*2_3).png");

  return 0;
}
