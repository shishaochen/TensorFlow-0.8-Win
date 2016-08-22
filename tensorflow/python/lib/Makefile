CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(TENSORFLOW_DIR)/third_party/eigen-eigen-50812b426b7c

PYTHON_INC = /usr/include/python2.7
NUMPY_INC = /usr/lib/python2.7/site-packages/numpy/core/include

CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
PUBLIC_HDRS = -I$(TENSORFLOW_DIR)

TARGET = libTensorflowPythonLib.a
CORE_OBJS = core/py_func.o \
    core/numpy.o
IO_OBJS = io/py_record_reader.o \
    io/py_record_writer.o

all: $(TARGET)

$(TARGET): $(CORE_OBJS) $(IO_OBJS)
	$(AR) $@ $^

CORE_HDRS = $(PUBLIC_HDRS) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11 -I$(PYTHON_INC) -I$(NUMPY_INC)
$(CORE_OBJS): %.o: %.cc
	$(CC) -o $@ $(CORE_HDRS) $(CFLAGS) -c $<

IO_HDRS = $(PUBLIC_HDRS)
$(IO_OBJS): %.o: %.cc
	$(CC) -o $@ $(IO_HDRS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	find . -name "*.o" | xargs rm -f
	rm -f $(TARGET)