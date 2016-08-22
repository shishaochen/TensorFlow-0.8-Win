CC = g++

TENSORFLOW_DIR = ../../..

HEADERS = -I$(TENSORFLOW_DIR)
CFLAGS = -O2 -std=gnu++11

TARGET = libTensorflowCoreProtoBuf.a
OBJECTS = config.pb.o \
    master.pb.o \
    master_service.grpc.pb.o \
    master_service.pb.o \
    meta_graph.pb.o \
	named_tensor.pb.o \
	queue_runner.pb.o \
    saver.pb.o \
    tensorflow_server.pb.o \
    worker.pb.o \
	worker_service.grpc.pb.o \
    worker_service.pb.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar crv $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)