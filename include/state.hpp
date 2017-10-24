/*=============================================================================
  Copyright (c) 2017-2018 Jilles Steeve Dibangoye
==============================================================================*/
#pragma once

#include <memory>
#include <vector>
#include <string>

#include "types.hpp"
#include "action.hpp"


//!
//! \file     state.hpp
//! \author   Jilles S. Dibangoye
//! \brief    state class
//! \version  1.0
//! \date     15 Octobre 2017
//!
//! This class provides the state's robot cleaner public interface.
//!

//! \namespace  cleaner
//!
//! Namespace grouping all tools required for the robot cleaner project.
namespace cleaner{
  class state{
  protected:
    int NBF = 2;//nb features
    bool base;
    size battery, pose,height,width;
    std::vector<bool> grid;

  public:
      state(std::vector<bool> const, bool, size, size,size,size);
      ~state();

      std::vector<bool>const& getGrid() const;
      bool getBase() const;
      size getBattery() const;
      size getPose() const;
      int getBaseDistance()const;
      // Return the matrix for a given state and action
      std::vector<double> getFeatures(int) ;

      /*!
      * \fn std::ostream& operator<<(std::ostream&, const state&)
      * \brief print the state
      * \param std::ostream&
      * \param const state& the state to be printed
      * \return std::ostream&
      *
      * This method should produce an output of this form:
      */
      friend std::ostream& operator<<(std::ostream& os, state const& s){
        os  << std::to_string(s.pose) << std::to_string(s.base) << std::to_string(s.battery);
        for(int i=0; i<s.grid.size(); ++i) os << std::to_string(s.grid[i]);
        return os;
      }
  };
}
