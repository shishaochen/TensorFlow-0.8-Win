# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/SparseCore" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/AmbiVector.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/CompressedStorage.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/ConservativeSparseSparseProduct.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/MappedSparseMatrix.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseAssign.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseBlock.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseColEtree.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseCompressedBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseCwiseBinaryOp.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseCwiseUnaryOp.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseDenseProduct.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseDiagonalProduct.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseDot.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseFuzzy.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseMap.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseMatrix.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseMatrixBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparsePermutation.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseProduct.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseRedux.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseRef.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseSelfAdjointView.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseSolverBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseSparseProductWithPruning.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseTranspose.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseTriangularView.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseUtil.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseVector.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/SparseView.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/SparseCore/TriangularSolver.h"
    )
endif()

