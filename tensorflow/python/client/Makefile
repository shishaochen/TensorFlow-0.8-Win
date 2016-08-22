CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

PYTHON_INC = /usr/include/python2.7
NUMPY_INC = /usr/lib/python2.7/site-packages/numpy/core/include

HEADERS = -I$(TENSORFLOW_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11 -I$(PYTHON_INC) -I$(NUMPY_INC)
CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL

TARGET = libTensorflowPythonClient.a
OBJECTS = test_construction_fails_op.o \
    tf_session_helper.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)