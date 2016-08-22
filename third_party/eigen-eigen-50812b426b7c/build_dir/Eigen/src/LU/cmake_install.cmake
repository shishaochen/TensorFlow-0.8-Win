# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/LU

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/LU" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/LU/Determinant.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/LU/FullPivLU.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/LU/InverseImpl.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/LU/PartialPivLU.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/LU/PartialPivLU_MKL.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/LU/arch/cmake_install.cmake")

endif()

