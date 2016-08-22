# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/AdolcForward"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/AlignedVector3"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/ArpackSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/AutoDiff"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/BVH"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/FFT"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/IterativeSolvers"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/KroneckerProduct"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/LevenbergMarquardt"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/MatrixFunctions"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/MoreVectorization"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/MPRealSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/NonLinearOptimization"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/NumericalDiff"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/OpenGLSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/Polynomials"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/Skyline"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/SparseExtra"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/unsupported/Eigen/Splines"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/unsupported/Eigen/src/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()

