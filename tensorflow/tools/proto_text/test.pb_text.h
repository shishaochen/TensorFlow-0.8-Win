// GENERATED FILE - DO NOT MODIFY
#ifndef tensorflow_tools_proto_text_test_proto_H_
#define tensorflow_tools_proto_text_test_proto_H_

#include "tensorflow/tools/proto_text/test.pb.h"
#include "tensorflow/core/platform/macros.h"
#include "tensorflow/core/platform/protobuf.h"
#include "tensorflow/core/platform/types.h"

namespace tensorflow {
namespace test {

// Enum text output for tensorflow.test.ForeignEnum
const char* EnumName_ForeignEnum(
    ::tensorflow::test::ForeignEnum value);

// Enum text output for tensorflow.test.TestAllTypes.NestedEnum
const char* EnumName_TestAllTypes_NestedEnum(
    ::tensorflow::test::TestAllTypes_NestedEnum value);

// Message-text conversion for tensorflow.test.TestAllTypes.NestedMessage.DoubleNestedMessage
string ProtoDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage& msg);
string ProtoShortDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage& msg);
bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage* msg)
        TF_MUST_USE_RESULT;

// Message-text conversion for tensorflow.test.TestAllTypes.NestedMessage
string ProtoDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage& msg);
string ProtoShortDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage& msg);
bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestAllTypes_NestedMessage* msg)
        TF_MUST_USE_RESULT;

// Message-text conversion for tensorflow.test.TestAllTypes
string ProtoDebugString(
    const ::tensorflow::test::TestAllTypes& msg);
string ProtoShortDebugString(
    const ::tensorflow::test::TestAllTypes& msg);
bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestAllTypes* msg)
        TF_MUST_USE_RESULT;

// Message-text conversion for tensorflow.test.NestedTestAllTypes
string ProtoDebugString(
    const ::tensorflow::test::NestedTestAllTypes& msg);
string ProtoShortDebugString(
    const ::tensorflow::test::NestedTestAllTypes& msg);
bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::NestedTestAllTypes* msg)
        TF_MUST_USE_RESULT;

// Message-text conversion for tensorflow.test.ForeignMessage
string ProtoDebugString(
    const ::tensorflow::test::ForeignMessage& msg);
string ProtoShortDebugString(
    const ::tensorflow::test::ForeignMessage& msg);
bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::ForeignMessage* msg)
        TF_MUST_USE_RESULT;

// Message-text conversion for tensorflow.test.TestEmptyMessage
string ProtoDebugString(
    const ::tensorflow::test::TestEmptyMessage& msg);
string ProtoShortDebugString(
    const ::tensorflow::test::TestEmptyMessage& msg);
bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestEmptyMessage* msg)
        TF_MUST_USE_RESULT;

}  // namespace test
}  // namespace tensorflow

#endif  // tensorflow_tools_proto_text_test_proto_H_
