CC = g++
AR = ar crv

TENSORFLOW_DIR = ../../..
THIRD_DIR = $(TENSORFLOW_DIR)/third_party
EIGEN_DIR = $(THIRD_DIR)/eigen-eigen-50812b426b7c

CCOPS_DIR = $(TENSORFLOW_DIR)/tensorflow/core/ops
USEROPS_DIR = $(TENSORFLOW_DIR)/tensorflow/core/user_ops
PYOPS_DIR = ../ops
TRAINING_DIR = ../training

HEADERS = -I$(TENSORFLOW_DIR) -I$(THIRD_DIR) -I$(EIGEN_DIR) -I$(EIGEN_DIR)/Eigen -I$(EIGEN_DIR)/unsupported/Eigen/CX11
CXXFLAGS = -O2 -std=gnu++11 -DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL
LIBS = $(TENSORFLOW_DIR)/tensorflow/core/framework/libTensorflowCoreFramework.a \
    $(TENSORFLOW_DIR)/tensorflow/core/platform/libTensorflowCorePlatform.a \
	$(TENSORFLOW_DIR)/tensorflow/core/lib/libTensorflowCoreLib.a \
	$(TENSORFLOW_DIR)/tensorflow/core/util/libTensorflowCoreUtil.a \
	-L$(TENSORFLOW_DIR)/google/protobuf -lprotobuf -lm

LIB_OUT = libTensorflowPythonFramework.a
OPS_OUT = $(PYOPS_DIR)/gen_array_ops.py \
    $(PYOPS_DIR)/gen_candidate_sampling_ops.py \
    $(PYOPS_DIR)/gen_control_flow_ops.py \
    $(PYOPS_DIR)/gen_ctc_ops.py \
    $(PYOPS_DIR)/gen_data_flow_ops.py \
    $(PYOPS_DIR)/gen_functional_ops.py \
    $(PYOPS_DIR)/gen_image_ops.py \
    $(PYOPS_DIR)/gen_io_ops.py \
    $(PYOPS_DIR)/gen_linalg_ops.py \
    $(PYOPS_DIR)/gen_logging_ops.py \
    $(PYOPS_DIR)/gen_math_ops.py \
    $(PYOPS_DIR)/gen_nn_ops.py \
    $(PYOPS_DIR)/gen_parsing_ops.py \
    $(PYOPS_DIR)/gen_random_ops.py \
    $(PYOPS_DIR)/gen_script_ops.py \
    $(PYOPS_DIR)/gen_sparse_ops.py \
    $(PYOPS_DIR)/gen_state_ops.py \
    $(PYOPS_DIR)/gen_string_ops.py \
    $(TRAINING_DIR)/gen_training_ops.py \
	$(PYOPS_DIR)/gen_user_ops.py

OBJECTS = python_op_gen.o \
    python_op_gen_main.o

TARGET = $(LIB_OUT) $(OPS_OUT)

all: $(TARGET)

$(LIB_OUT): $(OBJECTS)
	$(AR) $@ $^

$(OBJECTS): %.o: %.cc
	$(CC) $(HEADERS) $(CXXFLAGS) -c $<

$(PYOPS_DIR)/gen_array_ops.py: $(OBJECTS)
	$(CC) -o gen_array_ops_py_wrappers_cc $^ $(CCOPS_DIR)/array_ops.o $(LIBS)
	./gen_array_ops_py_wrappers_cc BroadcastGradientArgs,ConcatOffset,Concat,Const,EditDistance,MirrorPad,MirrorPadGrad,OneHot,Pack,Pad,Placeholder,RefIdentity,Split,Slice,TileGrad,ZerosLike,Unpack 1 > $@

$(PYOPS_DIR)/gen_candidate_sampling_ops.py: $(OBJECTS)
	$(CC) -o gen_candidate_sampling_ops_py_wrappers_cc $^ $(CCOPS_DIR)/candidate_sampling_ops.o $(LIBS)
	./gen_candidate_sampling_ops_py_wrappers_cc AllCandidateSampler,ComputeAccidentalHits,FixedUnigramCandidateSampler,LearnedUnigramCandidateSampler,LogUniformCandidateSampler,ThreadUnsafeUnigramCandidateSampler,UniformCandidateSampler 1 > $@

$(PYOPS_DIR)/gen_control_flow_ops.py: $(OBJECTS)
	$(CC) -o gen_control_flow_ops_py_wrappers_cc $^ $(CCOPS_DIR)/control_flow_ops.o $(CCOPS_DIR)/no_op.o $(LIBS)
	./gen_control_flow_ops_py_wrappers_cc Switch,Merge,RefMerge,Exit,RefExit 1 > $@

$(PYOPS_DIR)/gen_ctc_ops.py: $(OBJECTS)
	$(CC) -o gen_ctc_ops_py_wrappers_cc $^ $(CCOPS_DIR)/ctc_ops.o $(LIBS)
	./gen_ctc_ops_py_wrappers_cc CTCLoss,CTCGreedyDecoder,CTCBeamSearchDecoder 1 > $@

$(PYOPS_DIR)/gen_data_flow_ops.py: $(OBJECTS)
	$(CC) -o gen_data_flow_ops_py_wrappers_cc $^ $(CCOPS_DIR)/data_flow_ops.o $(LIBS)
	./gen_data_flow_ops_py_wrappers_cc FIFOQueue,HashTable,InitializeTable,LookupTableFind,LookupTableSize,Mutex,MutexAcquire,MutexRelease,PaddingFIFOQueue,QueueClose,QueueDequeue,QueueDequeueMany,QueueDequeueUpTo,QueueEnqueue,QueueEnqueueMany,QueueSize,RandomShuffleQueue,Stack,StackPop,StackPush,StackClose,TensorArray,TensorArrayClose,TensorArrayConcat,TensorArrayGrad,TensorArrayRead,TensorArrayPack,TensorArraySize,TensorArraySplit,TensorArrayUnpack,TensorArrayWrite,GetSessionHandle,GetSessionTensor,DeleteSessionTensor 1 > $@

$(PYOPS_DIR)/gen_functional_ops.py: $(OBJECTS)
	$(CC) -o gen_functional_ops_py_wrappers_cc $^ $(CCOPS_DIR)/functional_ops.o $(LIBS)
	./gen_functional_ops_py_wrappers_cc SymbolicGradient 0 > $@

$(PYOPS_DIR)/gen_image_ops.py: $(OBJECTS)
	$(CC) -o gen_image_ops_py_wrappers_cc $^ $(CCOPS_DIR)/image_ops.o $(LIBS)
	./gen_image_ops_py_wrappers_cc RandomCrop,ResizeBilinearGrad,ResizeNearestNeighborGrad,AdjustContrastv2,ScaleImageGrad 1 > $@

$(PYOPS_DIR)/gen_io_ops.py: $(OBJECTS)
	$(CC) -o gen_io_ops_py_wrappers_cc $^ $(CCOPS_DIR)/io_ops.o $(LIBS)
	./gen_io_ops_py_wrappers_cc FixedLengthRecordReader,IdentityReader,ReaderClose,ReaderEnqueueWork,ReaderNumRecordsProduced,ReaderNumWorkUnitsCompleted,ReaderRead,ReaderReset,ReaderRestoreState,ReaderSerializeState,ReaderWorkQueueLength,Restore,RestoreSlice,Save,SaveSlices,ShardedFilename,ShardedFilespec,TextLineReader,TFRecordReader,WholeFileReader 1 > $@

$(PYOPS_DIR)/gen_linalg_ops.py: $(OBJECTS)
	$(CC) -o gen_linalg_ops_py_wrappers_cc $^ $(CCOPS_DIR)/linalg_ops.o $(LIBS)
	./gen_linalg_ops_py_wrappers_cc 1 > $@

$(PYOPS_DIR)/gen_logging_ops.py: $(OBJECTS)
	$(CC) -o gen_logging_ops_py_wrappers_cc $^ $(CCOPS_DIR)/logging_ops.o $(LIBS)
	./gen_logging_ops_py_wrappers_cc Assert,AudioSummary,HistogramAccumulatorSummary,HistogramSummary,ImageSummary,MergeSummary,Print,ScalarSummary 1 > $@

$(PYOPS_DIR)/gen_math_ops.py: $(OBJECTS)
	$(CC) -o gen_math_ops_py_wrappers_cc $^ $(CCOPS_DIR)/math_ops.o $(LIBS)
	./gen_math_ops_py_wrappers_cc Abs,All,Any,BatchMatMul,Complex,Max,Mean,Min,Pow,Prod,Range,SparseMatMul,Sum,MatMul,Sigmoid,Tanh 1 > $@

$(PYOPS_DIR)/gen_nn_ops.py: $(OBJECTS)
	$(CC) -o gen_nn_ops_py_wrappers_cc $^ $(CCOPS_DIR)/nn_ops.o $(LIBS)
	./gen_nn_ops_py_wrappers_cc AvgPoolGrad,BatchNormWithGlobalNormalization,BatchNormWithGlobalNormalizationGrad,SoftmaxCrossEntropyWithLogits,SparseSoftmaxCrossEntropyWithLogits,LRNGrad,MaxPoolGrad,MaxPoolGradWithArgmax,ReluGrad,Relu6Grad,EluGrad,SoftplusGrad,SoftsignGrad,TopK,TopKV2,BiasAdd,BiasAddV1,Relu6,AvgPool,MaxPool 1 > $@

$(PYOPS_DIR)/gen_parsing_ops.py: $(OBJECTS)
	$(CC) -o gen_parsing_ops_py_wrappers_cc $^ $(CCOPS_DIR)/parsing_ops.o $(LIBS)
	./gen_parsing_ops_py_wrappers_cc ParseExample,ParseSingleSequenceExample 1 > $@

$(PYOPS_DIR)/gen_random_ops.py: $(OBJECTS)
	$(CC) -o gen_random_ops_py_wrappers_cc $^ $(CCOPS_DIR)/random_ops.o $(LIBS)
	./gen_random_ops_py_wrappers_cc RandomUniform,RandomUniformInt,RandomShuffle,RandomStandardNormal,TruncatedNormal 1 > $@

$(PYOPS_DIR)/gen_script_ops.py: $(OBJECTS)
	$(CC) -o gen_script_ops_py_wrappers_cc $^ $(CCOPS_DIR)/script_ops.o $(LIBS)
	./gen_script_ops_py_wrappers_cc PyFunc 1 > $@

$(PYOPS_DIR)/gen_sparse_ops.py: $(OBJECTS)
	$(CC) -o gen_sparse_ops_py_wrappers_cc $^ $(CCOPS_DIR)/sparse_ops.o $(LIBS)
	./gen_sparse_ops_py_wrappers_cc DeserializeManySparse,SerializeManySparse,SerializeSparse,SparseAdd,SparseAddGrad,SparseConcat,SparseSplit,SparseSelectLastK,SparseReorder,SparseToDense,SparseTensorDenseAdd,SparseTensorDenseMatMul 1 > $@

$(PYOPS_DIR)/gen_state_ops.py: $(OBJECTS)
	$(CC) -o gen_state_ops_py_wrappers_cc $^ $(CCOPS_DIR)/state_ops.o $(LIBS)
	./gen_state_ops_py_wrappers_cc Variable,TemporaryVariable,DestroyTemporaryVariable 1 > $@

$(PYOPS_DIR)/gen_string_ops.py: $(OBJECTS)
	$(CC) -o gen_string_ops_py_wrappers_cc $^ $(CCOPS_DIR)/string_ops.o $(LIBS)
	./gen_string_ops_py_wrappers_cc 1 > $@

$(TRAINING_DIR)/gen_training_ops.py: $(OBJECTS)
	$(CC) -o gen_training_ops_py_wrappers_cc $^ $(CCOPS_DIR)/training_ops.o $(LIBS)
	./gen_training_ops_py_wrappers_cc 1 > $@

$(PYOPS_DIR)/gen_user_ops.py: $(OBJECTS)
	$(CC) -o gen_user_ops_py_wrappers_cc $^ $(USEROPS_DIR)/fact.o $(LIBS)
	./gen_user_ops_py_wrappers_cc Fact 0 > $@

.PHONY : clean
clean:
	rm -rf *.exe *.o $(TARGET)