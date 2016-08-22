# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Eigen")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen/src/NonLinearOptimization" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/chkder.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/covar.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/dogleg.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/fdjac1.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/HybridNonLinearSolver.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/LevenbergMarquardt.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/lmpar.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/qrsolv.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/r1mpyq.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/r1updt.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/src/NonLinearOptimization/rwupdt.h"
    )
endif()
