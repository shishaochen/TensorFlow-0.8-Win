# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Cholesky"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/CholmodSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Core"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Dense"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Eigen"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Eigenvalues"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Geometry"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Householder"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/IterativeLinearSolvers"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Jacobi"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/LU"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/MetisSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/OrderingMethods"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/PardisoSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/PaStiXSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/QR"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/QtAlignedMalloc"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/Sparse"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/SparseCholesky"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/SparseCore"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/SparseLU"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/SparseQR"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/SPQRSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/StdDeque"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/StdList"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/StdVector"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/SuperLUSupport"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/SVD"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/UmfPackSupport"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/cmake_install.cmake")

endif()

