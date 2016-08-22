project(tensorflow)
cmake_minimum_required(VERSION 2.6.2)

if(NOT PYTHON_DIR)
  set(PYTHON_DIR D:/Python35)
endif()

include_directories(./
                    ./gmock/include
					./gmock/gtest/include
                    ./google/protobuf/src
                    ./posix
					./third_party
					./third_party/eigen-eigen-50812b426b7c
					./third_party/grpc
					./third_party/grpc/include
					./third_party/pthread-win32
					./third_party/re2
					./third_party/zlib
					${PYTHON_DIR}/include
					${PYTHON_DIR}/Lib/site-packages/numpy/core/include)

cmake_policy(SET CMP0015 NEW)
link_directories(./gmock/gtest/msvc/x64/Release
                 ./gmock/msvc/2010/x64/Release
                 ./google/protobuf/cmake/Release
                 ./third_party/grpc/vsprojects/x64/Release
                 ./third_party/jpeg-9a/build
                 ./third_party/libpng-1.2.53/build
                 ./third_party/openssl-1.0.2h/out32
                 ./third_party/pthread-win32
                 ./third_party/re2/release
                 ./third_party/zlib/build
				 ${PYTHON_DIR}/libs)

foreach(flag_var CMAKE_C_FLAGS CMAKE_CXX_FLAGS
                 CMAKE_C_FLAGS_DEBUG CMAKE_CXX_FLAGS_DEBUG
				 CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE
                 CMAKE_C_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_MINSIZEREL
				 CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO)
   if(${flag_var} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
   endif(${flag_var} MATCHES "/MD")
endforeach(flag_var)

add_definitions(-DEIGEN_AVOID_STL_ARRAY -DTENSORFLOW_USE_EIGEN_THREADPOOL)

set(POSIX_SRC ./posix/dlfcn.c
              ./posix/getopt.c
              ./posix/strings.c
              ./posix/sys/mman.c
              ./posix/sys/time.cc)
add_library(posix STATIC ${POSIX_SRC})

set(TENSORFLOW_CORE_LIB_SRC ./tensorflow/core/lib/core/arena.cc
                            ./tensorflow/core/lib/core/coding.cc
                            ./tensorflow/core/lib/core/error_codes.pb.cc
                            ./tensorflow/core/lib/core/status.cc
                            ./tensorflow/core/lib/core/stringpiece.cc
                            ./tensorflow/core/lib/core/threadpool.cc
                            ./tensorflow/core/lib/hash/crc32c.cc
                            ./tensorflow/core/lib/hash/hash.cc
                            ./tensorflow/core/lib/histogram/histogram.cc
                            ./tensorflow/core/lib/io/block.cc
                            ./tensorflow/core/lib/io/block_builder.cc
                            ./tensorflow/core/lib/io/format.cc
                            ./tensorflow/core/lib/io/inputbuffer.cc
                            ./tensorflow/core/lib/io/iterator.cc
                            ./tensorflow/core/lib/io/match.cc
                            ./tensorflow/core/lib/io/path.cc
                            ./tensorflow/core/lib/io/record_reader.cc
                            ./tensorflow/core/lib/io/record_writer.cc
                            ./tensorflow/core/lib/io/table.cc
                            ./tensorflow/core/lib/io/table_builder.cc
                            ./tensorflow/core/lib/io/two_level_iterator.cc
                            ./tensorflow/core/lib/jpeg/jpeg_handle.cc
                            ./tensorflow/core/lib/jpeg/jpeg_mem.cc
                            ./tensorflow/core/lib/png/png_io.cc
                            ./tensorflow/core/lib/random/distribution_sampler.cc
                            ./tensorflow/core/lib/random/random.cc
                            ./tensorflow/core/lib/random/simple_philox.cc
                            ./tensorflow/core/lib/random/weighted_picker.cc
                            ./tensorflow/core/lib/strings/numbers.cc
                            ./tensorflow/core/lib/strings/ordered_code.cc
                            ./tensorflow/core/lib/strings/proto_text_util.cc
                            ./tensorflow/core/lib/strings/scanner.cc
                            ./tensorflow/core/lib/strings/strcat.cc
                            ./tensorflow/core/lib/strings/stringprintf.cc
                            ./tensorflow/core/lib/strings/str_util.cc
                            ./tensorflow/core/lib/wav/wav_io.cc)
add_library(tensorflowCoreLib STATIC ${TENSORFLOW_CORE_LIB_SRC})

set(TENSORFLOW_CORE_PLATFORM_SRC ./tensorflow/core/platform/default/logging.cc
                                 ./tensorflow/core/platform/default/tracing.cc
                                 ./tensorflow/core/platform/posix/env.cc
                                 ./tensorflow/core/platform/posix/posix_file_system.cc
                                 ./tensorflow/core/platform/posix/port.cc
                                 ./tensorflow/core/platform/denormal.cc
                                 ./tensorflow/core/platform/env.cc
                                 ./tensorflow/core/platform/file_system.cc
                                 ./tensorflow/core/platform/load_library.cc
                                 ./tensorflow/core/platform/protobuf_util.cc
                                 ./tensorflow/core/platform/tensor_coding.cc
                                 ./tensorflow/core/platform/tracing.cc)
add_library(tensorflowCorePlatform STATIC ${TENSORFLOW_CORE_PLATFORM_SRC})

option(BUILD_PROTO_TEXT "Whether to build proto_text binary" OFF)

if(BUILD_PROTO_TEXT)

  set(TENSORFLOW_TOOLS_PROTO_TEXT_SRC ./tensorflow/tools/proto_text/gen_proto_text_functions_lib.cc)
  add_library(tensorflowToolsProtoText STATIC ${TENSORFLOW_TOOLS_PROTO_TEXT_SRC})

  add_executable(gen_proto_text_functions ./tensorflow/tools/proto_text/gen_proto_text_functions.cc)
  target_link_libraries(gen_proto_text_functions tensorflowToolsProtoText
                                                 tensorflowCoreLib
                                                 tensorflowCorePlatform
                                                 posix
                                                 libprotobuf)

endif()

set(TENSORFLOW_CORE_CLIENT_SRC tensorflow/core/client/tensor_c_api.cc)
add_library(tensorflowCoreClient STATIC ${TENSORFLOW_CORE_CLIENT_SRC})

set(TENSORFLOW_CORE_CPU_SRC tensorflow/core/common_runtime/direct_session.cc
                            tensorflow/core/common_runtime/threadpool_device_factory.cc)
add_library(tensorflowCoreCpu OBJECT ${TENSORFLOW_CORE_CPU_SRC})

set(TENSORFLOW_CORE_COMMON_RUNTIME_SRC tensorflow/core/common_runtime/gpu/cupti_wrapper.cc
                                       tensorflow/core/common_runtime/gpu/gpu_bfc_allocator.cc
                                       tensorflow/core/common_runtime/gpu/gpu_debug_allocator.cc
                                       tensorflow/core/common_runtime/gpu/gpu_device.cc
                                       tensorflow/core/common_runtime/gpu/gpu_device_factory.cc
                                       tensorflow/core/common_runtime/gpu/gpu_event_mgr.cc
                                       tensorflow/core/common_runtime/gpu/gpu_init.cc
                                       tensorflow/core/common_runtime/gpu/gpu_stream_util.cc
                                       tensorflow/core/common_runtime/gpu/gpu_tracer.cc
                                       tensorflow/core/common_runtime/gpu/gpu_util.cc
                                       tensorflow/core/common_runtime/gpu/gpu_util_platform_specific.cc
                                       tensorflow/core/common_runtime/gpu/pool_allocator.cc
                                       tensorflow/core/common_runtime/gpu/process_state.cc
                                       tensorflow/core/common_runtime/allocator_retry.cc
                                       tensorflow/core/common_runtime/bfc_allocator.cc
                                       tensorflow/core/common_runtime/build_graph_options.cc
                                       tensorflow/core/common_runtime/constant_folding.cc
                                       tensorflow/core/common_runtime/copy_tensor.cc
                                       tensorflow/core/common_runtime/costmodel_manager.cc
                                       tensorflow/core/common_runtime/device.cc
                                       tensorflow/core/common_runtime/device_factory.cc
                                       tensorflow/core/common_runtime/device_mgr.cc
                                       tensorflow/core/common_runtime/device_set.cc
                                       tensorflow/core/common_runtime/executor.cc
                                       tensorflow/core/common_runtime/function.cc
                                       tensorflow/core/common_runtime/graph_optimizer.cc
                                       tensorflow/core/common_runtime/local_device.cc
                                       tensorflow/core/common_runtime/memory_types.cc
                                       tensorflow/core/common_runtime/process_util.cc
                                       tensorflow/core/common_runtime/rendezvous_mgr.cc
                                       tensorflow/core/common_runtime/session.cc
                                       tensorflow/core/common_runtime/session_factory.cc
                                       tensorflow/core/common_runtime/session_options.cc
                                       tensorflow/core/common_runtime/session_state.cc
                                       tensorflow/core/common_runtime/simple_graph_execution_state.cc
                                       tensorflow/core/common_runtime/simple_placer.cc
                                       tensorflow/core/common_runtime/step_stats_collector.cc
                                       tensorflow/core/common_runtime/threadpool_device.cc)
add_library(tensorflowCoreCommonRuntime STATIC ${TENSORFLOW_CORE_COMMON_RUNTIME_SRC})

set(TENSORFLOW_CORE_RPC_SRC tensorflow/core/distributed_runtime/rpc/grpc_server_lib.cc
                            tensorflow/core/distributed_runtime/rpc/grpc_session.cc)
add_library(tensorflowCoreRpc OBJECT ${TENSORFLOW_CORE_RPC_SRC})

set(TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_SRC tensorflow/core/distributed_runtime/rpc/grpc_channel.cc
                                            tensorflow/core/distributed_runtime/rpc/grpc_master_service.cc
                                            tensorflow/core/distributed_runtime/rpc/grpc_remote_master.cc
                                            tensorflow/core/distributed_runtime/rpc/grpc_remote_worker.cc
                                            tensorflow/core/distributed_runtime/rpc/grpc_worker_cache.cc
                                            tensorflow/core/distributed_runtime/rpc/grpc_worker_service.cc
                                            tensorflow/core/distributed_runtime/rpc/rpc_rendezvous_mgr.cc
                                            tensorflow/core/distributed_runtime/base_rendezvous_mgr.cc
                                            tensorflow/core/distributed_runtime/call_options.cc
                                            tensorflow/core/distributed_runtime/graph_mgr.cc
                                            tensorflow/core/distributed_runtime/master.cc
                                            tensorflow/core/distributed_runtime/master_session.cc
                                            tensorflow/core/distributed_runtime/remote_device.cc
                                            tensorflow/core/distributed_runtime/server_lib.cc
                                            tensorflow/core/distributed_runtime/worker_cache_logger.cc
                                            tensorflow/core/distributed_runtime/worker_cache_partial.cc)
add_library(tensorflowCoreDistributedRuntime STATIC ${TENSORFLOW_CORE_DISTRIBUTED_RUNTIME_SRC})

set(TENSORFLOW_CORE_EXAMPLE_SRC tensorflow/core/example/example.pb.cc
                                tensorflow/core/example/feature.pb.cc
                                tensorflow/core/example/feature.pb_text.cc
                                tensorflow/core/example/feature_util.cc)
add_library(tensorflowCoreExample STATIC ${TENSORFLOW_CORE_EXAMPLE_SRC})

set(TENSORFLOW_CORE_FRAMEWORK_SRC tensorflow/core/framework/allocation_description.pb.cc
                                  tensorflow/core/framework/allocation_description.pb_text.cc
                                  tensorflow/core/framework/allocator.cc
                                  tensorflow/core/framework/attr_value.pb.cc
                                  tensorflow/core/framework/attr_value.pb_text.cc
                                  tensorflow/core/framework/attr_value_util.cc
                                  tensorflow/core/framework/bfloat16.cc
                                  tensorflow/core/framework/cancellation.cc
                                  tensorflow/core/framework/cost_graph.pb.cc
                                  tensorflow/core/framework/device_attributes.pb.cc
                                  tensorflow/core/framework/device_attributes.pb_text.cc
                                  tensorflow/core/framework/device_base.cc
                                  tensorflow/core/framework/function.cc
                                  tensorflow/core/framework/function.pb.cc
                                  tensorflow/core/framework/function.pb_text.cc
                                  tensorflow/core/framework/graph.pb.cc
                                  tensorflow/core/framework/graph.pb_text.cc
                                  tensorflow/core/framework/graph_def_util.cc
                                  tensorflow/core/framework/kernel_def.pb.cc
                                  tensorflow/core/framework/kernel_def.pb_text.cc
                                  tensorflow/core/framework/kernel_def_builder.cc
                                  tensorflow/core/framework/load_library.cc
                                  tensorflow/core/framework/log_memory.cc
                                  tensorflow/core/framework/log_memory.pb.cc
                                  tensorflow/core/framework/log_memory.pb_text.cc
                                  tensorflow/core/framework/lookup_interface.cc
                                  tensorflow/core/framework/memory_types.cc
                                  tensorflow/core/framework/node_def_builder.cc
                                  tensorflow/core/framework/node_def_util.cc
                                  tensorflow/core/framework/op.cc
                                  tensorflow/core/framework/op_def.pb.cc
                                  tensorflow/core/framework/op_def.pb_text.cc
                                  tensorflow/core/framework/op_def_builder.cc
                                  tensorflow/core/framework/op_def_util.cc
                                  tensorflow/core/framework/op_gen_lib.cc
                                  tensorflow/core/framework/op_kernel.cc
                                  tensorflow/core/framework/op_segment.cc
                                  tensorflow/core/framework/partial_tensor_shape.cc
                                  tensorflow/core/framework/reader_op_kernel.cc
                                  tensorflow/core/framework/rendezvous.cc
                                  tensorflow/core/framework/resource_mgr.cc
                                  tensorflow/core/framework/step_stats.pb.cc
                                  tensorflow/core/framework/summary.pb.cc
                                  tensorflow/core/framework/tensor.cc
                                  tensorflow/core/framework/tensor.pb.cc
                                  tensorflow/core/framework/tensor.pb_text.cc
                                  tensorflow/core/framework/tensor_description.pb.cc
                                  tensorflow/core/framework/tensor_description.pb_text.cc
                                  tensorflow/core/framework/tensor_reference.cc
                                  tensorflow/core/framework/tensor_shape.cc
                                  tensorflow/core/framework/tensor_shape.pb.cc
                                  tensorflow/core/framework/tensor_shape.pb_text.cc
                                  tensorflow/core/framework/tensor_slice.cc
                                  tensorflow/core/framework/tensor_slice.pb.cc
                                  tensorflow/core/framework/tensor_slice.pb_text.cc
                                  tensorflow/core/framework/tensor_util.cc
                                  tensorflow/core/framework/tracking_allocator.cc
                                  tensorflow/core/framework/types.cc
                                  tensorflow/core/framework/types.pb.cc
                                  tensorflow/core/framework/types.pb_text.cc
                                  tensorflow/core/framework/unique_tensor_references.cc
                                  tensorflow/core/framework/variable.pb.cc
                                  tensorflow/core/framework/versions.cc
                                  tensorflow/core/framework/versions.pb.cc
                                  tensorflow/core/framework/versions.pb_text.cc)
add_library(tensorflowCoreFramework STATIC ${TENSORFLOW_CORE_FRAMEWORK_SRC})

set(TENSORFLOW_CORE_GRAPH_SRC tensorflow/core/graph/algorithm.cc
                              tensorflow/core/graph/colors.cc
                              tensorflow/core/graph/costmodel.cc
                              tensorflow/core/graph/dot.cc
                              tensorflow/core/graph/edgeset.cc
                              tensorflow/core/graph/equal_graph_def.cc
                              tensorflow/core/graph/gradients.cc
                              tensorflow/core/graph/graph.cc
                              tensorflow/core/graph/graph_constructor.cc
                              tensorflow/core/graph/graph_def_builder.cc
                              tensorflow/core/graph/graph_partition.cc
                              tensorflow/core/graph/node_builder.cc
                              tensorflow/core/graph/optimizer_cse.cc
                              tensorflow/core/graph/subgraph.cc
                              tensorflow/core/graph/tensor_id.cc
                              tensorflow/core/graph/validate.cc)
add_library(tensorflowCoreGraph STATIC ${TENSORFLOW_CORE_GRAPH_SRC})

set(TENSORFLOW_CORE_KERNELS_SRC tensorflow/core/kernels/adjust_contrast_op.cc
                                tensorflow/core/kernels/adjust_contrast_op_gpu.cu.cc
                                tensorflow/core/kernels/aggregate_ops.cc
                                tensorflow/core/kernels/aggregate_ops_gpu.cu.cc
                                tensorflow/core/kernels/argmax_op.cc
                                tensorflow/core/kernels/argmax_op_gpu.cu.cc
                                tensorflow/core/kernels/attention_ops.cc
                                tensorflow/core/kernels/avgpooling_op.cc
                                tensorflow/core/kernels/avgpooling_op_gpu.cu.cc
                                tensorflow/core/kernels/batchtospace_op.cc
                                tensorflow/core/kernels/batchtospace_op_gpu.cu.cc
                                tensorflow/core/kernels/batch_matmul_op.cc
                                tensorflow/core/kernels/batch_matrix_band_part_op.cc
                                tensorflow/core/kernels/batch_matrix_band_part_op_gpu.cu.cc
                                tensorflow/core/kernels/batch_matrix_diag_op.cc
                                tensorflow/core/kernels/batch_matrix_diag_op_gpu.cu.cc
                                tensorflow/core/kernels/batch_norm_op.cc
                                tensorflow/core/kernels/batch_norm_op_gpu.cu.cc
                                tensorflow/core/kernels/bcast_ops.cc
                                tensorflow/core/kernels/bias_op.cc
                                tensorflow/core/kernels/bias_op_gpu.cu.cc
                                tensorflow/core/kernels/binary_linalg_ops_common.cc
                                tensorflow/core/kernels/bitcast_op.cc
                                tensorflow/core/kernels/candidate_sampler_ops.cc
                                tensorflow/core/kernels/cast_op.cc
                                tensorflow/core/kernels/cast_op_gpu.cu.cc
                                tensorflow/core/kernels/check_numerics_op.cc
                                tensorflow/core/kernels/check_numerics_op_gpu.cu.cc
                                tensorflow/core/kernels/cholesky_grad.cc
                                tensorflow/core/kernels/cholesky_op.cc
                                tensorflow/core/kernels/colorspace_op.cc
                                tensorflow/core/kernels/colorspace_op_gpu.cu.cc
                                tensorflow/core/kernels/concat_lib_cpu.cc
                                tensorflow/core/kernels/concat_lib_gpu.cu.cc
                                tensorflow/core/kernels/concat_op.cc
                                tensorflow/core/kernels/constant_op.cc
                                tensorflow/core/kernels/constant_op_gpu.cu.cc
                                tensorflow/core/kernels/control_flow_ops.cc
                                tensorflow/core/kernels/conv_grad_ops.cc
                                tensorflow/core/kernels/conv_grad_ops_3d.cc
                                tensorflow/core/kernels/conv_ops.cc
                                tensorflow/core/kernels/conv_ops_3d.cc
                                tensorflow/core/kernels/conv_ops_gpu_2.cu.cc
                                tensorflow/core/kernels/conv_ops_gpu_3.cu.cc
                                tensorflow/core/kernels/count_up_to_op.cc
                                tensorflow/core/kernels/cross_op.cc
                                tensorflow/core/kernels/cross_op_gpu.cu.cc
                                tensorflow/core/kernels/ctc_decoder_ops.cc
                                tensorflow/core/kernels/ctc_loss_op.cc
                                tensorflow/core/kernels/cudnn_pooling_gpu.cc
                                tensorflow/core/kernels/cwise_ops_common.cc
                                tensorflow/core/kernels/cwise_op_abs.cc
                                tensorflow/core/kernels/cwise_op_add.cc
                                tensorflow/core/kernels/cwise_op_ceil.cc
                                tensorflow/core/kernels/cwise_op_complex.cc
                                tensorflow/core/kernels/cwise_op_conj.cc
                                tensorflow/core/kernels/cwise_op_cos.cc
                                tensorflow/core/kernels/cwise_op_digamma.cc
                                tensorflow/core/kernels/cwise_op_div.cc
                                tensorflow/core/kernels/cwise_op_equal_to.cc
                                tensorflow/core/kernels/cwise_op_erf.cc
                                tensorflow/core/kernels/cwise_op_erfc.cc
                                tensorflow/core/kernels/cwise_op_exp.cc
                                tensorflow/core/kernels/cwise_op_floor.cc
                                tensorflow/core/kernels/cwise_op_gpu_abs.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_add.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_ceil.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_complex.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_conj.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_cos.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_digamma.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_div.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_equal_to.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_erf.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_erfc.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_exp.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_floor.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_greater.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_greater_equal.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_igammas.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_imag.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_inverse.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_isfinite.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_isinf.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_isnan.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_less.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_less_equal.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_lgamma.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_log.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_logical_and.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_logical_not.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_logical_or.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_maximum.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_minimum.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_mod.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_mul.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_neg.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_not_equal_to.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_pow.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_real.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_rsqrt.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_select.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_sigmoid.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_sign.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_sin.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_sqrt.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_square.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_squared_difference.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_sub.cu.cc
                                tensorflow/core/kernels/cwise_op_gpu_tanh.cu.cc
                                tensorflow/core/kernels/cwise_op_greater.cc
                                tensorflow/core/kernels/cwise_op_greater_equal.cc
                                tensorflow/core/kernels/cwise_op_igammas.cc
                                tensorflow/core/kernels/cwise_op_imag.cc
                                tensorflow/core/kernels/cwise_op_inverse.cc
                                tensorflow/core/kernels/cwise_op_isfinite.cc
                                tensorflow/core/kernels/cwise_op_isinf.cc
                                tensorflow/core/kernels/cwise_op_isnan.cc
                                tensorflow/core/kernels/cwise_op_less.cc
                                tensorflow/core/kernels/cwise_op_less_equal.cc
                                tensorflow/core/kernels/cwise_op_lgamma.cc
                                tensorflow/core/kernels/cwise_op_log.cc
                                tensorflow/core/kernels/cwise_op_logical_and.cc
                                tensorflow/core/kernels/cwise_op_logical_not.cc
                                tensorflow/core/kernels/cwise_op_logical_or.cc
                                tensorflow/core/kernels/cwise_op_maximum.cc
                                tensorflow/core/kernels/cwise_op_minimum.cc
                                tensorflow/core/kernels/cwise_op_mod.cc
                                tensorflow/core/kernels/cwise_op_mul.cc
                                tensorflow/core/kernels/cwise_op_neg.cc
                                tensorflow/core/kernels/cwise_op_not_equal_to.cc
                                tensorflow/core/kernels/cwise_op_pow.cc
                                tensorflow/core/kernels/cwise_op_real.cc
                                tensorflow/core/kernels/cwise_op_rsqrt.cc
                                tensorflow/core/kernels/cwise_op_select.cc
                                tensorflow/core/kernels/cwise_op_sigmoid.cc
                                tensorflow/core/kernels/cwise_op_sign.cc
                                tensorflow/core/kernels/cwise_op_sin.cc
                                tensorflow/core/kernels/cwise_op_sqrt.cc
                                tensorflow/core/kernels/cwise_op_square.cc
                                tensorflow/core/kernels/cwise_op_squared_difference.cc
                                tensorflow/core/kernels/cwise_op_sub.cc
                                tensorflow/core/kernels/cwise_op_tanh.cc
                                tensorflow/core/kernels/decode_csv_op.cc
                                tensorflow/core/kernels/decode_jpeg_op.cc
                                tensorflow/core/kernels/decode_png_op.cc
                                tensorflow/core/kernels/decode_raw_op.cc
                                tensorflow/core/kernels/dense_update_ops.cc
                                tensorflow/core/kernels/dense_update_ops_gpu.cu.cc
                                tensorflow/core/kernels/depthtospace_op.cc
                                tensorflow/core/kernels/depthtospace_op_gpu.cu.cc
                                tensorflow/core/kernels/depthwise_conv_grad_op.cc
                                tensorflow/core/kernels/depthwise_conv_op.cc
                                tensorflow/core/kernels/depthwise_conv_op_gpu.cu.cc
                                tensorflow/core/kernels/determinant_op.cc
                                tensorflow/core/kernels/diag_op.cc
                                tensorflow/core/kernels/draw_bounding_box_op.cc
                                tensorflow/core/kernels/dynamic_partition_op.cc
                                tensorflow/core/kernels/dynamic_stitch_op.cc
                                tensorflow/core/kernels/edit_distance_op.cc
                                tensorflow/core/kernels/encode_jpeg_op.cc
                                tensorflow/core/kernels/encode_png_op.cc
                                tensorflow/core/kernels/fact_op.cc
                                tensorflow/core/kernels/fft_ops.cc
                                tensorflow/core/kernels/fifo_queue.cc
                                tensorflow/core/kernels/fifo_queue_op.cc
                                tensorflow/core/kernels/fixed_length_record_reader_op.cc
                                tensorflow/core/kernels/gather_nd_op.cc
                                tensorflow/core/kernels/gather_nd_op_gpu.cu.cc
                                tensorflow/core/kernels/gather_op.cc
                                tensorflow/core/kernels/gather_op_gpu.cu.cc
                                tensorflow/core/kernels/identity_op.cc
                                tensorflow/core/kernels/identity_reader_op.cc
                                tensorflow/core/kernels/immutable_constant_op.cc
                                tensorflow/core/kernels/initializable_lookup_table.cc
                                tensorflow/core/kernels/in_topk_op.cc
                                tensorflow/core/kernels/l2loss_op.cc
                                tensorflow/core/kernels/l2loss_op_gpu.cu.cc
                                tensorflow/core/kernels/linalg_ops_common.cc
                                tensorflow/core/kernels/listdiff_op.cc
                                tensorflow/core/kernels/logging_ops.cc
                                tensorflow/core/kernels/lookup_table_init_op.cc
                                tensorflow/core/kernels/lookup_table_op.cc
                                tensorflow/core/kernels/lookup_util.cc
                                tensorflow/core/kernels/lrn_op.cc
                                tensorflow/core/kernels/matching_files_op.cc
                                tensorflow/core/kernels/matmul_op.cc
                                tensorflow/core/kernels/matrix_inverse_op.cc
                                tensorflow/core/kernels/matrix_solve_ls_op.cc
                                tensorflow/core/kernels/matrix_solve_op.cc
                                tensorflow/core/kernels/matrix_triangular_solve_op.cc
                                tensorflow/core/kernels/maxpooling_op.cc
                                tensorflow/core/kernels/maxpooling_op_gpu.cu.cc
                                tensorflow/core/kernels/mirror_pad_op.cc
                                tensorflow/core/kernels/mirror_pad_op_gpu.cu.cc
                                tensorflow/core/kernels/no_op.cc
                                tensorflow/core/kernels/one_hot_op.cc
                                tensorflow/core/kernels/one_hot_op_gpu.cu.cc
                                tensorflow/core/kernels/ops_util.cc
                                tensorflow/core/kernels/pack_op.cc
                                tensorflow/core/kernels/padding_fifo_queue.cc
                                tensorflow/core/kernels/padding_fifo_queue_op.cc
                                tensorflow/core/kernels/pad_op.cc
                                tensorflow/core/kernels/pad_op_gpu.cu.cc
                                tensorflow/core/kernels/pooling_ops_3d.cc
                                tensorflow/core/kernels/pooling_ops_common.cc
                                tensorflow/core/kernels/queue_base.cc
                                tensorflow/core/kernels/queue_ops.cc
                                tensorflow/core/kernels/random_crop_op.cc
                                tensorflow/core/kernels/random_op.cc
                                tensorflow/core/kernels/random_op_gpu.cu.cc
                                tensorflow/core/kernels/random_shuffle_op.cc
                                tensorflow/core/kernels/random_shuffle_queue_op.cc
                                tensorflow/core/kernels/range_sampler.cc
                                tensorflow/core/kernels/reader_base.cc
                                tensorflow/core/kernels/reader_base.pb.cc
                                tensorflow/core/kernels/reader_ops.cc
                                tensorflow/core/kernels/reduce_join_op.cc
                                tensorflow/core/kernels/reduction_ops_all.cc
                                tensorflow/core/kernels/reduction_ops_any.cc
                                tensorflow/core/kernels/reduction_ops_common.cc
                                tensorflow/core/kernels/reduction_ops_gpu.cu.cc
                                tensorflow/core/kernels/reduction_ops_max.cc
                                tensorflow/core/kernels/reduction_ops_mean.cc
                                tensorflow/core/kernels/reduction_ops_min.cc
                                tensorflow/core/kernels/reduction_ops_prod.cc
                                tensorflow/core/kernels/reduction_ops_sum.cc
                                tensorflow/core/kernels/relu_op.cc
                                tensorflow/core/kernels/relu_op_gpu.cu.cc
                                tensorflow/core/kernels/reshape_op.cc
                                tensorflow/core/kernels/resize_area_op.cc
                                tensorflow/core/kernels/resize_bicubic_op.cc
                                tensorflow/core/kernels/resize_bilinear_op.cc
                                tensorflow/core/kernels/resize_nearest_neighbor_op.cc
                                tensorflow/core/kernels/resize_nearest_neighbor_op_gpu.cu.cc
                                tensorflow/core/kernels/restore_op.cc
                                tensorflow/core/kernels/reverse_op.cc
                                tensorflow/core/kernels/reverse_op_gpu.cu.cc
                                tensorflow/core/kernels/reverse_sequence_op.cc
                                tensorflow/core/kernels/reverse_sequence_op_gpu.cu.cc
                                tensorflow/core/kernels/sample_distorted_bounding_box_op.cc
                                tensorflow/core/kernels/save_op.cc
                                tensorflow/core/kernels/save_restore_tensor.cc
                                tensorflow/core/kernels/scatter_op.cc
                                tensorflow/core/kernels/scatter_op_gpu.cu.cc
                                tensorflow/core/kernels/segment_reduction_ops.cc
                                tensorflow/core/kernels/self_adjoint_eig_op.cc
                                tensorflow/core/kernels/sendrecv_ops.cc
                                tensorflow/core/kernels/sequence_ops.cc
                                tensorflow/core/kernels/serialize_sparse_op.cc
                                tensorflow/core/kernels/session_ops.cc
                                tensorflow/core/kernels/shape_ops.cc
                                tensorflow/core/kernels/slice_op.cc
                                tensorflow/core/kernels/slice_op_gpu.cu.cc
                                tensorflow/core/kernels/softmax_op.cc
                                tensorflow/core/kernels/softmax_op_gpu.cu.cc
                                tensorflow/core/kernels/softplus_op.cc
                                tensorflow/core/kernels/softplus_op_gpu.cu.cc
                                tensorflow/core/kernels/softsign_op.cc
                                tensorflow/core/kernels/softsign_op_gpu.cu.cc
                                tensorflow/core/kernels/spacetobatch_op.cc
                                tensorflow/core/kernels/spacetobatch_op_gpu.cu.cc
                                tensorflow/core/kernels/spacetodepth_op.cc
                                tensorflow/core/kernels/spacetodepth_op_gpu.cu.cc
                                tensorflow/core/kernels/sparse_add_grad_op.cc
                                tensorflow/core/kernels/sparse_add_op.cc
                                tensorflow/core/kernels/sparse_concat_op.cc
                                tensorflow/core/kernels/sparse_dense_binary_op_shared.cc
                                tensorflow/core/kernels/sparse_matmul_op.cc
                                tensorflow/core/kernels/sparse_reduce_sum_op.cc
                                tensorflow/core/kernels/sparse_reorder_op.cc
                                tensorflow/core/kernels/sparse_split_op.cc
                                tensorflow/core/kernels/sparse_tensor_dense_add_op.cc
                                tensorflow/core/kernels/sparse_tensor_dense_matmul_op.cc
                                tensorflow/core/kernels/sparse_tensor_dense_matmul_op_gpu.cu.cc
                                tensorflow/core/kernels/sparse_to_dense_op.cc
                                tensorflow/core/kernels/sparse_xent_op.cc
                                tensorflow/core/kernels/sparse_xent_op_gpu.cu.cc
                                tensorflow/core/kernels/split_lib_cpu.cc
                                tensorflow/core/kernels/split_lib_gpu.cu.cc
                                tensorflow/core/kernels/split_op.cc
                                tensorflow/core/kernels/stack_ops.cc
                                tensorflow/core/kernels/string_to_hash_bucket_op.cc
                                tensorflow/core/kernels/string_to_number_op.cc
                                tensorflow/core/kernels/summary_audio_op.cc
                                tensorflow/core/kernels/summary_image_op.cc
                                tensorflow/core/kernels/summary_op.cc
                                tensorflow/core/kernels/tensor_array.cc
                                tensorflow/core/kernels/tensor_array_ops.cc
                                tensorflow/core/kernels/text_line_reader_op.cc
                                tensorflow/core/kernels/tf_record_reader_op.cc
                                tensorflow/core/kernels/tile_ops.cc
                                tensorflow/core/kernels/tile_ops_gpu.cu.cc
                                tensorflow/core/kernels/topk_op.cc
                                tensorflow/core/kernels/training_ops.cc
                                tensorflow/core/kernels/training_ops_gpu.cu.cc
                                tensorflow/core/kernels/transpose_functor_cpu.cc
                                tensorflow/core/kernels/transpose_functor_gpu.cu.cc
                                tensorflow/core/kernels/transpose_op.cc
                                tensorflow/core/kernels/unique_op.cc
                                tensorflow/core/kernels/unpack_op.cc
                                tensorflow/core/kernels/variable_ops.cc
                                tensorflow/core/kernels/where_op.cc
                                tensorflow/core/kernels/whole_file_read_ops.cc
                                tensorflow/core/kernels/xent_op.cc
                                tensorflow/core/kernels/xent_op_gpu.cu.cc)
add_library(tensorflowCoreKernels OBJECT ${TENSORFLOW_CORE_KERNELS_SRC})

set(TENSORFLOW_CORE_OPS_SRC tensorflow/core/ops/array_grad.cc
                            tensorflow/core/ops/array_ops.cc
                            tensorflow/core/ops/candidate_sampling_ops.cc
                            tensorflow/core/ops/control_flow_ops.cc
                            tensorflow/core/ops/ctc_ops.cc
                            tensorflow/core/ops/data_flow_ops.cc
                            tensorflow/core/ops/functional_grad.cc
                            tensorflow/core/ops/functional_ops.cc
                            tensorflow/core/ops/function_ops.cc
                            tensorflow/core/ops/image_ops.cc
                            tensorflow/core/ops/io_ops.cc
                            tensorflow/core/ops/linalg_ops.cc
                            tensorflow/core/ops/logging_ops.cc
                            tensorflow/core/ops/math_grad.cc
                            tensorflow/core/ops/math_ops.cc
                            tensorflow/core/ops/nn_grad.cc
                            tensorflow/core/ops/nn_ops.cc
                            tensorflow/core/ops/no_op.cc
                            tensorflow/core/ops/parsing_ops.cc
                            tensorflow/core/ops/random_grad.cc
                            tensorflow/core/ops/random_ops.cc
                            tensorflow/core/ops/script_ops.cc
                            tensorflow/core/ops/sendrecv_ops.cc
                            tensorflow/core/ops/sparse_ops.cc
                            tensorflow/core/ops/state_ops.cc
                            tensorflow/core/ops/string_ops.cc
                            tensorflow/core/ops/training_ops.cc)
add_library(tensorflowCoreOps OBJECT ${TENSORFLOW_CORE_OPS_SRC})

set(TENSORFLOW_CORE_USER_OPS_SRC tensorflow/core/user_ops/fact.cc)
add_library(tensorflowCoreUserOps OBJECT ${TENSORFLOW_CORE_USER_OPS_SRC})

set(TENSORFLOW_CORE_PROTOBUF_SRC tensorflow/core/protobuf/config.pb.cc
                                 tensorflow/core/protobuf/master.pb.cc
                                 tensorflow/core/protobuf/master_service.grpc.pb.cc
                                 tensorflow/core/protobuf/master_service.pb.cc
                                 tensorflow/core/protobuf/meta_graph.pb.cc
                                 tensorflow/core/protobuf/named_tensor.pb.cc
                                 tensorflow/core/protobuf/queue_runner.pb.cc
                                 tensorflow/core/protobuf/saver.pb.cc
                                 tensorflow/core/protobuf/tensorflow_server.pb.cc
                                 tensorflow/core/protobuf/worker.pb.cc
                                 tensorflow/core/protobuf/worker_service.grpc.pb.cc
                                 tensorflow/core/protobuf/worker_service.pb.cc)
add_library(tensorflowCoreProtobuf STATIC ${TENSORFLOW_CORE_PROTOBUF_SRC})

set(TENSORFLOW_CORE_UTIL_SRC tensorflow/core/util/ctc/ctc_loss_calculator.cc
                             tensorflow/core/util/sparse/group_iterator.cc
                             tensorflow/core/util/bcast.cc
                             tensorflow/core/util/checkpoint_reader.cc
                             tensorflow/core/util/command_line_flags.cc
                             tensorflow/core/util/device_name_utils.cc
                             tensorflow/core/util/event.pb.cc
                             tensorflow/core/util/events_writer.cc
                             tensorflow/core/util/example_proto_helper.cc
                             tensorflow/core/util/guarded_philox_random.cc
                             tensorflow/core/util/memmapped_file_system.cc
                             tensorflow/core/util/memmapped_file_system.pb.cc
                             tensorflow/core/util/memmapped_file_system_writer.cc
                             tensorflow/core/util/mirror_pad_mode.cc
                             tensorflow/core/util/padding.cc
                             tensorflow/core/util/port.cc
                             tensorflow/core/util/saved_tensor_slice.pb.cc
                             tensorflow/core/util/saved_tensor_slice.pb_text.cc
                             tensorflow/core/util/saved_tensor_slice_util.cc
                             tensorflow/core/util/stat_summarizer.cc
                             tensorflow/core/util/tensor_format.cc
                             tensorflow/core/util/tensor_slice_reader.cc
                             tensorflow/core/util/tensor_slice_reader_cache.cc
                             tensorflow/core/util/tensor_slice_set.cc
                             tensorflow/core/util/tensor_slice_writer.cc
                             tensorflow/core/util/tf_status_helper.cc
                             tensorflow/core/util/use_cudnn.cc
                             tensorflow/core/util/util.cc
                             tensorflow/core/util/work_sharder.cc)
add_library(tensorflowCoreUtil STATIC ${TENSORFLOW_CORE_UTIL_SRC})

option(BUILD_CC_OPS "Whether to build cc wrappers for tensorflow operations" OFF)

if(BUILD_CC_OPS)

  set(TENSORFLOW_CC_OPS_GEN_SRC tensorflow/cc/ops/cc_op_gen.cc
                                tensorflow/cc/ops/cc_op_gen_main.cc)
  add_library(tensorflowCcOpsGen OBJECT ${TENSORFLOW_CC_OPS_GEN_SRC})
  
  set(TENSORFLOW_CC_OPS_GEN_LIB tensorflowCoreFramework
                                tensorflowCoreLib
                                tensorflowCorePlatform
                                tensorflowCoreUtil
                                posix Psapi
                                libprotobuf)

  add_executable(gen_cc_op_array_ops ./tensorflow/core/ops/array_ops.cc
                                     $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_array_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_candidate_sampling_ops ./tensorflow/core/ops/candidate_sampling_ops.cc
                                                  $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_candidate_sampling_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_control_flow_ops ./tensorflow/core/ops/control_flow_ops.cc
                                            $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_control_flow_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_data_flow_ops ./tensorflow/core/ops/data_flow_ops.cc
                                         $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_data_flow_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_image_ops ./tensorflow/core/ops/image_ops.cc
                                     $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_image_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_io_ops ./tensorflow/core/ops/io_ops.cc
                                  $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_io_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_linalg_ops ./tensorflow/core/ops/linalg_ops.cc
                                      $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_linalg_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_logging_ops ./tensorflow/core/ops/logging_ops.cc
                                       $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_logging_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_math_ops ./tensorflow/core/ops/math_ops.cc
                                    $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_math_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_nn_ops ./tensorflow/core/ops/nn_ops.cc
                                  $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_nn_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_no_op ./tensorflow/core/ops/no_op.cc
                                 $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_no_op ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_parsing_ops ./tensorflow/core/ops/parsing_ops.cc
                                       $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_parsing_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_random_ops ./tensorflow/core/ops/random_ops.cc
                                      $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_random_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_sendrecv_ops ./tensorflow/core/ops/sendrecv_ops.cc
                                        $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_sendrecv_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_sparse_ops ./tensorflow/core/ops/sparse_ops.cc
                                      $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_sparse_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_state_ops ./tensorflow/core/ops/state_ops.cc
                                     $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_state_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_string_ops ./tensorflow/core/ops/string_ops.cc
                                      $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_string_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_training_ops ./tensorflow/core/ops/training_ops.cc
                                        $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_training_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

  add_executable(gen_cc_op_user_ops ./tensorflow/core/user_ops/fact.cc
                                    $<TARGET_OBJECTS:tensorflowCcOpsGen>)
  target_link_libraries(gen_cc_op_user_ops ${TENSORFLOW_CC_OPS_GEN_LIB})

endif()

option(BUILD_EXAMPLE_TRAINER "Whether to build the example trainer" OFF)

option(BUILD_LABEL_IMAGE "Whether to build the label image" OFF)

option(BUILD_UNIT_TESTS "Whether to build the unit tests" OFF)

if(BUILD_EXAMPLE_TRAINER OR BUILD_LABEL_IMAGE OR BUILD_UNIT_TESTS)

  set(TENSORFLOW_CC_OPS ./tensorflow/cc/ops/array_ops.cc
                        ./tensorflow/cc/ops/candidate_sampling_ops.cc
                        ./tensorflow/cc/ops/control_flow_ops.cc
                        ./tensorflow/cc/ops/const_op.cc
                        ./tensorflow/cc/ops/data_flow_ops.cc
                        ./tensorflow/cc/ops/image_ops.cc
                        ./tensorflow/cc/ops/io_ops.cc
                        ./tensorflow/cc/ops/linalg_ops.cc
                        ./tensorflow/cc/ops/logging_ops.cc
                        ./tensorflow/cc/ops/math_ops.cc
                        ./tensorflow/cc/ops/nn_ops.cc
                        ./tensorflow/cc/ops/no_op.cc
                        ./tensorflow/cc/ops/parsing_ops.cc
                        ./tensorflow/cc/ops/random_ops.cc
                        ./tensorflow/cc/ops/sendrecv_ops.cc
                        ./tensorflow/cc/ops/sparse_ops.cc
                        ./tensorflow/cc/ops/state_ops.cc
                        ./tensorflow/cc/ops/string_ops.cc
                        ./tensorflow/cc/ops/training_ops.cc
                        ./tensorflow/cc/ops/user_ops.cc)
  add_library(tensorflowCcOps STATIC ${TENSORFLOW_CC_OPS})

endif()

if(BUILD_EXAMPLE_TRAINER)

  add_executable(tutorials_example_trainer ./tensorflow/cc/tutorials/example_trainer.cc
                                           $<TARGET_OBJECTS:tensorflowCoreCpu>
                                           $<TARGET_OBJECTS:tensorflowCoreKernels>
                                           $<TARGET_OBJECTS:tensorflowCoreOps>
                                           $<TARGET_OBJECTS:tensorflowCoreUserOps>)
  target_link_libraries(tutorials_example_trainer tensorflowCcOps
                                                  tensorflowCoreCommonRuntime
                                                  tensorflowCoreExample
                                                  tensorflowCoreFramework
                                                  tensorflowCoreGraph
                                              	  tensorflowCoreLib
                                             	  tensorflowCorePlatform
												  tensorflowCoreProtobuf
												  tensorflowCoreUtil
												  posix Psapi
												  libprotobuf
												  jpeg
												  libpng12_static
												  zlibstatic
												  Shlwapi)

endif()

if (BUILD_LABEL_IMAGE)

  add_executable(label_image_main ./tensorflow/examples/label_image/main.cc
                                  $<TARGET_OBJECTS:tensorflowCoreCpu>
                                  $<TARGET_OBJECTS:tensorflowCoreKernels>
                                  $<TARGET_OBJECTS:tensorflowCoreOps>
                                  $<TARGET_OBJECTS:tensorflowCoreUserOps>)
  target_link_libraries(label_image_main tensorflowCcOps
                                         tensorflowCoreCommonRuntime
                                         tensorflowCoreExample
                                         tensorflowCoreFramework
                                         tensorflowCoreGraph
										 tensorflowCoreLib
										 tensorflowCorePlatform
										 tensorflowCoreProtobuf
										 tensorflowCoreUtil
										 posix Psapi
										 libprotobuf
										 jpeg
										 libpng12_static
										 zlibstatic
										 Shlwapi)

endif()

set(TENSORFLOW_STREAM_EXECUTOR_SRC #./tensorflow/stream_executor/cuda/cuda_activation.cc
                                   #./tensorflow/stream_executor/cuda/cuda_blas.cc
                                   #./tensorflow/stream_executor/cuda/cuda_diagnostics.cc
                                   #./tensorflow/stream_executor/cuda/cuda_dnn.cc
                                   #./tensorflow/stream_executor/cuda/cuda_driver.cc
                                   #./tensorflow/stream_executor/cuda/cuda_event.cc
                                   #./tensorflow/stream_executor/cuda/cuda_fft.cc
                                   #./tensorflow/stream_executor/cuda/cuda_gpu_executor.cc
                                   #./tensorflow/stream_executor/cuda/cuda_platform.cc
                                   #./tensorflow/stream_executor/cuda/cuda_platform_id.cc
                                   #./tensorflow/stream_executor/cuda/cuda_rng.cc
                                   #./tensorflow/stream_executor/cuda/cuda_stream.cc
                                   #./tensorflow/stream_executor/cuda/cuda_timer.cc
                                   ./tensorflow/stream_executor/lib/demangle.cc
                                   ./tensorflow/stream_executor/lib/numbers.cc
                                   ./tensorflow/stream_executor/lib/path.cc
                                   ./tensorflow/stream_executor/lib/process_state.cc
                                   ./tensorflow/stream_executor/blas.cc
                                   ./tensorflow/stream_executor/device_description.cc
                                   ./tensorflow/stream_executor/dnn.cc
                                   ./tensorflow/stream_executor/dso_loader.cc
                                   ./tensorflow/stream_executor/event.cc
                                   ./tensorflow/stream_executor/executor_cache.cc
                                   ./tensorflow/stream_executor/gcuda.cc
                                   ./tensorflow/stream_executor/kernel.cc
                                   ./tensorflow/stream_executor/kernel_spec.cc
                                   ./tensorflow/stream_executor/machine_manager.cc
                                   ./tensorflow/stream_executor/multi_platform_manager.cc
                                   ./tensorflow/stream_executor/platform.cc
                                   ./tensorflow/stream_executor/plugin.cc
                                   ./tensorflow/stream_executor/plugin_registry.cc
                                   ./tensorflow/stream_executor/rng.cc
                                   ./tensorflow/stream_executor/scratch_allocator.cc
                                   ./tensorflow/stream_executor/stream.cc
                                   ./tensorflow/stream_executor/stream_executor_internal.cc
                                   ./tensorflow/stream_executor/stream_executor_pimpl.cc
                                   ./tensorflow/stream_executor/temporary_device_memory.cc
                                   ./tensorflow/stream_executor/temporary_memory_manager.cc
                                   ./tensorflow/stream_executor/timer.cc)
add_library(tensorflowStreamExecutor STATIC ${TENSORFLOW_STREAM_EXECUTOR_SRC})

set(TENSORFLOW_PYTHON_CLIENT_SRC ./tensorflow/python/client/test_construction_fails_op.cc
                                 ./tensorflow/python/client/tf_session_helper.cc)
add_library(tensorflowPythonClient STATIC ${TENSORFLOW_PYTHON_CLIENT_SRC})

set(TENSORFLOW_PYTHON_FRAMEWORK_SRC ./tensorflow/python/framework/python_op_gen.cc)
add_library(tensorflowPythonFramework STATIC ${TENSORFLOW_PYTHON_FRAMEWORK_SRC})

set(TENSORFLOW_PYTHON_LIB_SRC ./tensorflow/python/lib/core/py_func.cc
                              ./tensorflow/python/lib/core/numpy.cc
                              ./tensorflow/python/lib/io/py_record_reader.cc
                              ./tensorflow/python/lib/io/py_record_writer.cc)
add_library(tensorflowPythonLib STATIC ${TENSORFLOW_PYTHON_LIB_SRC})

#set(TENSORFLOW_CONTRIB_LINEAR_OPTIMIZER_SRC ./tensorflow/contrib/linear_optimizer/kernels/sdca_ops.cc
#                                            ./tensorflow/contrib/linear_optimizer/kernels/resources.cc
#                                            ./tensorflow/contrib/linear_optimizer/ops/sdca_ops.cc)
#add_library(tensorflowContribLinearOptimizer OBJECT ${TENSORFLOW_CONTRIB_LINEAR_OPTIMIZER_SRC})

#set(TENSORFLOW_CONTRIB_QUANTIZATION_SRC ./tensorflow/contrib/quantization/kernels/dequantize_op.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantized_activation_ops.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantized_batch_norm_op.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantized_bias_add_op.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantized_concat_op.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantized_conv_ops.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantized_matmul_op.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantized_pooling_ops.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantize_down_and_shrink_range.cc
#                                        ./tensorflow/contrib/quantization/kernels/quantize_op.cc)
#add_library(tensorflowContribQuantization OBJECT ${TENSORFLOW_CONTRIB_QUANTIZATION_SRC})

set(TENSORFLOW_MODELS_EMBEDDING_SRC ./tensorflow/models/embedding/word2vec_kernels.cc
                                    ./tensorflow/models/embedding/word2vec_ops.cc)
add_library(tensorflowModelsEmbedding OBJECT ${TENSORFLOW_MODELS_EMBEDDING_SRC})

option(BUILD_PYTHON_OPS "Whether to build python wrappers for tensorflow operations" OFF)

if(BUILD_PYTHON_OPS)

  set(TENSORFLOW_PYTHON_OPS_GEN ./tensorflow/python/framework/python_op_gen_main.cc)
  add_library(tensorflowPythonOpsGen OBJECT ${TENSORFLOW_PYTHON_OPS_GEN})
  
  set(TENSORFLOW_PYTHON_OPS_GEN_LIB tensorflowPythonFramework
                                    tensorflowCoreFramework
                                    tensorflowCoreLib
									tensorflowCorePlatform
									tensorflowCoreUtil
									libprotobuf)

  add_executable(gen_array_ops_py_wrappers_cc ./tensorflow/core/ops/array_ops.cc
                                              $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_array_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_candidate_sampling_ops_py_wrappers_cc ./tensorflow/core/ops/candidate_sampling_ops.cc
                                                           $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_candidate_sampling_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_control_flow_ops_py_wrappers_cc ./tensorflow/core/ops/control_flow_ops.cc
                                                     ./tensorflow/core/ops/no_op.cc
                                                     $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_control_flow_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_ctc_ops_py_wrappers_cc ./tensorflow/core/ops/ctc_ops.cc
                                            $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_ctc_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_data_flow_ops_py_wrappers_cc ./tensorflow/core/ops/data_flow_ops.cc
                                                  $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_data_flow_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_functional_ops_py_wrappers_cc ./tensorflow/core/ops/functional_ops.cc
                                                   $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_functional_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_image_ops_py_wrappers_cc ./tensorflow/core/ops/image_ops.cc
                                              $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_image_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_io_ops_py_wrappers_cc ./tensorflow/core/ops/io_ops.cc
                                           $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_io_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_linalg_ops_py_wrappers_cc ./tensorflow/core/ops/linalg_ops.cc
                                               $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_linalg_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_logging_ops_py_wrappers_cc ./tensorflow/core/ops/logging_ops.cc
                                                $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_logging_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_math_ops_py_wrappers_cc ./tensorflow/core/ops/math_ops.cc
                                             $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_math_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_nn_ops_py_wrappers_cc ./tensorflow/core/ops/nn_ops.cc
                                           $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_nn_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_parsing_ops_py_wrappers_cc ./tensorflow/core/ops/parsing_ops.cc
                                                $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_parsing_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_random_ops_py_wrappers_cc ./tensorflow/core/ops/random_ops.cc
                                               $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_random_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_script_ops_py_wrappers_cc ./tensorflow/core/ops/script_ops.cc
                                               $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_script_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_sparse_ops_py_wrappers_cc ./tensorflow/core/ops/sparse_ops.cc
                                               $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_sparse_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_state_ops_py_wrappers_cc ./tensorflow/core/ops/state_ops.cc
                                              $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_state_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_string_ops_py_wrappers_cc ./tensorflow/core/ops/string_ops.cc
                                               $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_string_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_training_ops_py_wrappers_cc ./tensorflow/core/ops/training_ops.cc
                                                 $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_training_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_user_ops_py_wrappers_cc ./tensorflow/core/user_ops/fact.cc
                                             $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_user_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

#  add_executable(gen_sdca_ops_py_wrappers_cc $<TARGET_OBJECTS:tensorflowContribLinearOptimizer>
#                                             $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
#  target_link_libraries(gen_sdca_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})
  
#  add_executable(gen_quantization_array_ops_py_wrappers_cc ./tensorflow/contrib/quantization/ops/array_ops.cc
#                                                           $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
#  target_link_libraries(gen_quantization_array_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})
  
#  add_executable(gen_quantization_math_ops_py_wrappers_cc ./tensorflow/contrib/quantization/ops/math_ops.cc
#                                                          $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
#  target_link_libraries(gen_quantization_math_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})
  
#  add_executable(gen_quantization_nn_ops_py_wrappers_cc ./tensorflow/contrib/quantization/ops/nn_ops.cc
#                                                        $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
#  target_link_libraries(gen_quantization_nn_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

  add_executable(gen_word2vec_ops_py_wrappers_cc $<TARGET_OBJECTS:tensorflowModelsEmbedding>
                                                 $<TARGET_OBJECTS:tensorflowPythonOpsGen>)
  target_link_libraries(gen_word2vec_ops_py_wrappers_cc ${TENSORFLOW_PYTHON_OPS_GEN_LIB})

endif()

add_library(_pywrap_tensorflow SHARED ./tensorflow/python/pywrap_tensorflow.cc
                                      $<TARGET_OBJECTS:tensorflowCoreCpu>
                                      $<TARGET_OBJECTS:tensorflowCoreKernels>
                                      $<TARGET_OBJECTS:tensorflowCoreOps>
									  $<TARGET_OBJECTS:tensorflowCoreRpc>
                                      $<TARGET_OBJECTS:tensorflowCoreUserOps>
									  $<TARGET_OBJECTS:tensorflowModelsEmbedding>)
target_link_libraries(_pywrap_tensorflow tensorflowPythonClient
                                         tensorflowPythonFramework
                                         tensorflowPythonLib
										 tensorflowCoreClient
                                         tensorflowCoreCommonRuntime
                                         tensorflowCoreDistributedRuntime
                                         tensorflowCoreExample
                                         tensorflowCoreFramework
                                         tensorflowCoreGraph
										 tensorflowCoreLib Shlwapi
										 tensorflowCorePlatform
										 tensorflowCoreProtobuf
										 tensorflowCoreUtil
										 tensorflowStreamExecutor
										 posix Psapi
										 grpc++ grpc gpr libeay32 ssleay32 Ws2_32
										 jpeg
										 libpng12_static
										 libprotobuf
										 re2
										 zlibstatic)

if(BUILD_UNIT_TESTS)

  set(TENSORFLOW_TEST_MAIN_SRC ./tensorflow/core/platform/test_main.cc)
  add_library(tensorflowTestMain OBJECT ${TENSORFLOW_TEST_MAIN_SRC})

  set(TENSORFLOW_TEST_LIB_SRC ./tensorflow/core/common_runtime/kernel_benchmark_testlib.cc
                              ./tensorflow/core/framework/fake_input.cc
                              ./tensorflow/core/framework/function_testlib.cc
                              ./tensorflow/core/framework/tensor_testutil.cc
                              ./tensorflow/core/graph/testlib.cc
                              ./tensorflow/core/platform/default/test_benchmark.cc
							  ./tensorflow/core/platform/posix/test.cc
							  ./tensorflow/core/platform/test.cc
                              ./tensorflow/core/util/reporter.cc
                              ./tensorflow/core/util/test_log.pb.cc)
  add_library(tensorflowTestLib STATIC ${TENSORFLOW_TEST_LIB_SRC})

  set(TENSORFLOW_CORE_LIB_TEST_SRC ./tensorflow/core/lib/core/arena_test.cc
                                   ./tensorflow/core/lib/core/bit_cast_test.cc
                                   ./tensorflow/core/lib/core/blocking_counter_test.cc
                                   ./tensorflow/core/lib/core/coding_test.cc
                                   ./tensorflow/core/lib/core/notification_test.cc
                                   ./tensorflow/core/lib/core/refcount_test.cc
                                   ./tensorflow/core/lib/core/status_test.cc
                                   ./tensorflow/core/lib/core/stringpiece_test.cc
                                   ./tensorflow/core/lib/core/threadpool_test.cc
                                   ./tensorflow/core/lib/gtl/array_slice_test.cc
                                   ./tensorflow/core/lib/gtl/edit_distance_test.cc
                                   ./tensorflow/core/lib/gtl/inlined_vector_test.cc
                                   ./tensorflow/core/lib/gtl/int_type_test.cc
                                   ./tensorflow/core/lib/gtl/iterator_range_test.cc
                                   ./tensorflow/core/lib/gtl/manual_constructor_test.cc
                                   ./tensorflow/core/lib/gtl/map_util_test.cc
                                   ./tensorflow/core/lib/gtl/top_n_test.cc
                                   ./tensorflow/core/lib/hash/crc32c_test.cc
                                   ./tensorflow/core/lib/hash/hash_test.cc
                                   ./tensorflow/core/lib/histogram/histogram_test.cc
                                   ./tensorflow/core/lib/io/inputbuffer_test.cc
                                   ./tensorflow/core/lib/io/match_test.cc
                                   ./tensorflow/core/lib/io/path_test.cc
                                   ./tensorflow/core/lib/io/recordio_test.cc
                                   ./tensorflow/core/lib/io/record_reader.cc
                                   ./tensorflow/core/lib/io/record_writer.cc
                                   ./tensorflow/core/lib/io/table_test.cc
                                   ./tensorflow/core/lib/jpeg/jpeg_mem_unittest.cc
                                   ./tensorflow/core/lib/random/distribution_sampler_test.cc
                                   ./tensorflow/core/lib/random/philox_random_test.cc
                                   ./tensorflow/core/lib/random/random_distributions_test.cc
                                   ./tensorflow/core/lib/random/random_test.cc
                                   ./tensorflow/core/lib/random/simple_philox_test.cc
                                   ./tensorflow/core/lib/random/weighted_picker_test.cc
                                   ./tensorflow/core/lib/strings/numbers_test.cc
                                   ./tensorflow/core/lib/strings/ordered_code_test.cc
                                   ./tensorflow/core/lib/strings/scanner_test.cc
                                   ./tensorflow/core/lib/strings/strcat_test.cc
                                   ./tensorflow/core/lib/strings/stringprintf_test.cc
                                   ./tensorflow/core/lib/strings/str_util_test.cc
                                   ./tensorflow/core/lib/wav/wav_io_test.cc)
  add_executable(tensorflowCoreLibTest ${TENSORFLOW_CORE_LIB_TEST_SRC}
                                       $<TARGET_OBJECTS:tensorflowTestMain>)
  target_link_libraries(tensorflowCoreLibTest tensorflowTestLib
											  tensorflowCoreFramework
                                              tensorflowCoreLib Shlwapi
											  tensorflowCorePlatform
											  posix Psapi
											  gtest
										      jpeg
										      libprotobuf
										      re2)

  set(TENSORFLOW_CORE_PLATFORM_TEST_SRC ./tensorflow/core/platform/env_test.cc
                                        ./tensorflow/core/platform/integral_types_test.cc
                                        ./tensorflow/core/platform/logging_test.cc
                                        ./tensorflow/core/platform/port_test.cc)
  add_executable(tensorflowCorePlatformTest ${TENSORFLOW_CORE_PLATFORM_TEST_SRC}
                                            $<TARGET_OBJECTS:tensorflowTestMain>)
  target_link_libraries(tensorflowCorePlatformTest tensorflowTestLib
                                                   tensorflowCoreLib Shlwapi
                                                   tensorflowCorePlatform
											       posix Psapi
											       gtest
										           libprotobuf
										           re2)

  if(BUILD_PROTO_TEXT)
  
    set(TENSORFLOW_TOOLS_PROTO_TEXT_TEST_SRC ./tensorflow/tools/proto_text/gen_proto_text_functions_lib_test.cc
                                             ./tensorflow/tools/proto_text/test.pb.cc
                                             ./tensorflow/tools/proto_text/test.pb_text.cc)
    add_executable(tensorflowToolsProtoTextTest ${TENSORFLOW_TOOLS_PROTO_TEXT_TEST_SRC}
                                                $<TARGET_OBJECTS:tensorflowTestMain>)
    target_link_libraries(tensorflowToolsProtoTextTest tensorflowTestLib
                                                       tensorflowToolsProtoText
                                                       tensorflowCoreLib
                                                       tensorflowCorePlatform
											           posix Psapi
											           gtest
										               libprotobuf
										               re2)

  endif()

  set(TENSORFLOW_CORE_COMMON_RUNTIME_TEST_SRC ./tensorflow/core/common_runtime/constant_folding_test.cc
                                              ./tensorflow/core/common_runtime/device_set_test.cc
                                              ./tensorflow/core/common_runtime/direct_session_test.cc
                                              ./tensorflow/core/common_runtime/direct_session_with_tracking_alloc_test.cc
                                              ./tensorflow/core/common_runtime/function_test.cc
                                              ./tensorflow/core/common_runtime/gpu/gpu_allocator_retry_test.cc
                                              ./tensorflow/core/common_runtime/gpu/gpu_bfc_allocator_test.cc
                                              ./tensorflow/core/common_runtime/gpu/gpu_debug_allocator_test.cc
                                              ./tensorflow/core/common_runtime/gpu/gpu_event_mgr_test.cc
                                              ./tensorflow/core/common_runtime/gpu/gpu_stream_util_test.cc
                                              ./tensorflow/core/common_runtime/gpu/gpu_tracer_test.cc
                                              ./tensorflow/core/common_runtime/gpu/pool_allocator_test.cc
                                              ./tensorflow/core/common_runtime/memory_types_test.cc
                                              ./tensorflow/core/common_runtime/pending_counts_test.cc
                                              ./tensorflow/core/common_runtime/session_test.cc
                                              ./tensorflow/core/common_runtime/simple_placer_test.cc)
  add_executable(tensorflowCoreCommonRuntimeTest ${TENSORFLOW_CORE_COMMON_RUNTIME_TEST_SRC}
                                                 $<TARGET_OBJECTS:tensorflowCoreCpu>
                                                 $<TARGET_OBJECTS:tensorflowCoreKernels>
                                                 $<TARGET_OBJECTS:tensorflowCoreOps>
                                                 $<TARGET_OBJECTS:tensorflowCoreUserOps>
                                                 $<TARGET_OBJECTS:tensorflowTestMain>)
  target_link_libraries(tensorflowCoreCommonRuntimeTest tensorflowTestLib
                                                        tensorflowCcOps
                                                        tensorflowCoreCommonRuntime
                                                        tensorflowCoreGraph
                                                        tensorflowCoreFramework
                                                        tensorflowCoreLib Shlwapi
                                                        tensorflowCorePlatform
                                                        tensorflowCoreProtobuf
                                                        tensorflowCoreUtil
											            posix Psapi
                                                        gtest
										                jpeg
										                libpng12_static
										                libprotobuf
														re2
													    zlibstatic)

  set(TENSORFLOW_CORE_EXAMPLE_TEST_SRC ./tensorflow/core/example/feature_util_test)
  add_executable(tensorflowCoreExampleTest ${TENSORFLOW_CORE_EXAMPLE_TEST_SRC}
                                           $<TARGET_OBJECTS:tensorflowTestMain>)
  target_link_libraries(tensorflowCoreExampleTest tensorflowTestLib
                                                  tensorflowCoreExample
                                                  tensorflowCoreLib
                                                  tensorflowCorePlatform
											      posix Psapi
                                                  gtest
										          libprotobuf
											      re2)

  set(TENSORFLOW_CORE_FRAMEWORK_TEST_SRC ./tensorflow/core/framework/allocator_test.cc
                                         ./tensorflow/core/framework/attr_value_util_test.cc
                                         ./tensorflow/core/framework/bfloat16_test.cc
                                         ./tensorflow/core/framework/cancellation_test.cc
                                         ./tensorflow/core/framework/function_test.cc
                                         ./tensorflow/core/framework/graph_def_util_test.cc
                                         ./tensorflow/core/framework/kernel_def_builder_test.cc
                                         ./tensorflow/core/framework/memory_types_test.cc
                                         ./tensorflow/core/framework/node_def_builder_test.cc
                                         ./tensorflow/core/framework/node_def_util_test.cc
                                         ./tensorflow/core/framework/op_compatibility_test.cc
                                         ./tensorflow/core/framework/op_def_builder_test.cc
                                         ./tensorflow/core/framework/op_def_util_test.cc
                                         ./tensorflow/core/framework/op_kernel_test.cc
                                         ./tensorflow/core/framework/op_segment_test.cc
                                         ./tensorflow/core/framework/partial_tensor_shape_test.cc
                                         ./tensorflow/core/framework/rendezvous_test.cc
                                         ./tensorflow/core/framework/resource_mgr_test.cc
                                         ./tensorflow/core/framework/tensor_shape_test.cc
                                         ./tensorflow/core/framework/tensor_slice_test.cc
                                         ./tensorflow/core/framework/tensor_test.cc
                                         ./tensorflow/core/framework/tensor_util_test.cc
                                         ./tensorflow/core/framework/tracking_allocator_test.cc
                                         ./tensorflow/core/framework/types_test.cc
                                         ./tensorflow/core/framework/unique_tensor_references_test.cc)
  add_executable(tensorflowCoreFrameworkTest ${TENSORFLOW_CORE_FRAMEWORK_TEST_SRC}
                                             $<TARGET_OBJECTS:tensorflowCoreCpu>
                                             $<TARGET_OBJECTS:tensorflowCoreKernels>
                                             $<TARGET_OBJECTS:tensorflowCoreOps>
                                             $<TARGET_OBJECTS:tensorflowTestMain>)
  target_link_libraries(tensorflowCoreFrameworkTest tensorflowTestLib
                                                    tensorflowCoreCommonRuntime
                                                    tensorflowCoreFramework
                                                    tensorflowCoreGraph
                                                    tensorflowCoreLib Shlwapi
                                                    tensorflowCorePlatform
                                                    tensorflowCoreProtobuf
                                                    tensorflowCoreUtil
											        posix Psapi
                                                    gtest
										            jpeg
										            libpng12_static
										            libprotobuf
											        re2
													zlibstatic)

  set(TENSORFLOW_CORE_GRAPH_TEST_SRC ./tensorflow/core/graph/algorithm_test.cc
                                     ./tensorflow/core/graph/edgeset_test.cc
                                     ./tensorflow/core/graph/equal_graph_def_test.cc
                                     ./tensorflow/core/graph/graph_constructor_test.cc
                                     ./tensorflow/core/graph/graph_def_builder_test.cc
                                     ./tensorflow/core/graph/graph_partition_test.cc
                                     ./tensorflow/core/graph/graph_test.cc
                                     ./tensorflow/core/graph/node_builder_test.cc
                                     ./tensorflow/core/graph/optimizer_cse_test.cc
                                     ./tensorflow/core/graph/subgraph_test.cc
                                     ./tensorflow/core/graph/tensor_id_test.cc
                                     ./tensorflow/core/graph/validate_test.cc)
  add_executable(tensorflowCoreGraphTest ${TENSORFLOW_CORE_GRAPH_TEST_SRC}
                                         $<TARGET_OBJECTS:tensorflowCoreCpu>
                                         $<TARGET_OBJECTS:tensorflowCoreKernels>
                                         $<TARGET_OBJECTS:tensorflowCoreOps>
                                         $<TARGET_OBJECTS:tensorflowCoreUserOps>
                                         $<TARGET_OBJECTS:tensorflowTestMain>)
  target_link_libraries(tensorflowCoreGraphTest tensorflowTestLib
                                                tensorflowCcOps
                                                tensorflowCoreCommonRuntime
                                                tensorflowCoreFramework
                                                tensorflowCoreGraph
                                                tensorflowCoreLib Shlwapi
                                                tensorflowCorePlatform
                                                tensorflowCoreProtobuf
                                                tensorflowCoreUtil
											    posix Psapi
                                                gtest
										        jpeg
										        libpng12_static
										        libprotobuf
											    re2
												zlibstatic)

  set(TENSORFLOW_CORE_UTIL_TEST_SRC ./tensorflow/core/util/bcast_test.cc
                                    ./tensorflow/core/util/command_line_flags_test.cc
                                    ./tensorflow/core/util/ctc/ctc_beam_search_test.cc
                                    ./tensorflow/core/util/device_name_utils_test.cc
                                    ./tensorflow/core/util/events_writer_test.cc
                                    ./tensorflow/core/util/example_proto_helper_test.cc
                                   #./tensorflow/core/util/memmapped_file_system_test.cc
                                    ./tensorflow/core/util/reporter_test.cc
                                    ./tensorflow/core/util/saved_tensor_slice_util_test.cc
                                    ./tensorflow/core/util/sparse/sparse_tensor_test.cc
                                    ./tensorflow/core/util/tensor_slice_reader_test.cc
                                    ./tensorflow/core/util/tensor_slice_set_test.cc
                                    ./tensorflow/core/util/tensor_slice_util_test.cc
                                    ./tensorflow/core/util/tensor_slice_writer_test.cc
                                    ./tensorflow/core/util/work_sharder_test.cc)
  add_executable(tensorflowCoreUtilTest ${TENSORFLOW_CORE_UTIL_TEST_SRC}
                                        $<TARGET_OBJECTS:tensorflowTestMain>)
  target_link_libraries(tensorflowCoreUtilTest tensorflowTestLib
                                               tensorflowCoreExample
                                               tensorflowCoreFramework
                                               tensorflowCoreLib Shlwapi
                                               tensorflowCorePlatform
                                               tensorflowCoreProtobuf
                                               tensorflowCoreUtil
											   posix Psapi
                                               gtest
										       libprotobuf
											   re2)

endif()