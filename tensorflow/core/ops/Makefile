CC = g++

TENSORFLOW_DIR = ../../..
GTEST_DIR = $(TENSORFLOW_DIR)/gmock-1.7.0/gtest/include
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

HEADERS = -I$(TENSORFLOW_DIR) -I$(GTEST_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11

TARGET = libTensorflowCoreOps.a
OBJECTS = array_grad.o \
    array_ops.o \
    candidate_sampling_ops.o \
    control_flow_ops.o \
    ctc_ops.o \
    data_flow_ops.o \
    functional_grad.o \
    functional_ops.o \
    function_ops.o \
    image_ops.o \
    io_ops.o \
    linalg_ops.o \
    logging_ops.o \
    math_grad.o \
    math_ops.o \
    nn_grad.o \
    nn_ops.o \
    no_op.o \
    parsing_ops.o \
    random_grad.o \
    random_ops.o \
    script_ops.o \
    sendrecv_ops.o \
    sparse_ops.o \
    state_ops.o \
    string_ops.o \
    training_ops.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar crv $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf *.o $(TARGET)