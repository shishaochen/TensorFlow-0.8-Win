CC = g++

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c
RE2_DIR = $(THIRD_DIR)/re2

HEADERS = -I$(TENSORFLOW_DIR) -I$(RE2_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL

TARGET = libTensorflowCoreGraph.a
OBJECTS = algorithm.o \
    colors.o \
    costmodel.o \
    dot.o \
    edgeset.o \
    equal_graph_def.o \
    gradients.o \
    graph.o \
    graph_constructor.o \
    graph_def_builder.o \
    graph_partition.o \
    node_builder.o \
    optimizer_cse.o \
    subgraph.o \
    tensor_id.o \
    testlib.o \
    validate.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar crv $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)