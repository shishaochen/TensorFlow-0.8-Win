// This file is MACHINE GENERATED! Do not edit.

#ifndef TENSORFLOW_CC_OPS_STRING_OPS_H_
#define TENSORFLOW_CC_OPS_STRING_OPS_H_

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


// Joins a string Tensor across the given dimensions.
//
// Computes the string join across dimensions in the given string Tensor of shape
// `[d_0, d_1, ..., d_n-1]`.  Returns a new Tensor created by joining the input
// strings with the given separator (default: empty string).  Negative indices are
// counted backwards from the end, with `-1` being equivalent to `n - 1`.  Passing
// an empty `reduction_indices` joins all strings in linear index order and outputs
// a scalar string.
//
//
// For example:
// ```
// # tensor `a` is [["a", "b"], ["c", "d"]]
// tf.reduce_join(a, 0) ==> ["ac", "bd"]
// tf.reduce_join(a, 1) ==> ["ab", "cd"]
// tf.reduce_join(a, -2) = tf.reduce_join(a, 0) ==> ["ac", "bd"]
// tf.reduce_join(a, -1) = tf.reduce_join(a, 1) ==> ["ab", "cd"]
// tf.reduce_join(a, 0, keep_dims=True) ==> [["ac", "bd"]]
// tf.reduce_join(a, 1, keep_dims=True) ==> [["ab"], ["cd"]]
// tf.reduce_join(a, 0, separator=".") ==> ["a.c", "b.d"]
// tf.reduce_join(a, [0, 1]) ==> ["acbd"]
// tf.reduce_join(a, [1, 0]) ==> ["abcd"]
// tf.reduce_join(a, []) ==> ["abcd"]
// ```
//
// Arguments:
// * inputs: The input to be joined.  All reduced indices must have non-zero size.
// * reduction_indices: The dimensions to reduce over.  Dimensions are reduced in the
// order specified.  If `reduction_indices` has higher rank than `1`, it is
// flattened.  Omitting `reduction_indices` is equivalent to passing
// `[n-1, n-2, ..., 0]`.  Negative indices from `-n` to `-1` are supported.
// * opts:
//   .WithAttr("keep_dims", bool): Defaults to false.
//     If `True`, retain reduced dimensions with length `1`.
//   .WithAttr("separator", StringPiece): Defaults to "".
//     The separator to use when joining.
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// Has shape equal to that of the input with reduced dimensions removed or
// set to `1` depending on `keep_dims`.
Node* ReduceJoin(NodeOut inputs, NodeOut reduction_indices, const
                 GraphDefBuilder::Options& opts);

// Converts each string in the input Tensor to its hash mod by a number of buckets.
//
// The hash function is deterministic on the content of the string within the
// process.
//
// Note that the hash function may change from time to time.
//
// Arguments:
// * num_buckets: The number of buckets.
// * opts:
//   .WithName(StringPiece): Set the Node's name
//   .WithDevice(StringPiece): Set the Node's requested device
//   .WithControlInput(Node*) / .WithControlInputs({Node*, ...}):
//     Add control dependencies on the specified Node(s).
//
// Returns a pointer to the created Node, with output:
// A Tensor of the same shape as the input `string_tensor`.
Node* StringToHashBucket(NodeOut string_tensor, int64 num_buckets, const
                         GraphDefBuilder::Options& opts);

}  // namespace ops
}  // namespace tensorflow

#endif  // TENSORFLOW_CC_OPS_STRING_OPS_H_
