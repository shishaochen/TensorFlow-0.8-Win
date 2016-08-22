CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(TENSORFLOW_DIR)/third_party/eigen-eigen-50812b426b7c

CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
PUBLIC_HDRS = -I$(TENSORFLOW_DIR)

TARGET = libTensorflowCoreCommonRunTime.a
GPU_OBJS = gpu/cupti_wrapper.o \
    gpu/gpu_bfc_allocator.o \
    gpu/gpu_debug_allocator.o \
    gpu/gpu_device.o \
    gpu/gpu_device_factory.o \
    gpu/gpu_event_mgr.o \
    gpu/gpu_init.o \
    gpu/gpu_stream_util.o \
    gpu/gpu_tracer.o \
    gpu/gpu_util.o \
    gpu/gpu_util_platform_specific.o \
    gpu/pool_allocator.o \
    gpu/process_state.o
OBJS = allocator_retry.o \
    bfc_allocator.o \
    build_graph_options.o \
    constant_folding.o \
    copy_tensor.o \
    costmodel_manager.o \
    device.o \
    device_factory.o \
    device_mgr.o \
    device_set.o \
    direct_session.o \
    executor.o \
    function.o \
    graph_optimizer.o \
    kernel_benchmark_testlib.o \
    local_device.o \
    memory_types.o \
    process_util.o \
    rendezvous_mgr.o \
    session.o \
    session_factory.o \
    session_options.o \
    session_state.o \
    simple_graph_execution_state.o \
    simple_placer.o \
    step_stats_collector.o \
    threadpool_device.o \
    threadpool_device_factory.o

all: $(TARGET)

$(TARGET): $(GPU_OBJS) $(OBJS)
	$(AR) $@ $^

GPU_HDRS = $(PUBLIC_HDRS) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
$(GPU_OBJS): %.o: %.cc
	$(CC) -o $@ $(GPU_HDRS) $(CFLAGS) -c $<

HDRS = $(PUBLIC_HDRS) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
$(OBJS): %.o: %.cc
	$(CC) -o $@ $(HDRS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	find . -name "*.o" | xargs rm -f
	rm -f $(TARGET)