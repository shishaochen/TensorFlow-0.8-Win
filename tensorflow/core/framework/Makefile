CC = g++

TENSORFLOW_DIR = ../../..
GTEST_DIR = $(TENSORFLOW_DIR)/gmock/gtest/include
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

HEADERS = -I$(TENSORFLOW_DIR) -I$(GTEST_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL

TARGET = libTensorflowCoreFramework.a
OBJECTS = allocation_description.pb.o \
    allocation_description.pb_text.o \
    allocator.o \
    attr_value.pb.o \
    attr_value.pb_text.o \
    attr_value_util.o \
    bfloat16.o \
    cancellation.o \
	cost_graph.pb.o \
    device_attributes.pb.o \
    device_attributes.pb_text.o \
    device_base.o \
    fake_input.o \
    function.o \
    function.pb.o \
    function.pb_text.o \
    function_testlib.o \
    graph.pb.o \
	graph.pb_text.o \
    graph_def_util.o \
    kernel_def.pb.o \
    kernel_def.pb_text.o \
    kernel_def_builder.o \
    load_library.o \
    log_memory.o \
    log_memory.pb.o \
    log_memory.pb_text.o \
    lookup_interface.o \
    memory_types.o \
    node_def_builder.o \
    node_def_util.o \
    op.o \
    op_def.pb.o \
    op_def.pb_text.o \
    op_def_builder.o \
    op_def_util.o \
    op_gen_lib.o \
    op_kernel.o \
    op_segment.o \
    partial_tensor_shape.o \
    reader_op_kernel.o \
    rendezvous.o \
    resource_mgr.o \
    step_stats.pb.o \
    summary.pb.o \
    tensor.o \
    tensor.pb.o \
    tensor.pb_text.o \
    tensor_description.pb.o \
    tensor_description.pb_text.o \
    tensor_reference.o \
    tensor_shape.o \
    tensor_shape.pb.o \
    tensor_shape.pb_text.o \
    tensor_slice.o \
    tensor_slice.pb.o \
	tensor_slice.pb_text.o \
    tensor_testutil.o \
    tensor_util.o \
    tracking_allocator.o \
    types.o \
    types.pb.o \
    types.pb_text.o \
    unique_tensor_references.o \
    variable.pb.o \
    versions.o \
    versions.pb.o \
    versions.pb_text.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar crv $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)