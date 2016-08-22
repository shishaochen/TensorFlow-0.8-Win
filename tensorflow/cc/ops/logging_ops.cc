// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/ops/logging_ops.h"

#include "tensorflow/core/graph/node_builder.h"

namespace tensorflow {
namespace ops {

Node* Assert(NodeOut condition, gtl::ArraySlice<NodeOut> data, const
             GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Assert";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(condition);
  node_builder.Input(data);
  return opts.FinalizeBuilder(&node_builder);
}

Node* AudioSummary(NodeOut tag, NodeOut tensor, float sample_rate, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "AudioSummary";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(tag);
  node_builder.Input(tensor);
  node_builder.Attr("sample_rate", sample_rate);
  return opts.FinalizeBuilder(&node_builder);
}

Node* HistogramSummary(NodeOut tag, NodeOut values, const
                       GraphDefBuilder::Options& opts) {
  static const string kOpName = "HistogramSummary";
  return BinaryOp(kOpName, tag, values, opts);
}

Node* ImageSummary(NodeOut tag, NodeOut tensor, const GraphDefBuilder::Options&
                   opts) {
  static const string kOpName = "ImageSummary";
  return BinaryOp(kOpName, tag, tensor, opts);
}

Node* MergeSummary(gtl::ArraySlice<NodeOut> inputs, const
                   GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "MergeSummary";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(inputs);
  return opts.FinalizeBuilder(&node_builder);
}

Node* Print(NodeOut input, gtl::ArraySlice<NodeOut> data, const
            GraphDefBuilder::Options& opts) {
  if (opts.HaveError()) return nullptr;
  static const string kOpName = "Print";
  NodeBuilder node_builder(opts.GetNameForOp(kOpName), kOpName,
                           opts.op_registry());
  node_builder.Input(input);
  node_builder.Input(data);
  return opts.FinalizeBuilder(&node_builder);
}

Node* ScalarSummary(NodeOut tags, NodeOut values, const
                    GraphDefBuilder::Options& opts) {
  static const string kOpName = "ScalarSummary";
  return BinaryOp(kOpName, tags, values, opts);
}

}  // namespace ops
}  // namespace tensorflow
