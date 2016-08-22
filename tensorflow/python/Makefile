CC = g++
LD = $(CC)
SWIG = swig -c++ -python

TENSORFLOW_DIR = ../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

PYTHON_INC = /usr/include/python2.7
PYTHON_LIB = /lib/python2.7/config
NUMPY_INC = /usr/lib/python2.7/site-packages/numpy/core/include

HEADERS = -I$(TENSORFLOW_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11 -I$(PYTHON_INC) -I$(NUMPY_INC)
CFLAGS = -O2 -std=gnu++11 -fPIC -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
RIGSTERS = $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/direct_session.o \
    $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/threadpool_device_factory.o \
    $(TENSORFLOW_DIR)/tensorflow/core/distributed_runtime/rpc/grpc_session.o \
    $(TENSORFLOW_DIR)/tensorflow/core/distributed_runtime/rpc/grpc_server_lib.o
LIBS = $(TENSORFLOW_DIR)/tensorflow/python/client/libTensorflowPythonClient.a \
    $(TENSORFLOW_DIR)/tensorflow/python/framework/libTensorflowPythonFramework.a \
    $(TENSORFLOW_DIR)/tensorflow/python/lib/libTensorflowPythonLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/client/libTensorflowCoreClient.a \
    $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/libTensorflowCoreCommonRunTime.a \
    $(TENSORFLOW_DIR)/tensorflow/core/distributed_runtime/libTensorflowCoreDistributedRuntime.a \
    $(TENSORFLOW_DIR)/tensorflow/core/example/libTensorflowCoreExample.a \
    $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
	$(TENSORFLOW_DIR)/tensorflow/core/graph/libTensorflowCoreGraph.a \
	-Wl,--whole-archive $(TENSORFLOW_DIR)/tensorflow/core/kernels/libTensorflowCoreKernels.a \
	$(TENSORFLOW_DIR)/tensorflow/core/ops/libTensorflowCoreOps.a \
    $(TENSORFLOW_DIR)/tensorflow/core/user_ops/libTensorflowCoreUserOps.a \
    $(TENSORFLOW_DIR)/tensorflow/models/embedding/libTensorflowModelsEmbedding.a -Wl,--no-whole-archive \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
    $(TENSORFLOW_DIR)/tensorflow/core/protobuf/libTensorflowCoreProtoBuf.a \
    $(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
    $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/libTensorflowCoreCommonRunTime.a \
    $(TENSORFLOW_DIR)/tensorflow/stream_executor/libTensorflowStreamExecutor.a \
    $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf \
	-L$(THIRD_DIR)/grpc/libs/opt -lgrpc++ -lgrpc -lboringssl \
	-L$(THIRD_DIR)/jpeg_archive/jpeg-9a -ljpeg \
	-L$(THIRD_DIR)/png_archive/libpng-1.2.53 -lpng \
	-L$(THIRD_DIR)/re2/obj -lre2 \
	-L$(THIRD_DIR)/zlib -lz \
	-L$(PYTHON_LIB) -lpython2.7

SWIG_MODULE = pywrap_tensorflow
TARGET = _$(SWIG_MODULE).so

all: $(TARGET)

$(TARGET): $(SWIG_MODULE).o
	$(LD) -o $@ -shared $< $(RIGSTERS) $(LIBS)
	strip $@

$(SWIG_MODULE).o: $(SWIG_MODULE).cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

$(SWIG_MODULE).cc: tensorflow.i
	$(SWIG) -module $(SWIG_MODULE) -I$(TENSORFLOW_DIR) -o $@ $<

.PHONY: clean
clean:
	-rm -f $(SWIG_MODULE).cc $(SWIG_MODULE).py $(SWIG_MODULE).o $(TARGET)