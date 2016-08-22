CC = g++
LD = $(CC)

TENSORFLOW_DIR = ../../..
GTEST_DIR = $(TENSORFLOW_DIR)/gmock-1.7.0/gtest/include
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(TENSORFLOW_DIR)/third_party/eigen-eigen-50812b426b7c

HEADERS = -I$(TENSORFLOW_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11
RIGSTERS = $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/direct_session.o \
    $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/threadpool_device_factory.o
LIBS = $(TENSORFLOW_DIR)/tensorflow/cc/ops/libTensorflowCcOps.a \
    $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/libTensorflowCoreCommonRunTime.a \
    $(TENSORFLOW_DIR)/tensorflow/core/example/libTensorflowCoreExample.a \
    $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
	$(TENSORFLOW_DIR)/tensorflow/core/graph/libTensorflowCoreGraph.a \
	-Wl,--whole-archive $(TENSORFLOW_DIR)/tensorflow/core/kernels/libTensorflowCoreKernels.a \
	$(TENSORFLOW_DIR)/tensorflow/core/ops/libTensorflowCoreOps.a \
    $(TENSORFLOW_DIR)/tensorflow/core/user_ops/libTensorflowCoreUserOps.a -Wl,--no-whole-archive \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
    $(TENSORFLOW_DIR)/tensorflow/core/protobuf/libTensorflowCoreProtoBuf.a \
    $(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
    $(TENSORFLOW_DIR)/tensorflow/core/common_runtime/libTensorflowCoreCommonRunTime.a \
    $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf \
	-L$(THIRD_DIR)/jpeg_archive/jpeg-9a -ljpeg \
	-L$(THIRD_DIR)/png_archive/libpng-1.2.53 -lpng \
	-L$(THIRD_DIR)/zlib -lz

TARGET = main
OBJECTS = main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(RIGSTERS) $(LIBS)
	strip $@

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)