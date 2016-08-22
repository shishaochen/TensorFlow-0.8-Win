CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
GTEST_INC = $(TENSORFLOW_DIR)/gmock/gtest/include
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c
GRPC_DIR = $(THIRD_DIR)/grpc
RE2_DIR = $(THIRD_DIR)/re2

CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
PUBLIC_HDRS = -I$(TENSORFLOW_DIR)

TARGET = libTensorflowCoreDistributedRuntime.a
RPC_OBJS = rpc/grpc_channel.o \
    rpc/grpc_master_service.o \
    rpc/grpc_remote_master.o \
    rpc/grpc_remote_worker.o \
    rpc/grpc_server_lib.o \
    rpc/grpc_session.o \
    rpc/grpc_testlib.o \
    rpc/grpc_testlib_ops.o \
    rpc/grpc_worker_cache.o \
    rpc/grpc_worker_service.o \
    rpc/rpc_rendezvous_mgr.o
OBJS = base_rendezvous_mgr.o \
    call_options.o \
    graph_mgr.o \
    master.o \
    master_session.o \
    remote_device.o \
    server_lib.o \
    worker_cache_logger.o \
    worker_cache_partial.o

all: $(TARGET)

$(TARGET): $(RPC_OBJS) $(OBJS)
	$(AR) $@ $^

RPC_HDRS = $(PUBLIC_HDRS) -I$(GRPC_DIR) -I$(GRPC_DIR)/include -I$(GTEST_INC) -I$(RE2_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
$(RPC_OBJS): %.o: %.cc
	$(CC) -o $@ $(RPC_HDRS) $(CFLAGS) -c $<

HDRS = $(PUBLIC_HDRS) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
$(OBJS): %.o: %.cc
	$(CC) -o $@ $(HDRS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	find . -name "*.o" | xargs rm -f
	rm -f $(TARGET)