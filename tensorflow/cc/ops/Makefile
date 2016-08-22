CC = g++

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(TENSORFLOW_DIR)/third_party/eigen-eigen-50812b426b7c
GTEST_DIR = $(TENSORFLOW_DIR)/gmock-1.7.0/gtest/include

HEADERS = -I$(TENSORFLOW_DIR) -I$(GTEST_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
LIBS = $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
	$(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf -lm

TARGET = libTensorflowCcOps.a

OBJECTS = array_ops.o \
    candidate_sampling_ops.o \
    control_flow_ops.o \
	const_op.o \
    data_flow_ops.o \
    image_ops.o \
    io_ops.o \
    linalg_ops.o \
    logging_ops.o \
    math_ops.o \
    nn_ops.o \
    no_op.o \
    parsing_ops.o \
    random_ops.o \
    sendrecv_ops.o \
    sparse_ops.o \
    state_ops.o \
    string_ops.o \
    training_ops.o \
    user_ops.o

GEN_SRCS = array_ops.cc \
    candidate_sampling_ops.cc \
    control_flow_ops.cc \
    data_flow_ops.cc \
    image_ops.cc \
    io_ops.cc \
    linalg_ops.cc \
    logging_ops.cc \
    math_ops.cc \
    nn_ops.cc \
    no_op.cc \
    parsing_ops.cc \
    random_ops.cc \
    sendrecv_ops.cc \
    sparse_ops.cc \
    state_ops.cc \
    string_ops.cc \
    training_ops.cc \
    user_ops.cc

BIN_OBJS = cc_op_gen.o \
    cc_op_gen_main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	ar crv $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

array_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_array_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/array_ops.o $(LIBS)
	./gen_cc_op_array_ops array_ops.h $@ 0

candidate_sampling_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_candidate_sampling_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/candidate_sampling_ops.o $(LIBS)
	./gen_cc_op_candidate_sampling_ops candidate_sampling_ops.h $@ 0

control_flow_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_control_flow_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/control_flow_ops.o $(LIBS)
	./gen_cc_op_control_flow_ops control_flow_ops.h $@ 0

data_flow_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_data_flow_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/data_flow_ops.o $(LIBS)
	./gen_cc_op_data_flow_ops data_flow_ops.h $@ 0

image_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_image_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/image_ops.o $(LIBS)
	./gen_cc_op_image_ops image_ops.h $@ 0

io_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_io_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/io_ops.o $(LIBS)
	./gen_cc_op_io_ops io_ops.h $@ 0

linalg_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_linalg_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/linalg_ops.o $(LIBS)
	./gen_cc_op_linalg_ops linalg_ops.h $@ 0

logging_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_logging_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/logging_ops.o $(LIBS)
	./gen_cc_op_logging_ops logging_ops.h $@ 0

math_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_math_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/math_ops.o $(LIBS)
	./gen_cc_op_math_ops math_ops.h $@ 0

nn_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_nn_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/nn_ops.o $(LIBS)
	./gen_cc_op_nn_ops nn_ops.h $@ 0

no_op.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_no_op $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/no_op.o $(LIBS)
	./gen_cc_op_no_op no_op.h $@ 0

parsing_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_parsing_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/parsing_ops.o $(LIBS)
	./gen_cc_op_parsing_ops parsing_ops.h $@ 0

random_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_random_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/random_ops.o $(LIBS)
	./gen_cc_op_random_ops random_ops.h $@ 0

sendrecv_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_sendrecv_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/sendrecv_ops.o $(LIBS)
	./gen_cc_op_sendrecv_ops sendrecv_ops.h $@ 1

sparse_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_sparse_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/sparse_ops.o $(LIBS)
	./gen_cc_op_sparse_ops sparse_ops.h $@ 0

state_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_state_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/state_ops.o $(LIBS)
	./gen_cc_op_state_ops state_ops.h $@ 0

string_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_string_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/string_ops.o $(LIBS)
	./gen_cc_op_string_ops string_ops.h $@ 0

training_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_training_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/ops/training_ops.o $(LIBS)
	./gen_cc_op_training_ops training_ops.h $@ 0

user_ops.cc: $(BIN_OBJS)
	$(CC) -o gen_cc_op_user_ops $^ $(TENSORFLOW_DIR)/tensorflow/core/user_ops/fact.o $(LIBS)
	./gen_cc_op_user_ops user_ops.h $@ 0

$(BIN_OBJS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

.PHONY : clean
clean:
	rm -rf $(GEN_SRCS) *.o *.exe $(TARGET)