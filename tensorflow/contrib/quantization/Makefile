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
	$(TENSORFLOW_DIR)/tensorflow/core/kernels/libTensorflowCoreKernels.a \
	$(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	$(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
	$(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf

LIB_OUT = _quantized_ops.so
OPS_OUT = ops/gen_array_ops.py \
    ops/gen_math_ops.py \
	ops/gen_nn_ops.py

KNL_OBJS = kernels/dequantize_op.o \
    kernels/quantized_activation_ops.o \
    kernels/quantized_batch_norm_op.o \
    kernels/quantized_bias_add_op.o \
    kernels/quantized_concat_op.o \
    kernels/quantized_conv_ops.o \
    kernels/quantized_matmul_op.o \
    kernels/quantized_pooling_ops.o \
    kernels/quantize_down_and_shrink_range.o \
    kernels/quantize_op.o
OPS_OBJS = ops/array_ops.o \
    ops/math_ops.o \
    ops/nn_ops.o

all: $(OPS_OUT) $(LIB_OUT)

$(LIB_OUT): $(KNL_OBJS)
	$(LD) -o $@ -shared $^ $(LIBS)

$(KNL_OBJS): %.o: %.cc
	$(CC) -o $@ $(HEADERS) $(CXXFLAGS) -c $<

ops/gen_array_ops.py: $(OPS_OBJS)
	$(CC) -o gen_array_ops_py_wrappers_cc ops/array_ops.o $(MAIN) $(LIBS)
	./gen_array_ops_py_wrappers_cc 0 > $@

ops/gen_math_ops.py: $(OPS_OBJS)
	$(CC) -o gen_math_ops_py_wrappers_cc ops/math_ops.o $(MAIN) $(LIBS)
	./gen_math_ops_py_wrappers_cc 0 > $@

ops/gen_nn_ops.py: $(OPS_OBJS)
	$(CC) -o gen_nn_ops_py_wrappers_cc ops/nn_ops.o $(MAIN) $(LIBS)
	./gen_nn_ops_py_wrappers_cc 0 > $@

$(OPS_OBJS): %.o: %.cc
	$(CC) -o $@ $(HEADERS) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf $(OPS_OBJS) $(KNL_OBJS) $(OPS_OUT) $(LIB_OUT) *.exe