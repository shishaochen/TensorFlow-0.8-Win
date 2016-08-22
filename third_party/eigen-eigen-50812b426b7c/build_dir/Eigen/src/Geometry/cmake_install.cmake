# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/Geometry" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/AlignedBox.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/AngleAxis.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/EulerAngles.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Homogeneous.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Hyperplane.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/OrthoMethods.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/ParametrizedLine.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Quaternion.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Rotation2D.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/RotationBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Scaling.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Transform.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Translation.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Geometry/Umeyama.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Geometry/arch/cmake_install.cmake")

endif()

