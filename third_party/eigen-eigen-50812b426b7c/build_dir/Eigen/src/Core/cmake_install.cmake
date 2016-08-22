# Install script for directory: D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/Core" TYPE FILE FILES
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Array.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/ArrayBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/ArrayWrapper.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Assign.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/AssignEvaluator.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Assign_MKL.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/BandMatrix.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Block.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/BooleanRedux.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/CommaInitializer.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/ConditionEstimator.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/CoreEvaluators.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/CoreIterators.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/CwiseBinaryOp.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/CwiseNullaryOp.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/CwiseUnaryOp.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/CwiseUnaryView.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/DenseBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/DenseCoeffsBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/DenseStorage.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Diagonal.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/DiagonalMatrix.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/DiagonalProduct.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Dot.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/EigenBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/ForceAlignedAccess.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Fuzzy.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/GeneralProduct.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/GenericPacketMath.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/GlobalFunctions.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Inverse.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/IO.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Map.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/MapBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/MathFunctions.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Matrix.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/MatrixBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/NestByValue.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/NoAlias.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/NumTraits.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/PermutationMatrix.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/PlainObjectBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Product.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/ProductEvaluators.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Random.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Redux.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Ref.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Replicate.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/ReturnByValue.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Reverse.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Select.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/SelfAdjointView.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/SelfCwiseBinaryOp.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Solve.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/SolverBase.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/SolveTriangular.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/SpecialFunctions.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/StableNorm.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Stride.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Swap.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Transpose.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Transpositions.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/TriangularMatrix.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/VectorBlock.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/VectorwiseOp.h"
    "D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/Eigen/src/Core/Visitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Core/products/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Core/util/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Core/arch/cmake_install.cmake")
  include("D:/tensorflow0.8/third_party/eigen-eigen-50812b426b7c/build_dir/Eigen/src/Core/functors/cmake_install.cmake")

endif()

