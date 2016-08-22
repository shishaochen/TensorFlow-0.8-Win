CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
RE2_DIR = $(THIRD_DIR)/re2
GTEST_INC = $(TENSORFLOW_DIR)/gmock/gtest/include

CFLAGS = -O2 -std=gnu++11
PUBLIC_HDRS = -I$(TENSORFLOW_DIR)

TARGET = libTensorflowCorePlatform.a
DEFAULT_OBJS = default/logging.o \
    default/test_benchmark.o \
    default/tracing.o
POSIX_OBJS = posix/env.o \
    posix/posix_file_system.o \
    posix/port.o
OBJS = denormal.o \
    env.o \
	file_system.o \
    load_library.o \
    protobuf_util.o \
    tensor_coding.o \
    test.o \
    tracing.o

all: $(TARGET)

$(TARGET): $(DEFAULT_OBJS) $(POSIX_OBJS) $(OBJS)
	$(AR) $@ $^

DEFAULT_HDRS = $(PUBLIC_HDRS) -I$(RE2_DIR)
$(DEFAULT_OBJS): %.o: %.cc
	$(CC) -o $@ $(DEFAULT_HDRS) $(CFLAGS) -c $<

POSIX_HDRS = $(PUBLIC_HDRS)
$(POSIX_OBJS): %.o: %.cc
	$(CC) -o $@ $(POSIX_HDRS) $(CFLAGS) -c $<

HDRS = $(PUBLIC_HDRS) -I$(GTEST_INC)
$(OBJS): %.o: %.cc
	$(CC) -o $@ $(HDRS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	find . -name "*.o" | xargs rm -f
	rm -f $(TARGET)