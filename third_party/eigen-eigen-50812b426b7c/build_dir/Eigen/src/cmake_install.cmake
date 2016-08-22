# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Cholesky/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/CholmodSupport/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Core/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Eigenvalues/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Geometry/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Householder/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/IterativeLinearSolvers/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Jacobi/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/LU/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/MetisSupport/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/misc/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/OrderingMethods/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/PardisoSupport/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/PaStiXSupport/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/plugins/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/QR/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/SparseCholesky/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/SparseCore/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/SparseLU/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/SparseQR/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/SPQRSupport/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/StlSupport/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/SuperLUSupport/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/SVD/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/UmfPackSupport/cmake_install.cmake")

endif()

