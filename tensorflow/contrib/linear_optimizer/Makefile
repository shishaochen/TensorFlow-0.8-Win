CC = g++
AR = ar crv
LD = $(CC)

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

HEADERS = -I$(TENSORFLOW_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CXXFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
MAIN = $(TENSORFLOW_DIR)/tensorflow/python/framework/python_op_gen.o \
    $(TENSORFLOW_DIR)/tensorflow/python/framework/python_op_gen_main.o
LIBS = $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	$(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf -lm

LIB_OUT = python/ops/_sdca_ops.so
OPS_OUT = ops/gen_sdca_ops.py
BIN_OUT = gen_sdca_ops_py_wrappers_cc

OBJECTS = kernels/sdca_ops.o \
    kernels/resources.o \
	ops/sdca_ops.o

all: $(LIB_OUT) $(OPS_OUT)

$(LIB_OUT): $(OBJECTS)
	$(LD) -o $@ -shared $^ $(LIBS)

$(OPS_OUT): $(BIN_OUT)
	./$(BIN_OUT) 0 > $@

$(BIN_OUT): $(OBJECTS)
	$(CC) -o $@ $^ $(MAIN) $(LIBS)
	strip $@

$(OBJECTS): %.o: %.cc
	$(CC) -o $@ $(HEADERS) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(BIN_OUT) $(LIB_OUT) $(OPS_OUT)