CC = g++
LD = $(CC)

TENSORFLOW_DIR = ../../../..

HEADERS = -I$(TENSORFLOW_DIR)
CFLAGS = -O2 -std=gnu++11
LIBS = $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
	 -L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf

OBJECTS = op_compatibility_lib.o \
    update_ops_main.o
TARGET = update_ops

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LIBS)
	strip $@

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)