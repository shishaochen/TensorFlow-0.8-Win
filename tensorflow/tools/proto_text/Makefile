CC = g++

TENSORFLOW_DIR = ../../..

HEADERS = -I$(TENSORFLOW_DIR)
CFLAGS = -g -std=gnu++11
LIBS = $(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf

OBJECTS = gen_proto_text_functions_lib.o \
    gen_proto_text_functions.o

all: gen_proto_text_functions

gen_proto_text_functions: gen_proto_text_functions_lib.o gen_proto_text_functions.o
	$(CC) -o $@ $^ $(LIBS)

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o gen_proto_text_functions