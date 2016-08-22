// This file is MACHINE GENERATED! Do not edit.

#ifndef TENSORFLOW_CC_OPS_LOGGING_OPS_H_
#define TENSORFLOW_CC_OPS_LOGGING_OPS_H_

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


// Asserts that the given condition is true.
//
// If `condition` evaluates to false, print the list of tensors in `data`.
// `summarize` determines how many entries of the tensors to print.
//
// Arguments:
// * condition: The condition to evaluate.
// * data: The tensors to print out when condition is false.
// * opts:
//   .WithAttr("summarize", int64): Defaults to 3.
//     Print this many entries of each tensor.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node.
Node* Assert(NodeOut condition, gtl::ArraySlice<NodeOut> data, const
             GraphDefBuilder::Options& opts);

// Outputs a `Summary` protocol buffer with audio.
//
// The summary has up to `max_outputs` summary values containing audio. The
// audio is built from `tensor` which must be 3-D with shape `[batch_size,
// frames, channels]` or 2-D with shape `[batch_size, frames]`. The values are
// assumed to be in the range of `[-1.0, 1.0]` with a sample rate of `sample_rate`.
//
// The `tag` argument is a scalar `Tensor` of type `string`.  It is used to
// build the `tag` of the summary values:
//
// *  If `max_outputs` is 1, the summary value tag is '*tag*/audio'.
// *  If `max_outputs` is greater than 1, the summary value tags are
//    generated sequentially as '*tag*/audio/0', '*tag*/audio/1', etc.
//
// Arguments:
// * tag: Scalar. Used to build the `tag` attribute of the summary values.
// * tensor: 2-D of shape `[batch_size, frames]`.
// * sample_rate: The sample rate of the signal in hertz.
// * opts:
//   .WithAttr("max_outputs", int64): Defaults to 3.
//     Max number of batch elements to generate audio for.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Scalar. Serialized `Summary` protocol buffer.
Node* AudioSummary(NodeOut tag, NodeOut tensor, float sample_rate, const
                   GraphDefBuilder::Options& opts);

// Outputs a `Summary` protocol buffer with a histogram.
//
// The generated
// [`Summary`](https://www.tensorflow.org/code/tensorflow/core/framework/summary.proto)
// has one summary value containing a histogram for `values`.
//
// This op reports an `InvalidArgument` error if any value is not finite.
//
// Arguments:
// * tag: Scalar.  Tag to use for the `Summary.Value`.
// * values: Any shape. Values to use to build the histogram.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Scalar. Serialized `Summary` protocol buffer.
Node* HistogramSummary(NodeOut tag, NodeOut values, const
                       GraphDefBuilder::Options& opts);

// Outputs a `Summary` protocol buffer with images.
//
// The summary has up to `max_images` summary values containing images. The
// images are built from `tensor` which must be 4-D with shape `[batch_size,
// height, width, channels]` and where `channels` can be:
//
// *  1: `tensor` is interpreted as Grayscale.
// *  3: `tensor` is interpreted as RGB.
// *  4: `tensor` is interpreted as RGBA.
//
// The images have the same number of channels as the input tensor. For float
// input, the values are normalized one image at a time to fit in the range
// `[0, 255]`.  `uint8` values are unchanged.  The op uses two different
// normalization algorithms:
//
// *  If the input values are all positive, they are rescaled so the largest one
//    is 255.
//
// *  If any input value is negative, the values are shifted so input value 0.0
//    is at 127.  They are then rescaled so that either the smallest value is 0,
//    or the largest one is 255.
//
// The `tag` argument is a scalar `Tensor` of type `string`.  It is used to
// build the `tag` of the summary values:
//
// *  If `max_images` is 1, the summary value tag is '*tag*/image'.
// *  If `max_images` is greater than 1, the summary value tags are
//    generated sequentially as '*tag*/image/0', '*tag*/image/1', etc.
//
// The `bad_color` argument is the color to use in the generated images for
// non-finite input values.  It is a `unit8` 1-D tensor of length `channels`.
// Each element must be in the range `[0, 255]` (It represents the value of a
// pixel in the output image).  Non-finite values in the input tensor are
// replaced by this tensor in the output image.  The default value is the color
// red.
//
// Arguments:
// * tag: Scalar. Used to build the `tag` attribute of the summary values.
// * tensor: 4-D of shape `[batch_size, height, width, channels]` where
// `channels` is 1, 3, or 4.
// * opts:
//   .WithAttr("max_images", int64): Defaults to 3.
//     Max number of batch elements to generate images for.
//   .WithAttr("bad_color", const Tensor&): Defaults to Tensor<type: uint8 shape: [4] values: 255 0 0...>.
//     Color to use for pixels with non-finite values.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Scalar. Serialized `Summary` protocol buffer.
Node* ImageSummary(NodeOut tag, NodeOut tensor, const GraphDefBuilder::Options&
                   opts);

// Merges summaries.
//
// This op creates a
// [`Summary`](https://www.tensorflow.org/code/tensorflow/core/framework/summary.proto)
// protocol buffer that contains the union of all the values in the input
// summaries.
//
// When the Op is run, it reports an `InvalidArgument` error if multiple values
// in the summaries to merge use the same tag.
//
// Arguments:
// * inputs: Can be of any shape.  Each must contain serialized `Summary` protocol
// buffers.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Scalar. Serialized `Summary` protocol buffer.
Node* MergeSummary(gtl::ArraySlice<NodeOut> inputs, const
                   GraphDefBuilder::Options& opts);

// Prints a list of tensors.
//
// Passes `input` through to `output` and prints `data` when evaluating.
//
// Arguments:
// * input: The tensor passed to `output`
// * data: A list of tensors to print out when op is evaluated.
// * opts:
//   .WithAttr("message", StringPiece): Defaults to "".
//     A string, prefix of the error message.
//   .WithAttr("first_n", int64): Defaults to -1.
//     Only log `first_n` number of times. -1 disables logging.
//   .WithAttr("summarize", int64): Defaults to 3.
//     Only print this many entries of each tensor.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// The unmodified `input` tensor
Node* Print(NodeOut input, gtl::ArraySlice<NodeOut> data, const
            GraphDefBuilder::Options& opts);

// Outputs a `Summary` protocol buffer with scalar values.
//
// The input `tags` and `values` must have the same shape.  The generated summary
// has a summary value for each tag-value pair in `tags` and `values`.
//
// Arguments:
// * tags: Tags for the summary.
// * values: Same shape as `tags.  Values for the summary.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Scalar.  Serialized `Summary` protocol buffer.
Node* ScalarSummary(NodeOut tags, NodeOut values, const
                    GraphDefBuilder::Options& opts);

}  // namespace ops
}  // namespace tensorflow

#endif  // TENSORFLOW_CC_OPS_LOGGING_OPS_H_
