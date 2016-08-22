// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/ops/array_ops.h"

#include "tensorflow/core/graph/node_builder.h"

namespace tensorflow {
namespace ops {

Node* BatchMatrixBandPart(NodeOut input, NodeOut num_lower, NodeOut num_upper,
                          const GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "BatchMatrixBandPart";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(num_lower);
  node_builder.Input(num_upper);
  return opts.FinalizeBuilder(&node_builder);
}

Node* BatchMatrixDiag(NodeOut diagonal, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "BatchMatrixDiag";
  return UnaryOp(kOpName, diagonal, opts);
}

Node* BatchMatrixDiagPart(NodeOut input, const GraphDefBuilder::Options& opts)
                          {
  static const string kOpName = "BatchMatrixDiagPart";
  return UnaryOp(kOpName, input, opts);
}

Node* BatchToSpace(NodeOut input, NodeOut crops, int64 block_size, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "BatchToSpace";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(crops);
  node_builder.Attr("block_size", block_size);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Bitcast(NodeOut input, DataType type, const GraphDefBuilder::Options&
              opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Bitcast";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Attr("type", type);
  return opts.FinalizeBuilder(&node_builder);
}

Node* BroadcastGradientArgs(NodeOut s0, NodeOut s1, const
                            GraphDefBuilder::Options& opts) {
  static const string kOpName = "BroadcastGradientArgs";
  return BinaryOp(kOpName, s0, s1, opts);
}

Node* CheckNumerics(NodeOut tensor, StringPiece message, const
                    GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "CheckNumerics";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(tensor);
  node_builder.Attr("message", message);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Concat(NodeOut concat_dim, gtl::ArraySlice<NodeOut> values, const
             GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Concat";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(concat_dim);
  node_builder.Input(values);
  return opts.FinalizeBuilder(&node_builder);
}

Node* ConcatOffset(NodeOut concat_dim, gtl::ArraySlice<NodeOut> shape, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "ConcatOffset";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(concat_dim);
  node_builder.Input(shape);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Const(const Tensor& value, DataType dtype, const
            GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Const";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Attr("value", value);
  node_builder.Attr("dtype", dtype);
  return opts.FinalizeBuilder(&node_builder);
}

Node* DepthToSpace(NodeOut input, int64 block_size, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "DepthToSpace";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Attr("block_size", block_size);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Diag(NodeOut diagonal, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Diag";
  return UnaryOp(kOpName, diagonal, opts);
}

Node* DiagPart(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "DiagPart";
  return UnaryOp(kOpName, input, opts);
}

Node* EditDistance(NodeOut hypothesis_indices, NodeOut hypothesis_values,
                   NodeOut hypothesis_shape, NodeOut truth_indices, NodeOut
                   truth_values, NodeOut truth_shape, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "EditDistance";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(hypothesis_indices);
  node_builder.Input(hypothesis_values);
  node_builder.Input(hypothesis_shape);
  node_builder.Input(truth_indices);
  node_builder.Input(truth_values);
  node_builder.Input(truth_shape);
  return opts.FinalizeBuilder(&node_builder);
}

Node* ExpandDims(NodeOut input, NodeOut dim, const GraphDefBuilder::Options&
                 opts) {
  static const string kOpName = "ExpandDims";
  return BinaryOp(kOpName, input, dim, opts);
}

Node* Fill(NodeOut dims, NodeOut value, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Fill";
  return BinaryOp(kOpName, dims, value, opts);
}

Node* Gather(NodeOut params, NodeOut indices, const GraphDefBuilder::Options&
             opts) {
  static const string kOpName = "Gather";
  return BinaryOp(kOpName, params, indices, opts);
}

Node* GatherNd(NodeOut params, NodeOut indices, const GraphDefBuilder::Options&
               opts) {
  static const string kOpName = "GatherNd";
  return BinaryOp(kOpName, params, indices, opts);
}

Node* Identity(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Identity";
  return UnaryOp(kOpName, input, opts);
}

Node* ImmutableConst(DataType dtype, TensorShape shape, StringPiece
                     memory_region_name, const GraphDefBuilder::Options& opts)
                     {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "ImmutableConst";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Attr("dtype", dtype);
  node_builder.Attr("shape", shape);
  node_builder.Attr("memory_region_name", memory_region_name);
  return opts.FinalizeBuilder(&node_builder);
}

Node* InvertPermutation(NodeOut x, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "InvertPermutation";
  return UnaryOp(kOpName, x, opts);
}

Node* ListDiff(NodeOut x, NodeOut y, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "ListDiff";
  return BinaryOp(kOpName, x, y, opts);
}

Node* MirrorPad(NodeOut input, NodeOut paddings, StringPiece mode, const
                GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "MirrorPad";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(paddings);
  node_builder.Attr("mode", mode);
  return opts.FinalizeBuilder(&node_builder);
}

Node* MirrorPadGrad(NodeOut input, NodeOut paddings, StringPiece mode, const
                    GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "MirrorPadGrad";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(paddings);
  node_builder.Attr("mode", mode);
  return opts.FinalizeBuilder(&node_builder);
}

Node* OneHot(NodeOut indices, NodeOut depth, NodeOut on_value, NodeOut
             off_value, const GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "OneHot";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(indices);
  node_builder.Input(depth);
  node_builder.Input(on_value);
  node_builder.Input(off_value);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Pack(gtl::ArraySlice<NodeOut> values, const GraphDefBuilder::Options&
           opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Pack";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(values);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Pad(NodeOut input, NodeOut paddings, const GraphDefBuilder::Options&
          opts) {
  static const string kOpName = "Pad";
  return BinaryOp(kOpName, input, paddings, opts);
}

Node* Placeholder(DataType dtype, const GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Placeholder";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Attr("dtype", dtype);
  return opts.FinalizeBuilder(&node_builder);
}

Node* PlaceholderWithDefault(NodeOut input, TensorShape shape, const
                             GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "PlaceholderWithDefault";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Attr("shape", shape);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Rank(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Rank";
  return UnaryOp(kOpName, input, opts);
}

Node* RefIdentity(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "RefIdentity";
  return UnaryOp(kOpName, input, opts);
}

Node* Reshape(NodeOut tensor, NodeOut shape, const GraphDefBuilder::Options&
              opts) {
  static const string kOpName = "Reshape";
  return BinaryOp(kOpName, tensor, shape, opts);
}

Node* Reverse(NodeOut tensor, NodeOut dims, const GraphDefBuilder::Options&
              opts) {
  static const string kOpName = "Reverse";
  return BinaryOp(kOpName, tensor, dims, opts);
}

Node* ReverseSequence(NodeOut input, NodeOut seq_lengths, int64 seq_dim, const
                      GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "ReverseSequence";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(seq_lengths);
  node_builder.Attr("seq_dim", seq_dim);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Shape(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Shape";
  return UnaryOp(kOpName, input, opts);
}

Node* ShapeN(gtl::ArraySlice<NodeOut> input, const GraphDefBuilder::Options&
             opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "ShapeN";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Size(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Size";
  return UnaryOp(kOpName, input, opts);
}

Node* Slice(NodeOut input, NodeOut begin, NodeOut size, const
            GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Slice";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(begin);
  node_builder.Input(size);
  return opts.FinalizeBuilder(&node_builder);
}

Node* SpaceToBatch(NodeOut input, NodeOut paddings, int64 block_size, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "SpaceToBatch";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(paddings);
  node_builder.Attr("block_size", block_size);
  return opts.FinalizeBuilder(&node_builder);
}

Node* SpaceToDepth(NodeOut input, int64 block_size, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "SpaceToDepth";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Attr("block_size", block_size);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Split(NodeOut split_dim, NodeOut value, int64 num_split, const
            GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Split";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(split_dim);
  node_builder.Input(value);
  node_builder.Attr("num_split", num_split);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Squeeze(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Squeeze";
  return UnaryOp(kOpName, input, opts);
}

Node* StopGradient(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "StopGradient";
  return UnaryOp(kOpName, input, opts);
}

Node* Tile(NodeOut input, NodeOut multiples, const GraphDefBuilder::Options&
           opts) {
  static const string kOpName = "Tile";
  return BinaryOp(kOpName, input, multiples, opts);
}

Node* TileGrad(NodeOut input, NodeOut multiples, const
               GraphDefBuilder::Options& opts) {
  static const string kOpName = "TileGrad";
  return BinaryOp(kOpName, input, multiples, opts);
}

Node* Transpose(NodeOut x, NodeOut perm, const GraphDefBuilder::Options& opts)
                {
  static const string kOpName = "Transpose";
  return BinaryOp(kOpName, x, perm, opts);
}

Node* Unique(NodeOut x, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Unique";
  return UnaryOp(kOpName, x, opts);
}

Node* UniqueWithCounts(NodeOut x, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "UniqueWithCounts";
  return UnaryOp(kOpName, x, opts);
}

Node* Unpack(NodeOut value, int64 num, const GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Unpack";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(value);
  node_builder.Attr("num", num);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Where(NodeOut input, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "Where";
  return UnaryOp(kOpName, input, opts);
}

Node* ZerosLike(NodeOut x, const GraphDefBuilder::Options& opts) {
  static const string kOpName = "ZerosLike";
  return UnaryOp(kOpName, x, opts);
}

}  // namespace ops
}  // namespace tensorflow
