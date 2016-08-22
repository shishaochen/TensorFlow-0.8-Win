CC = g++

TENSORFLOW_DIR = ../../..

HEADERS = -I$(TENSORFLOW_DIR)
CFLAGS = -O2 -std=gnu++11

TARGET = libTensorflowCoreExample.a
OBJECTS = example.pb.o \
    feature.pb.o \
    feature.pb_text.o \
    feature_util.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar crv $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)