CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(gemmlowp)

INCLUDE_DIRECTORIES(../../posix
                    ../pthread-win32)
ADD_LIBRARY(gemmlowp STATIC eight_bit_int_gemm/eight_bit_int_gemm.cc)