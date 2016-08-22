# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/Core/util" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/BlasUtil.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/Constants.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/DisableStupidWarnings.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/ForwardDeclarations.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/Macros.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/Memory.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/Meta.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/MKL_support.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/NonMPL2.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/ReenableStupidWarnings.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/StaticAssert.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/util/XprHelper.h"
    )
endif()

