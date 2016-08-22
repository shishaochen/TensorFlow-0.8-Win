CC = g++
LD = $(CC)

TENSORFLOW_DIR = ../../../..
GTEST_INC = $(TENSORFLOW_DIR)/gmock-1.7.0/gtest/include
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
GRPC_DIR = $(THIRD_DIR)/grpc
RE2_DIR = $(THIRD_DIR)/re2
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

HEADERS = -I$(TENSORFLOW_DIR) -I$(GRPC_DIR) -I$(GRPC_DIR)/include -I$(GTEST_INC) -I$(RE2_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11
LIBS = $(TENSORFLOW_DIR)/tensorflow/core/distributed_runtime/libTensorflowCoreDistributedRunTime.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
    $(TENSORFLOW_DIR)/tensorflow/core/protobuf/libTensorflowCoreProtoBuf.a \
    $(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
    $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf

SRV_BIN = grpc_tensorflow_server
TST_BIN = grpc_testlib_server

all: $(SRV_BIN) $(TST_BIN)

$(SRV_BIN): $(SRV_BIN).o $(DST_LIB)
	$(LD) -o $@ $^ $(LIBS)
	strip $@

$(TST_BIN): $(TST_BIN).o $(DST_LIB)
	$(LD) -o $@ $^ $(LIBS)
	strip $@

$(SRV_BIN).o: $(SRV_BIN).cc
	$(CC) -o $@ $(HEADERS) $(CFLAGS) -c $<

$(TST_BIN).o: $(TST_BIN).cc
	$(CC) -o $@ $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)