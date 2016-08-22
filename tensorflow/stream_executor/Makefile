CXX = g++
AR = ar crv

TENSORFLOW_DIR = ../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party

CXXFLAGS = -O2 -std=gnu++11
PUBLIC_HDRS = -I$(TENSORFLOW_DIR)

TARGET = libTensorflowStreamExecutor.a
CUDA_OBJS =  cuda/cuda_activation.o \
    cuda/cuda_blas.o \
    cuda/cuda_diagnostics.o \
    cuda/cuda_dnn.o \
    cuda/cuda_driver.o \
    cuda/cuda_event.o \
    cuda/cuda_fft.o \
    cuda/cuda_gpu_executor.o \
    cuda/cuda_platform.o \
    cuda/cuda_platform_id.o \
    cuda/cuda_rng.o \
    cuda/cuda_stream.o \
    cuda/cuda_timer.o
LIB_OBJS = lib/demangle.o \
    lib/numbers.o \
    lib/path.o \
    lib/process_state.o
OBJS = blas.o \
    device_description.o \
    dnn.o \
    dso_loader.o \
    event.o \
    executor_cache.o \
    gcuda.o \
    kernel.o \
    kernel_spec.o \
    machine_manager.o \
    multi_platform_manager.o \
    platform.o \
    plugin.o \
    plugin_registry.o \
    rng.o \
    scratch_allocator.o \
    stream.o \
    stream_executor_internal.o \
    stream_executor_pimpl.o \
    temporary_device_memory.o \
    temporary_memory_manager.o \
    timer.o

all: $(TARGET)

$(TARGET): $(LIB_OBJS) $(OBJS)
	$(AR) $@ $^

CUDA_HDRS = $(PUBLIC_HDRS)
$(CUDA_OBJS): %.o: %.cc
	$(CXX) -o $@ $(CUDA_HDRS) $(CXXFLAGS) -c $<

LIB_HDRS = $(PUBLIC_HDRS)
$(LIB_OBJS): %.o: %.cc
	$(CXX) -o $@ $(LIB_HDRS) $(CXXFLAGS) -c $<

HDRS = $(PUBLIC_HDRS)
$(OBJS): %.o: %.cc
	$(CXX) -o $@ $(HDRS) $(CXXFLAGS) -c $<

.PHONY : clean
clean:
	find . -name "*.o" | xargs rm -f
	rm -f $(TARGET)