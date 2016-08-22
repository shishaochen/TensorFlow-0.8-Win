// This file is MACHINE GENERATED! Do not edit.

#ifndef TENSORFLOW_CC_OPS_NN_OPS_H_
#define TENSORFLOW_CC_OPS_NN_OPS_H_

#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/graph/graph_def_builder.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

// These add a node to the graph from opts.
//
// Note for "NodeOut" inputs, you will typically either pass
// * a {Node*, int index} (to pass the index-th output of that node), or
// * a Node* (to pass the first output of that node).


// Performs average pooling on the input.
//
// Each entry in `output` is the mean of the corresponding size `ksize`
// window in `value`.
//
// Arguments:
// * value: 4-D with shape `[batch, height, width, channels]`.
// * ksize: The size of the sliding window for each dimension of `value`.
// * strides: The stride of the sliding window for each dimension of `value`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the data is stored in the order of:
//     [batch, in_height, in_width, in_channels].
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The average pooled output tensor.
Node* AvgPool(NodeOut value, gtl::ArraySlice<int> ksize, gtl::ArraySlice<int>
              strides, StringPiece padding, const GraphDefBuilder::Options&
              opts);

// Performs 3D average pooling on the input.
//
// Arguments:
// * input: Shape `[batch, depth, rows, cols, channels]` tensor to pool over.
// * ksize: 1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[1] = 1`.
// * strides: 1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The average pooled output tensor.
Node* AvgPool3D(NodeOut input, gtl::ArraySlice<int> ksize, gtl::ArraySlice<int>
                strides, StringPiece padding, const GraphDefBuilder::Options&
                opts);

// Computes gradients of average pooling function.
//
// Arguments:
// * orig_input_shape: The original input dimensions.
// * grad: Output backprop of shape `[batch, depth, rows, cols, channels]`.
// * ksize: 1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[1] = 1`.
// * strides: 1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The backprop for input.
Node* AvgPool3DGrad(NodeOut orig_input_shape, NodeOut grad,
                    gtl::ArraySlice<int> ksize, gtl::ArraySlice<int> strides,
                    StringPiece padding, const GraphDefBuilder::Options& opts);

// Computes gradients of the average pooling function.
//
// Arguments:
// * orig_input_shape: 1-D.  Shape of the original input to `avg_pool`.
// * grad: 4-D with shape `[batch, height, width, channels]`.  Gradients w.r.t.
// the output of `avg_pool`.
// * ksize: The size of the sliding window for each dimension of the input.
// * strides: The stride of the sliding window for each dimension of the input.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the data is stored in the order of:
//     [batch, in_height, in_width, in_channels].
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// 4-D.  Gradients w.r.t. the input of `avg_pool`.
Node* AvgPoolGrad(NodeOut orig_input_shape, NodeOut grad, gtl::ArraySlice<int>
                  ksize, gtl::ArraySlice<int> strides, StringPiece padding,
                  const GraphDefBuilder::Options& opts);

// Batch normalization.
//
// DEPRECATED at GraphDef version 9:
// Use tf.nn.batch_normalization().
//
// This op is deprecated. Prefer `tf.nn.batch_normalization`.
//
// Arguments:
// * t: A 4D input Tensor.
// * m: A 1D mean Tensor with size matching the last dimension of t.
// This is the first output from tf.nn.moments,
// or a saved moving average thereof.
// * v: A 1D variance Tensor with size matching the last dimension of t.
// This is the second output from tf.nn.moments,
// or a saved moving average thereof.
// * beta: A 1D beta Tensor with size matching the last dimension of t.
// An offset to be added to the normalized tensor.
// * gamma: A 1D gamma Tensor with size matching the last dimension of t.
// If "scale_after_normalization" is true, this tensor will be multiplied
// with the normalized tensor.
// * variance_epsilon: A small float number to avoid dividing by 0.
// * scale_after_normalization: A bool indicating whether the resulted tensor
// needs to be multiplied with gamma.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* BatchNormWithGlobalNormalization(NodeOut t, NodeOut m, NodeOut v, NodeOut
                                       beta, NodeOut gamma, float
                                       variance_epsilon, bool
                                       scale_after_normalization, const
                                       GraphDefBuilder::Options& opts);

// Gradients for batch normalization.
//
// DEPRECATED at GraphDef version 9:
// Use tf.nn.batch_normalization().
//
// This op is deprecated. See `tf.nn.batch_normalization`.
//
// Arguments:
// * t: A 4D input Tensor.
// * m: A 1D mean Tensor with size matching the last dimension of t.
// This is the first output from tf.nn.moments,
// or a saved moving average thereof.
// * v: A 1D variance Tensor with size matching the last dimension of t.
// This is the second output from tf.nn.moments,
// or a saved moving average thereof.
// * gamma: A 1D gamma Tensor with size matching the last dimension of t.
// If "scale_after_normalization" is true, this Tensor will be multiplied
// with the normalized Tensor.
// * backprop: 4D backprop Tensor.
// * variance_epsilon: A small float number to avoid dividing by 0.
// * scale_after_normalization: A bool indicating whether the resulted tensor
// needs to be multiplied with gamma.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with outputs:
// * dx: 4D backprop tensor for input.
// * dm: 1D backprop tensor for mean.
// * dv: 1D backprop tensor for variance.
// * db: 1D backprop tensor for beta.
// * dg: 1D backprop tensor for gamma.
Node* BatchNormWithGlobalNormalizationGrad(NodeOut t, NodeOut m, NodeOut v,
                                           NodeOut gamma, NodeOut backprop,
                                           float variance_epsilon, bool
                                           scale_after_normalization, const
                                           GraphDefBuilder::Options& opts);

// Adds `bias` to `value`.
//
// This is a special case of `tf.add` where `bias` is restricted to be 1-D.
// Broadcasting is supported, so `value` may have any number of dimensions.
//
// Arguments:
// * value: Any number of dimensions.
// * bias: 1-D with size the last dimension of `value`.
// * opts:
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the bias tensor will be added to the last dimension
// of the value tensor.
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
// The tensor will be added to "in_channels", the third-to-the-last
//     dimension.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Broadcasted sum of `value` and `bias`.
Node* BiasAdd(NodeOut value, NodeOut bias, const GraphDefBuilder::Options&
              opts);

// The backward operation for "BiasAdd" on the "bias" tensor.
//
// It accumulates all the values from out_backprop into the feature dimension.
// For NHWC data format, the feature dimension is the last. For NCHW data format,
// the feature dimension is the third-to-last.
//
// Arguments:
// * out_backprop: Any number of dimensions.
// * opts:
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the bias tensor will be added to the last dimension
// of the value tensor.
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
// The tensor will be added to "in_channels", the third-to-the-last
//     dimension.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// 1-D with size the feature dimension of `out_backprop`.
Node* BiasAddGrad(NodeOut out_backprop, const GraphDefBuilder::Options& opts);

// Adds `bias` to `value`.
//
// This is a deprecated version of BiasAdd and will be soon removed.
//
// This is a special case of `tf.add` where `bias` is restricted to be 1-D.
// Broadcasting is supported, so `value` may have any number of dimensions.
//
// Arguments:
// * value: Any number of dimensions.
// * bias: 1-D with size the last dimension of `value`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Broadcasted sum of `value` and `bias`.
Node* BiasAddV1(NodeOut value, NodeOut bias, const GraphDefBuilder::Options&
                opts);

// Computes a 2-D convolution given 4-D `input` and `filter` tensors.
//
// Given an input tensor of shape `[batch, in_height, in_width, in_channels]`
// and a filter / kernel tensor of shape
// `[filter_height, filter_width, in_channels, out_channels]`, this op
// performs the following:
//
// 1. Flattens the filter to a 2-D matrix with shape
//    `[filter_height * filter_width * in_channels, output_channels]`.
// 2. Extracts image patches from the input tensor to form a *virtual*
//    tensor of shape `[batch, out_height, out_width,
//    filter_height * filter_width * in_channels]`.
// 3. For each patch, right-multiplies the filter matrix and the image patch
//    vector.
//
// In detail, with the default NHWC format,
//
//     output[b, i, j, k] =
//         sum_{di, dj, q} input[b, strides[1] * i + di, strides[2] * j + dj, q] *
//                         filter[di, dj, q, k]
//
// Must have `strides[0] = strides[3] = 1`.  For the most common case of the same
// horizontal and vertices strides, `strides = [1, stride, stride, 1]`.
//
// Arguments:
// * strides: 1-D of length 4.  The stride of the sliding window for each dimension
// of `input`. Must be in the same order as the dimension specified with format.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("use_cudnn_on_gpu", bool): Defaults to true.
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the data is stored in the order of:
//     [batch, in_height, in_width, in_channels].
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Conv2D(NodeOut input, NodeOut filter, gtl::ArraySlice<int> strides,
             StringPiece padding, const GraphDefBuilder::Options& opts);

// Computes the gradients of convolution with respect to the filter.
//
// Arguments:
// * input: 4-D with shape `[batch, in_height, in_width, in_channels]`.
// * filter_sizes: An integer vector representing the tensor shape of `filter`,
// where `filter` is a 4-D
// `[filter_height, filter_width, in_channels, out_channels]` tensor.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides: The stride of the sliding window for each dimension of the input
// of the convolution. Must be in the same order as the dimension specified with
// format.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("use_cudnn_on_gpu", bool): Defaults to true.
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the data is stored in the order of:
//     [batch, in_height, in_width, in_channels].
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// 4-D with shape
// `[filter_height, filter_width, in_channels, out_channels]`.  Gradient w.r.t.
// the `filter` input of the convolution.
Node* Conv2DBackpropFilter(NodeOut input, NodeOut filter_sizes, NodeOut
                           out_backprop, gtl::ArraySlice<int> strides,
                           StringPiece padding, const GraphDefBuilder::Options&
                           opts);

// Computes the gradients of convolution with respect to the input.
//
// Arguments:
// * input_sizes: An integer vector representing the shape of `input`,
// where `input` is a 4-D `[batch, height, width, channels]` tensor.
// * filter: 4-D with shape
// `[filter_height, filter_width, in_channels, out_channels]`.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides: The stride of the sliding window for each dimension of the input
// of the convolution. Must be in the same order as the dimension specified with
// format.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("use_cudnn_on_gpu", bool): Defaults to true.
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the data is stored in the order of:
//     [batch, in_height, in_width, in_channels].
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// 4-D with shape `[batch, in_height, in_width, in_channels]`.  Gradient
// w.r.t. the input of the convolution.
Node* Conv2DBackpropInput(NodeOut input_sizes, NodeOut filter, NodeOut
                          out_backprop, gtl::ArraySlice<int> strides,
                          StringPiece padding, const GraphDefBuilder::Options&
                          opts);

// Computes a 3-D convolution given 5-D `input` and `filter` tensors.
//
// In signal processing, cross-correlation is a measure of similarity of
// two waveforms as a function of a time-lag applied to one of them. This
// is also known as a sliding dot product or sliding inner-product.
//
// Our Conv3D implements a form of cross-correlation.
//
// Arguments:
// * input: Shape `[batch, in_depth, in_height, in_width, in_channels]`.
// * filter: Shape `[filter_depth, filter_height, filter_width, in_channels, out_channels]`.
// `in_channels` must match between `input` and `filter`.
// * strides: 1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Conv3D(NodeOut input, NodeOut filter, gtl::ArraySlice<int> strides,
             StringPiece padding, const GraphDefBuilder::Options& opts);

// Computes the gradients of 3D convolution with respect to the filter.
//
// Arguments:
// * input: Shape `[batch, depth, rows, cols, in_channels]`.
// * filter: Shape `[depth, rows, cols, in_channels, out_channels]`.
// `in_channels` must match between `input` and `filter`.
// * out_backprop: Backprop signal of shape `[batch, out_depth, out_rows, out_cols, out_channels]`.
// * strides: 1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Conv3DBackpropFilter(NodeOut input, NodeOut filter, NodeOut out_backprop,
                           gtl::ArraySlice<int> strides, StringPiece padding,
                           const GraphDefBuilder::Options& opts);

// Computes the gradients of 3D convolution with respect to the input.
//
// Arguments:
// * input: Shape `[batch, depth, rows, cols, in_channels]`.
// * filter: Shape `[depth, rows, cols, in_channels, out_channels]`.
// `in_channels` must match between `input` and `filter`.
// * out_backprop: Backprop signal of shape `[batch, out_depth, out_rows, out_cols, out_channels]`.
// * strides: 1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Conv3DBackpropInput(NodeOut input, NodeOut filter, NodeOut out_backprop,
                          gtl::ArraySlice<int> strides, StringPiece padding,
                          const GraphDefBuilder::Options& opts);

// Computes a 2-D depthwise convolution given 4-D `input` and `filter` tensors.
//
// Given an input tensor of shape `[batch, in_height, in_width, in_channels]`
// and a filter / kernel tensor of shape
// `[filter_height, filter_width, in_channels, channel_multiplier]`, containing
// `in_channels` convolutional filters of depth 1, `depthwise_conv2d` applies
// a different filter to each input channel (expanding from 1 channel to
// `channel_multiplier` channels for each), then concatenates the results
// together. Thus, the output has `in_channels * channel_multiplier` channels.
//
// for k in 0..in_channels-1
//   for q in 0..channel_multiplier-1
//     output[b, i, j, k * channel_multiplier + q] =
//       sum_{di, dj} input[b, strides[1] * i + di, strides[2] * j + dj, k] *
//                         filter[di, dj, k, q]
//
// Must have `strides[0] = strides[3] = 1`.  For the most common case of the same
// horizontal and vertices strides, `strides = [1, stride, stride, 1]`.
//
// Arguments:
// * strides: 1-D of length 4.  The stride of the sliding window for each dimension
// of `input`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* DepthwiseConv2dNative(NodeOut input, NodeOut filter, gtl::ArraySlice<int>
                            strides, StringPiece padding, const
                            GraphDefBuilder::Options& opts);

// Computes the gradients of depthwise convolution with respect to the filter.
//
// Arguments:
// * input: 4-D with shape `[batch, in_height, in_width, in_channels]`.
// * filter_sizes: An integer vector representing the tensor shape of `filter`,
// where `filter` is a 4-D
// `[filter_height, filter_width, in_channels, depthwise_multiplier]` tensor.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides: The stride of the sliding window for each dimension of the input
// of the convolution.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// 4-D with shape
// `[filter_height, filter_width, in_channels, out_channels]`.  Gradient w.r.t.
// the `filter` input of the convolution.
Node* DepthwiseConv2dNativeBackpropFilter(NodeOut input, NodeOut filter_sizes,
                                          NodeOut out_backprop,
                                          gtl::ArraySlice<int> strides,
                                          StringPiece padding, const
                                          GraphDefBuilder::Options& opts);

// Computes the gradients of depthwise convolution with respect to the input.
//
// Arguments:
// * input_sizes: An integer vector representing the shape of `input`,
// where `input` is a 4-D `[batch, height, width, channels]` tensor.
// * filter: 4-D with shape
// `[filter_height, filter_width, in_channels, depthwise_multiplier]`.
// * out_backprop: 4-D with shape `[batch, out_height, out_width, out_channels]`.
// Gradients w.r.t. the output of the convolution.
// * strides: The stride of the sliding window for each dimension of the input
// of the convolution.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// 4-D with shape `[batch, in_height, in_width, in_channels]`.  Gradient
// w.r.t. the input of the convolution.
Node* DepthwiseConv2dNativeBackpropInput(NodeOut input_sizes, NodeOut filter,
                                         NodeOut out_backprop,
                                         gtl::ArraySlice<int> strides,
                                         StringPiece padding, const
                                         GraphDefBuilder::Options& opts);

// Computes exponential linear: `exp(features) - 1` if < 0, `features` otherwise.
//
// See [Fast and Accurate Deep Network Learning by Exponential Linear Units (ELUs)
// ](http://arxiv.org/abs/1511.07289)
//
// Arguments:
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Elu(NodeOut features, const GraphDefBuilder::Options& opts);

// Computes gradients for the exponential linear (Elu) operation.
//
// Arguments:
// * gradients: The backpropagated gradients to the corresponding Elu operation.
// * outputs: The outputs of the corresponding Elu operation.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The gradients: `gradients * (outputs + 1)` if outputs < 0,
// `gradients` otherwise.
Node* EluGrad(NodeOut gradients, NodeOut outputs, const
              GraphDefBuilder::Options& opts);

// Says whether the targets are in the top `K` predictions.
//
// This outputs a `batch_size` bool array, an entry `out[i]` is `true` if the
// prediction for the target class is among the top `k` predictions among
// all predictions for example `i`. Note that the behavior of `InTopK` differs
// from the `TopK` op in its handling of ties; if multiple classes have the
// same prediction value and straddle the top-`k` boundary, all of those
// classes are considered to be in the top `k`.
//
// More formally, let
//
//   \\(predictions_i\\) be the predictions for all classes for example `i`,
//   \\(targets_i\\) be the target class for example `i`,
//   \\(out_i\\) be the output for example `i`,
//
// $$out_i = predictions_{i, targets_i} \in TopKIncludingTies(predictions_i)$$
//
// Arguments:
// * predictions: A `batch_size` x `classes` tensor.
// * targets: A `batch_size` vector of class ids.
// * k: Number of top elements to look at for computing precision.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Computed Precision at `k` as a `bool Tensor`.
Node* InTopK(NodeOut predictions, NodeOut targets, int64 k, const
             GraphDefBuilder::Options& opts);

// L2 Loss.
//
// Computes half the L2 norm of a tensor without the `sqrt`:
//
//     output = sum(t ** 2) / 2
//
// Arguments:
// * t: Typically 2-D, but may have any dimensions.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// 0-D.
Node* L2Loss(NodeOut t, const GraphDefBuilder::Options& opts);

// Local Response Normalization.
//
// The 4-D `input` tensor is treated as a 3-D array of 1-D vectors (along the last
// dimension), and each vector is normalized independently.  Within a given vector,
// each component is divided by the weighted, squared sum of inputs within
// `depth_radius`.  In detail,
//
//     sqr_sum[a, b, c, d] =
//         sum(input[a, b, c, d - depth_radius : d + depth_radius + 1] ** 2)
//     output = input / (bias + alpha * sqr_sum) ** beta
//
// For details, see [Krizhevsky et al., ImageNet classification with deep
// convolutional neural networks (NIPS 2012)]
// (http://papers.nips.cc/paper/4824-imagenet-classification-with-deep-convolutional-neural-networks).
//
// Arguments:
// * input: 4-D.
// * opts:
//   .WithAttr("depth_radius", int64): Defaults to 5.
//     0-D.  Half-width of the 1-D normalization window.
//   .WithAttr("bias", float): Defaults to 1.
//     An offset (usually positive to avoid dividing by 0).
//   .WithAttr("alpha", float): Defaults to 1.
//     A scale factor, usually positive.
//   .WithAttr("beta", float): Defaults to 0.5.
//     An exponent.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* LRN(NodeOut input, const GraphDefBuilder::Options& opts);

// Gradients for Local Response Normalization.
//
// Arguments:
// * input_grads: 4-D with shape `[batch, height, width, channels]`.
// * input_image: 4-D with shape `[batch, height, width, channels]`.
// * output_image: 4-D with shape `[batch, height, width, channels]`.
// * opts:
//   .WithAttr("depth_radius", int64): Defaults to 5.
//     A depth radius.
//   .WithAttr("bias", float): Defaults to 1.
//     An offset (usually > 0 to avoid dividing by 0).
//   .WithAttr("alpha", float): Defaults to 1.
//     A scale factor, usually positive.
//   .WithAttr("beta", float): Defaults to 0.5.
//     An exponent.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The gradients for LRN.
Node* LRNGrad(NodeOut input_grads, NodeOut input_image, NodeOut output_image,
              const GraphDefBuilder::Options& opts);

// Computes log softmax activations.
//
// For each batch `i` and class `j` we have
//
//     logsoftmax[i, j] = logits[i, j] - log(sum(exp(logits[i])))
//
// Arguments:
// * logits: 2-D with shape `[batch_size, num_classes]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Same shape as `logits`.
Node* LogSoftmax(NodeOut logits, const GraphDefBuilder::Options& opts);

// Performs max pooling on the input.
//
// Arguments:
// * input: 4-D input to pool over.
// * ksize: The size of the window for each dimension of the input tensor.
// * strides: The stride of the sliding window for each dimension of the
// input tensor.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the data is stored in the order of:
//     [batch, in_height, in_width, in_channels].
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The max pooled output tensor.
Node* MaxPool(NodeOut input, gtl::ArraySlice<int> ksize, gtl::ArraySlice<int>
              strides, StringPiece padding, const GraphDefBuilder::Options&
              opts);

// Performs 3D max pooling on the input.
//
// Arguments:
// * input: Shape `[batch, depth, rows, cols, channels]` tensor to pool over.
// * ksize: 1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[1] = 1`.
// * strides: 1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The max pooled output tensor.
Node* MaxPool3D(NodeOut input, gtl::ArraySlice<int> ksize, gtl::ArraySlice<int>
                strides, StringPiece padding, const GraphDefBuilder::Options&
                opts);

// Computes gradients of max pooling function.
//
// Arguments:
// * orig_input: The original input tensor.
// * orig_output: The original output tensor.
// * grad: Output backprop of shape `[batch, depth, rows, cols, channels]`.
// * ksize: 1-D tensor of length 5. The size of the window for each dimension of
// the input tensor. Must have `ksize[0] = ksize[1] = 1`.
// * strides: 1-D tensor of length 5. The stride of the sliding window for each
// dimension of `input`. Must have `strides[0] = strides[4] = 1`.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* MaxPool3DGrad(NodeOut orig_input, NodeOut orig_output, NodeOut grad,
                    gtl::ArraySlice<int> ksize, gtl::ArraySlice<int> strides,
                    StringPiece padding, const GraphDefBuilder::Options& opts);

// Computes gradients of the maxpooling function.
//
// Arguments:
// * orig_input: The original input tensor.
// * orig_output: The original output tensor.
// * grad: 4-D.  Gradients w.r.t. the output of `max_pool`.
// * ksize: The size of the window for each dimension of the input tensor.
// * strides: The stride of the sliding window for each dimension of the
// input tensor.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("data_format", StringPiece): Defaults to "NHWC".
//     Specify the data format of the input and output data. With the
// default format "NHWC", the data is stored in the order of:
//     [batch, in_height, in_width, in_channels].
// Alternatively, the format could be "NCHW", the data storage order of:
//     [batch, in_channels, in_height, in_width].
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Gradients w.r.t. the input to `max_pool`.
Node* MaxPoolGrad(NodeOut orig_input, NodeOut orig_output, NodeOut grad,
                  gtl::ArraySlice<int> ksize, gtl::ArraySlice<int> strides,
                  StringPiece padding, const GraphDefBuilder::Options& opts);

// Computes gradients of the maxpooling function.
//
// Arguments:
// * input: The original input.
// * grad: 4-D with shape `[batch, height, width, channels]`.  Gradients w.r.t. the
// output of `max_pool`.
// * argmax: The indices of the maximum values chosen for each output of `max_pool`.
// * ksize: The size of the window for each dimension of the input tensor.
// * strides: The stride of the sliding window for each dimension of the
// input tensor.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Gradients w.r.t. the input of `max_pool`.
Node* MaxPoolGradWithArgmax(NodeOut input, NodeOut grad, NodeOut argmax,
                            gtl::ArraySlice<int> ksize, gtl::ArraySlice<int>
                            strides, StringPiece padding, const
                            GraphDefBuilder::Options& opts);

// Performs max pooling on the input and outputs both max values and indices.
//
// The indices in `argmax` are flattened, so that a maximum value at position
// `[b, y, x, c]` becomes flattened index
// `((b * height + y) * width + x) * channels + c`.
//
// Arguments:
// * input: 4-D with shape `[batch, height, width, channels]`.  Input to pool over.
// * ksize: The size of the window for each dimension of the input tensor.
// * strides: The stride of the sliding window for each dimension of the
// input tensor.
// * padding: The type of padding algorithm to use.
// * opts:
//   .WithAttr("Targmax", DataType): Defaults to DT_INT64.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with outputs:
// * output: The max pooled output tensor.
// * argmax: 4-D.  The flattened indices of the max values chosen for each output.
Node* MaxPoolWithArgmax(NodeOut input, gtl::ArraySlice<int> ksize,
                        gtl::ArraySlice<int> strides, StringPiece padding,
                        const GraphDefBuilder::Options& opts);

// Computes rectified linear: `max(features, 0)`.
//
// Arguments:
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Relu(NodeOut features, const GraphDefBuilder::Options& opts);

// Computes rectified linear 6: `min(max(features, 0), 6)`.
//
// Arguments:
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Relu6(NodeOut features, const GraphDefBuilder::Options& opts);

// Computes rectified linear 6 gradients for a Relu6 operation.
//
// Arguments:
// * gradients: The backpropagated gradients to the corresponding Relu6 operation.
// * features: The features passed as input to the corresponding Relu6 operation.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The gradients:
// `gradients * features * (features > 0) * (features < 6)`.
Node* Relu6Grad(NodeOut gradients, NodeOut features, const
                GraphDefBuilder::Options& opts);

// Computes rectified linear gradients for a Relu operation.
//
// Arguments:
// * gradients: The backpropagated gradients to the corresponding Relu operation.
// * features: The features passed as input to the corresponding Relu operation, OR
// the outputs of that operation (both work equivalently).
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// `gradients * (features > 0)`.
Node* ReluGrad(NodeOut gradients, NodeOut features, const
               GraphDefBuilder::Options& opts);

// Computes softmax activations.
//
// For each batch `i` and class `j` we have
//
//     softmax[i, j] = exp(logits[i, j]) / sum(exp(logits[i]))
//
// Arguments:
// * logits: 2-D with shape `[batch_size, num_classes]`.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Same shape as `logits`.
Node* Softmax(NodeOut logits, const GraphDefBuilder::Options& opts);

// Computes softmax cross entropy cost and gradients to backpropagate.
//
// Inputs are the logits, not probabilities.
//
// Arguments:
// * features: batch_size x num_classes matrix
// * labels: batch_size x num_classes matrix
// The caller must ensure that each batch of labels represents a valid
// probability distribution.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with outputs:
// * loss: Per example loss (batch_size vector).
// * backprop: backpropagated gradients (batch_size x num_classes matrix).
Node* SoftmaxCrossEntropyWithLogits(NodeOut features, NodeOut labels, const
                                    GraphDefBuilder::Options& opts);

// Computes softplus: `log(exp(features) + 1)`.
//
// Arguments:
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Softplus(NodeOut features, const GraphDefBuilder::Options& opts);

// Computes softplus gradients for a softplus operation.
//
// Arguments:
// * gradients: The backpropagated gradients to the corresponding softplus operation.
// * features: The features passed as input to the corresponding softplus operation.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The gradients: `gradients / (1 + exp(-features))`.
Node* SoftplusGrad(NodeOut gradients, NodeOut features, const
                   GraphDefBuilder::Options& opts);

// Computes softsign: `features / (abs(features) + 1)`.
//
// Arguments:
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Softsign(NodeOut features, const GraphDefBuilder::Options& opts);

// Computes softsign gradients for a softsign operation.
//
// Arguments:
// * gradients: The backpropagated gradients to the corresponding softsign operation.
// * features: The features passed as input to the corresponding softsign operation.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The gradients: `gradients / (1 + abs(-features)) ** 2`.
Node* SoftsignGrad(NodeOut gradients, NodeOut features, const
                   GraphDefBuilder::Options& opts);

// Computes softmax cross entropy cost and gradients to backpropagate.
//
// Unlike `SoftmaxCrossEntropyWithLogits`, this operation does not accept
// a matrix of label probabilities, but rather a single label per row
// of features.  This label is considered to have probability 1.0 for the
// given row.
//
// Inputs are the logits, not probabilities.
//
// Arguments:
// * features: batch_size x num_classes matrix
// * labels: batch_size vector with values in [0, num_classes).
// This is the label for the given minibatch entry.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with outputs:
// * loss: Per example loss (batch_size vector).
// * backprop: backpropagated gradients (batch_size x num_classes matrix).
Node* SparseSoftmaxCrossEntropyWithLogits(NodeOut features, NodeOut labels,
                                          const GraphDefBuilder::Options&
                                          opts);

// Finds values and indices of the `k` largest elements for the last dimension.
//
// DEPRECATED at GraphDef version 7:
// Use TopKV2 instead.
//
// If the input is a vector (rank-1), finds the `k` largest entries in the vector
// and outputs their values and indices as vectors.  Thus `values[j]` is the
// `j`-th largest entry in `input`, and its index is `indices[j]`.
//
// For matrices (resp. higher rank input), computes the top `k` entries in each
// row (resp. vector along the last dimension).  Thus,
//
//     values.shape = indices.shape = input.shape[:-1] + [k]
//
// If two elements are equal, the lower-index element appears first.
//
// If `k` varies dynamically, use `TopKV2` below.
//
// Arguments:
// * input: 1-D or higher with last dimension at least `k`.
// * k: Number of top elements to look for along the last dimension (along each
// row for matrices).
// * opts:
//   .WithAttr("sorted", bool): Defaults to true.
//     If true the resulting `k` elements will be sorted by the values in
// descending order.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with outputs:
// * values: The `k` largest elements along each last dimensional slice.
// * indices: The indices of `values` within the last dimension of `input`.
Node* TopK(NodeOut input, int64 k, const GraphDefBuilder::Options& opts);

// Finds values and indices of the `k` largest elements for the last dimension.
//
// If the input is a vector (rank-1), finds the `k` largest entries in the vector
// and outputs their values and indices as vectors.  Thus `values[j]` is the
// `j`-th largest entry in `input`, and its index is `indices[j]`.
//
// For matrices (resp. higher rank input), computes the top `k` entries in each
// row (resp. vector along the last dimension).  Thus,
//
//     values.shape = indices.shape = input.shape[:-1] + [k]
//
// If two elements are equal, the lower-index element appears first.
//
// This is the same as `TopK`, but takes `k` as in input rather than an attr.
//
// Arguments:
// * input: 1-D or higher with last dimension at least `k`.
// * k: 0-D.  Number of top elements to look for along the last dimension (along each
// row for matrices).
// * opts:
//   .WithAttr("sorted", bool): Defaults to true.
//     If true the resulting `k` elements will be sorted by the values in
// descending order.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with outputs:
// * values: The `k` largest elements along each last dimensional slice.
// * indices: The indices of `values` within the last dimension of `input`.
Node* TopKV2(NodeOut input, NodeOut k, const GraphDefBuilder::Options& opts);

}  // namespace ops
}  // namespace tensorflow

#endif  // TENSORFLOW_CC_OPS_NN_OPS_H_
