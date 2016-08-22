// GENERATED FILE - DO NOT MODIFY
#ifndef tensorflow_tools_proto_text_test_proto_IMPL_H_
#define tensorflow_tools_proto_text_test_proto_IMPL_H_

#include "tensorflow/tools/proto_text/test.pb_text.h"
#include "tensorflow/core/lib/strings/proto_text_util.h"
#include "tensorflow/core/lib/strings/scanner.h"
#include "tensorflow/tools/proto_text/test.pb.h"

namespace tensorflow {
namespace test {

namespace internal {

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage& msg);
bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage* msg);

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestAllTypes_NestedMessage& msg);
bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestAllTypes_NestedMessage* msg);

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestAllTypes& msg);
bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestAllTypes* msg);

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::NestedTestAllTypes& msg);
bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::NestedTestAllTypes* msg);

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::ForeignMessage& msg);
bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::ForeignMessage* msg);

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestEmptyMessage& msg);
bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestEmptyMessage* msg);

}  // namespace internal

}  // namespace test
}  // namespace tensorflow

#endif  // tensorflow_tools_proto_text_test_proto_IMPL_H_
