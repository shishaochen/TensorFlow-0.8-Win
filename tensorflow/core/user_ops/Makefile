CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(TENSORFLOW_DIR)/third_party/eigen-eigen-50812b426b7c

HEADERS = -I$(TENSORFLOW_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL

TARGET = libTensorflowCoreUserOps.a
OBJECTS = fact.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)