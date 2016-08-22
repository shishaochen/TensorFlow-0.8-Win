CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c
JPEG_DIR = $(THIRD_DIR)/jpeg_archive
PNG_DIR = $(THIRD_DIR)/png_archive

CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
PUBLIC_HDRS = -I$(TENSORFLOW_DIR)

TARGET = libTensorflowCoreLib.a
CORE_OBJS = core/arena.o \
    core/coding.o \
    core/error_codes.pb.o \
    core/status.o \
    core/stringpiece.o \
    core/threadpool.o
HASH_OBJS = hash/crc32c.o \
    hash/hash.o
HISTOGRAM_OBJS = histogram/histogram.o
IO_OBJS = io/block.o \
    io/block_builder.o \
    io/format.o \
    io/inputbuffer.o \
    io/iterator.o \
    io/match.o \
    io/path.o \
    io/record_reader.o \
    io/record_writer.o \
    io/table.o \
    io/table_builder.o \
    io/two_level_iterator.o
JPEG_OBJS = jpeg/jpeg_handle.o \
    jpeg/jpeg_mem.o
PNG_OBJS = png/png_io.o
RANDOM_OBJS = random/distribution_sampler.o \
    random/random.o \
    random/simple_philox.o \
    random/weighted_picker.o
STRINGS_OBJS = strings/numbers.o \
    strings/ordered_code.o \
    strings/proto_text_util.o \
    strings/scanner.o \
    strings/strcat.o \
    strings/stringprintf.o \
    strings/str_util.o
WAV_OBJS = wav/wav_io.o

all: $(TARGET)

$(TARGET): $(CORE_OBJS) $(HASH_OBJS) $(HISTOGRAM_OBJS) $(IO_OBJS) $(JPEG_OBJS) $(PNG_OBJS) $(RANDOM_OBJS) $(STRINGS_OBJS) $(WAV_OBJS)
	$(AR) $@ $^

CORE_HDRS = $(PUBLIC_HDRS) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
$(CORE_OBJS): %.o: %.cc
	$(CC) -o $@ $(CORE_HDRS) $(CFLAGS) -c $<

HASH_HDRS = $(PUBLIC_HDRS)
$(HASH_OBJS): %.o: %.cc
	$(CC) -o $@ $(HASH_HDRS) $(CFLAGS) -c $<

HISTOGRAM_HDRS = $(PUBLIC_HDRS)
$(HISTOGRAM_OBJS): %.o: %.cc
	$(CC) -o $@ $(HISTOGRAM_HDRS) $(CFLAGS) -c $<

IO_HDRS = $(PUBLIC_HDRS)
$(IO_OBJS): %.o: %.cc
	$(CC) -o $@ $(IO_HDRS) $(CFLAGS) -c $<

JPEG_HDRS = $(PUBLIC_HDRS) -I$(JPEG_DIR)
$(JPEG_OBJS): %.o: %.cc
	$(CC) -o $@ $(JPEG_HDRS) $(CFLAGS) -c $<

PNG_HDRS = $(PUBLIC_HDRS) -I$(PNG_DIR)
$(PNG_OBJS): %.o: %.cc
	$(CC) -o $@ $(PNG_HDRS) $(CFLAGS) -c $<

RANDOM_HDRS = $(PUBLIC_HDRS) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
$(RANDOM_OBJS): %.o: %.cc
	$(CC) -o $@ $(RANDOM_HDRS) $(CFLAGS) -c $<

STRINGS_HDRS = $(PUBLIC_HDRS)
$(STRINGS_OBJS): %.o: %.cc
	$(CC) -o $@ $(STRINGS_HDRS) $(CFLAGS) -c $<

WAV_HDRS = $(PUBLIC_HDRS)
$(WAV_OBJS): %.o: %.cc
	$(CC) -o $@ $(WAV_HDRS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	find . -name "*.o" | xargs rm -f
	rm -f $(TARGET)