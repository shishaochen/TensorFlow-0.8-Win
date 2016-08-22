CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
PUBLIC_HDRS = -I$(TENSORFLOW_DIR)

TARGET = libTensorflowCoreUtil.a
CTC_OBJS = ctc/ctc_loss_calculator.o
SPARSE_OBJS = sparse/group_iterator.o
OBJS = bcast.o \
    checkpoint_reader.o \
    command_line_flags.o \
    device_name_utils.o \
    event.pb.o \
    events_writer.o \
    example_proto_helper.o \
    guarded_philox_random.o \
    memmapped_file_system.o \
    memmapped_file_system.pb.o \
    memmapped_file_system_writer.o \
    mirror_pad_mode.o \
    padding.o \
    port.o \
    reporter.o \
    saved_tensor_slice.pb.o \
    saved_tensor_slice.pb_text.o \
    saved_tensor_slice_util.o \
    stat_summarizer.o \
    tensor_format.o \
    tensor_slice_reader.o \
    tensor_slice_reader_cache.o \
    tensor_slice_set.o \
    tensor_slice_writer.o \
    test_log.pb.o \
    tf_status_helper.o \
    use_cudnn.o \
    util.o \
    work_sharder.o
OBJECTS = $(CTC_OBJS) $(SPARSE_OBJS) $(OBJS)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $@ $^

HEADERS = $(PUBLIC_HDRS) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
$(OBJECTS): %.o: %.cc
	$(CC) -o $@ $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	find . -name "*.o" | xargs rm -f
	rm -f $(TARGET)