CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

HEADERS = -I$(TENSORFLOW_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
LIBS = -Wl,--whole-archive $(TENSORFLOW_DIR)/tensorflow/python/framework/libTensorflowPythonFramework.a -Wl,--no-whole-archive \
    $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
	$(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf -lm

LIB_OUT = libTensorflowModelsEmbedding.a
BIN_OUT = gen_word2vec_py_wrappers_cc
PY_OUT = gen_word2vec.py

OBJECTS = word2vec_kernels.o \
    word2vec_ops.o

BIN_OBJS = cc_op_gen.o \
    cc_op_gen_main.o

all: $(LIB_OUT) $(PY_OUT)

$(LIB_OUT): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CFLAGS) -c $<

$(PY_OUT): $(BIN_OUT)
	./$(BIN_OUT) 0 > $@

$(BIN_OUT): word2vec_ops.o
	$(CC) -o $(BIN_OUT) $^ $(LIBS)

.PHONY : clean
clean:
	rm -rf *.o *.exe $(LIB_OUT)