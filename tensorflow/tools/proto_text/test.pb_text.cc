// GENERATED FILE - DO NOT MODIFY
#include "tensorflow/tools/proto_text/test.pb_text-impl.h"

using ::tensorflow::strings::Scanner;
using ::tensorflow::strings::StrCat;

namespace tensorflow {
namespace test {

const char* EnumName_ForeignEnum(
    ::tensorflow::test::ForeignEnum value) {
  switch (value) {
    case 0: return "FOREIGN_ZERO";
    case 4: return "FOREIGN_FOO";
    case 5: return "FOREIGN_BAR";
    case 6: return "FOREIGN_BAZ";
    default: return "";
  }
}

const char* EnumName_TestAllTypes_NestedEnum(
    ::tensorflow::test::TestAllTypes_NestedEnum value) {
  switch (value) {
    case 0: return "ZERO";
    case 1: return "FOO";
    case 2: return "BAR";
    case 3: return "BAZ";
    case -1: return "NEG";
    default: return "";
  }
}

string ProtoDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, false);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

string ProtoShortDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, true);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

namespace internal {

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage& msg) {
  o->AppendStringIfNotEmpty("optional_string", ProtobufStringToString(msg.optional_string()));
}

}  // namespace internal

bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage* msg) {
  msg->Clear();
  Scanner scanner(s);
  if (!internal::ProtoParseFromScanner(&scanner, false, false, msg)) return false;
  scanner.Eos();
  return scanner.GetResult();
}

namespace internal {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestAllTypes_NestedMessage_DoubleNestedMessage* msg) {
  std::vector<bool> has_seen(1, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "optional_string") {
      if (has_seen[0]) return false;
      has_seen[0] = true;
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, msg->mutable_optional_string());
    }
  }
}

}  // namespace internal

string ProtoDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, false);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

string ProtoShortDebugString(
    const ::tensorflow::test::TestAllTypes_NestedMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, true);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

namespace internal {

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestAllTypes_NestedMessage& msg) {
  o->AppendNumericIfNotZero("optional_int32", msg.optional_int32());
  for (int i = 0; i < msg.repeated_int32_size(); ++i) {
    o->AppendNumeric("repeated_int32", msg.repeated_int32(i));
  }
  if (msg.has_msg()) {
    o->OpenNestedMessage("msg");
    ::tensorflow::test::internal::AppendProtoDebugString(o, msg.msg());
    o->CloseNestedMessage();
  }
  o->AppendNumericIfNotZero("optional_int64", msg.optional_int64());
}

}  // namespace internal

bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestAllTypes_NestedMessage* msg) {
  msg->Clear();
  Scanner scanner(s);
  if (!internal::ProtoParseFromScanner(&scanner, false, false, msg)) return false;
  scanner.Eos();
  return scanner.GetResult();
}

namespace internal {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestAllTypes_NestedMessage* msg) {
  std::vector<bool> has_seen(4, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "optional_int32") {
      if (has_seen[0]) return false;
      has_seen[0] = true;
      int32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_int32(value);
    }
    else if (identifier == "repeated_int32") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int32 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_int32(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "msg") {
      if (has_seen[2]) return false;
      has_seen[2] = true;
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', msg->mutable_msg())) return false;
    }
    else if (identifier == "optional_int64") {
      if (has_seen[3]) return false;
      has_seen[3] = true;
      int64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_int64(value);
    }
  }
}

}  // namespace internal

namespace internal {
namespace {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::protobuf::Map<string, ::tensorflow::test::TestAllTypes_NestedMessage>* map) {
  string map_key;
  bool set_map_key = false;
  ::tensorflow::test::TestAllTypes_NestedMessage map_value;
  bool set_map_value = false;
  std::vector<bool> has_seen(2, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!set_map_key || !set_map_value) return false;
      (*map)[map_key] = map_value;
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "key") {
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, &map_key);
      set_map_key = true;
    }
    else if (identifier == "value") {
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', &map_value)) return false;
      set_map_value = true;
    }
  }
}

}  // namespace
}  // namespace internal

namespace internal {
namespace {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::protobuf::Map<int32, ::tensorflow::test::TestAllTypes_NestedMessage>* map) {
  int32 map_key;
  bool set_map_key = false;
  ::tensorflow::test::TestAllTypes_NestedMessage map_value;
  bool set_map_value = false;
  std::vector<bool> has_seen(2, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!set_map_key || !set_map_value) return false;
      (*map)[map_key] = map_value;
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "key") {
      int32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      map_key = (value);
      set_map_key = true;
    }
    else if (identifier == "value") {
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', &map_value)) return false;
      set_map_value = true;
    }
  }
}

}  // namespace
}  // namespace internal

namespace internal {
namespace {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::protobuf::Map<int64, ::tensorflow::test::TestAllTypes_NestedMessage>* map) {
  int64 map_key;
  bool set_map_key = false;
  ::tensorflow::test::TestAllTypes_NestedMessage map_value;
  bool set_map_value = false;
  std::vector<bool> has_seen(2, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!set_map_key || !set_map_value) return false;
      (*map)[map_key] = map_value;
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "key") {
      int64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      map_key = (value);
      set_map_key = true;
    }
    else if (identifier == "value") {
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', &map_value)) return false;
      set_map_value = true;
    }
  }
}

}  // namespace
}  // namespace internal

namespace internal {
namespace {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::protobuf::Map<bool, ::tensorflow::test::TestAllTypes_NestedMessage>* map) {
  bool map_key;
  bool set_map_key = false;
  ::tensorflow::test::TestAllTypes_NestedMessage map_value;
  bool set_map_value = false;
  std::vector<bool> has_seen(2, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!set_map_key || !set_map_value) return false;
      (*map)[map_key] = map_value;
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "key") {
      bool value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseBoolFromScanner(scanner, &value)) return false;
      map_key = (value);
      set_map_key = true;
    }
    else if (identifier == "value") {
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', &map_value)) return false;
      set_map_value = true;
    }
  }
}

}  // namespace
}  // namespace internal

namespace internal {
namespace {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::protobuf::Map<string, int64>* map) {
  string map_key;
  bool set_map_key = false;
  int64 map_value;
  bool set_map_value = false;
  std::vector<bool> has_seen(2, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!set_map_key || !set_map_value) return false;
      (*map)[map_key] = map_value;
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "key") {
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, &map_key);
      set_map_key = true;
    }
    else if (identifier == "value") {
      int64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      map_value = (value);
      set_map_value = true;
    }
  }
}

}  // namespace
}  // namespace internal

namespace internal {
namespace {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::protobuf::Map<int64, string>* map) {
  int64 map_key;
  bool set_map_key = false;
  string map_value;
  bool set_map_value = false;
  std::vector<bool> has_seen(2, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!set_map_key || !set_map_value) return false;
      (*map)[map_key] = map_value;
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "key") {
      int64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      map_key = (value);
      set_map_key = true;
    }
    else if (identifier == "value") {
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, &map_value);
      set_map_value = true;
    }
  }
}

}  // namespace
}  // namespace internal

string ProtoDebugString(
    const ::tensorflow::test::TestAllTypes& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, false);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

string ProtoShortDebugString(
    const ::tensorflow::test::TestAllTypes& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, true);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

namespace internal {

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestAllTypes& msg) {
  o->AppendNumericIfNotZero("optional_int64", msg.optional_int64());
  o->AppendNumericIfNotZero("optional_uint32", msg.optional_uint32());
  o->AppendNumericIfNotZero("optional_sint32", msg.optional_sint32());
  o->AppendNumericIfNotZero("optional_sint64", msg.optional_sint64());
  o->AppendNumericIfNotZero("optional_fixed32", msg.optional_fixed32());
  o->AppendNumericIfNotZero("optional_fixed64", msg.optional_fixed64());
  o->AppendNumericIfNotZero("optional_sfixed32", msg.optional_sfixed32());
  o->AppendNumericIfNotZero("optional_sfixed64", msg.optional_sfixed64());
  o->AppendNumericIfNotZero("optional_float", msg.optional_float());
  o->AppendNumericIfNotZero("optional_double", msg.optional_double());
  o->AppendBoolIfTrue("optional_bool", msg.optional_bool());
  o->AppendStringIfNotEmpty("optional_string", ProtobufStringToString(msg.optional_string()));
  o->AppendStringIfNotEmpty("optional_bytes", ProtobufStringToString(msg.optional_bytes()));
  if (msg.has_optional_nested_message()) {
    o->OpenNestedMessage("optional_nested_message");
    ::tensorflow::test::internal::AppendProtoDebugString(o, msg.optional_nested_message());
    o->CloseNestedMessage();
  }
  if (msg.has_optional_foreign_message()) {
    o->OpenNestedMessage("optional_foreign_message");
    ::tensorflow::test::internal::AppendProtoDebugString(o, msg.optional_foreign_message());
    o->CloseNestedMessage();
  }
  if (msg.optional_nested_enum() != 0) {
    o->AppendEnumName("optional_nested_enum", ::tensorflow::test::EnumName_TestAllTypes_NestedEnum(msg.optional_nested_enum()));
  }
  if (msg.optional_foreign_enum() != 0) {
    o->AppendEnumName("optional_foreign_enum", ::tensorflow::test::EnumName_ForeignEnum(msg.optional_foreign_enum()));
  }
  o->AppendStringIfNotEmpty("optional_cord", ProtobufStringToString(msg.optional_cord()));
  for (int i = 0; i < msg.repeated_int32_size(); ++i) {
    o->AppendNumeric("repeated_int32", msg.repeated_int32(i));
  }
  for (int i = 0; i < msg.repeated_int64_size(); ++i) {
    o->AppendNumeric("repeated_int64", msg.repeated_int64(i));
  }
  for (int i = 0; i < msg.repeated_uint32_size(); ++i) {
    o->AppendNumeric("repeated_uint32", msg.repeated_uint32(i));
  }
  for (int i = 0; i < msg.repeated_uint64_size(); ++i) {
    o->AppendNumeric("repeated_uint64", msg.repeated_uint64(i));
  }
  for (int i = 0; i < msg.repeated_sint32_size(); ++i) {
    o->AppendNumeric("repeated_sint32", msg.repeated_sint32(i));
  }
  for (int i = 0; i < msg.repeated_sint64_size(); ++i) {
    o->AppendNumeric("repeated_sint64", msg.repeated_sint64(i));
  }
  for (int i = 0; i < msg.repeated_fixed32_size(); ++i) {
    o->AppendNumeric("repeated_fixed32", msg.repeated_fixed32(i));
  }
  for (int i = 0; i < msg.repeated_fixed64_size(); ++i) {
    o->AppendNumeric("repeated_fixed64", msg.repeated_fixed64(i));
  }
  for (int i = 0; i < msg.repeated_sfixed32_size(); ++i) {
    o->AppendNumeric("repeated_sfixed32", msg.repeated_sfixed32(i));
  }
  for (int i = 0; i < msg.repeated_sfixed64_size(); ++i) {
    o->AppendNumeric("repeated_sfixed64", msg.repeated_sfixed64(i));
  }
  for (int i = 0; i < msg.repeated_float_size(); ++i) {
    o->AppendNumeric("repeated_float", msg.repeated_float(i));
  }
  for (int i = 0; i < msg.repeated_double_size(); ++i) {
    o->AppendNumeric("repeated_double", msg.repeated_double(i));
  }
  for (int i = 0; i < msg.repeated_bool_size(); ++i) {
    o->AppendBool("repeated_bool", msg.repeated_bool(i));
  }
  for (int i = 0; i < msg.repeated_string_size(); ++i) {
    o->AppendString("repeated_string", ProtobufStringToString(msg.repeated_string(i)));
  }
  for (int i = 0; i < msg.repeated_bytes_size(); ++i) {
    o->AppendString("repeated_bytes", ProtobufStringToString(msg.repeated_bytes(i)));
  }
  for (int i = 0; i < msg.repeated_nested_message_size(); ++i) {
    o->OpenNestedMessage("repeated_nested_message");
    ::tensorflow::test::internal::AppendProtoDebugString(o, msg.repeated_nested_message(i));
    o->CloseNestedMessage();
  }
  for (int i = 0; i < msg.repeated_nested_enum_size(); ++i) {
    o->AppendEnumName("repeated_nested_enum", ::tensorflow::test::EnumName_TestAllTypes_NestedEnum(msg.repeated_nested_enum(i)));
  }
  for (int i = 0; i < msg.repeated_cord_size(); ++i) {
    o->AppendString("repeated_cord", ProtobufStringToString(msg.repeated_cord(i)));
  }
  {
    std::vector<string> keys;
    for (const auto& e : msg.map_string_to_message()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("map_string_to_message");
      o->AppendString("key", ProtobufStringToString(key));
      o->OpenNestedMessage("value");
      ::tensorflow::test::internal::AppendProtoDebugString(o, msg.map_string_to_message().at(key));
      o->CloseNestedMessage();
      o->CloseNestedMessage();
    }
  }
  {
    std::vector<int32> keys;
    for (const auto& e : msg.map_int32_to_message()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("map_int32_to_message");
      o->AppendNumeric("key", key);
      o->OpenNestedMessage("value");
      ::tensorflow::test::internal::AppendProtoDebugString(o, msg.map_int32_to_message().at(key));
      o->CloseNestedMessage();
      o->CloseNestedMessage();
    }
  }
  {
    std::vector<int64> keys;
    for (const auto& e : msg.map_int64_to_message()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("map_int64_to_message");
      o->AppendNumeric("key", key);
      o->OpenNestedMessage("value");
      ::tensorflow::test::internal::AppendProtoDebugString(o, msg.map_int64_to_message().at(key));
      o->CloseNestedMessage();
      o->CloseNestedMessage();
    }
  }
  {
    std::vector<bool> keys;
    for (const auto& e : msg.map_bool_to_message()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("map_bool_to_message");
      o->AppendBool("key", key);
      o->OpenNestedMessage("value");
      ::tensorflow::test::internal::AppendProtoDebugString(o, msg.map_bool_to_message().at(key));
      o->CloseNestedMessage();
      o->CloseNestedMessage();
    }
  }
  {
    std::vector<string> keys;
    for (const auto& e : msg.map_string_to_int64()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("map_string_to_int64");
      o->AppendString("key", ProtobufStringToString(key));
      o->AppendNumeric("value", msg.map_string_to_int64().at(key));
      o->CloseNestedMessage();
    }
  }
  {
    std::vector<int64> keys;
    for (const auto& e : msg.map_int64_to_string()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("map_int64_to_string");
      o->AppendNumeric("key", key);
      o->AppendString("value", ProtobufStringToString(msg.map_int64_to_string().at(key)));
      o->CloseNestedMessage();
    }
  }
  for (int i = 0; i < msg.packed_repeated_int64_size(); ++i) {
    o->AppendNumeric("packed_repeated_int64", msg.packed_repeated_int64(i));
  }
  {
    std::vector<string> keys;
    for (const auto& e : msg.another_map_string_to_message()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("another_map_string_to_message");
      o->AppendString("key", ProtobufStringToString(key));
      o->OpenNestedMessage("value");
      ::tensorflow::test::internal::AppendProtoDebugString(o, msg.another_map_string_to_message().at(key));
      o->CloseNestedMessage();
      o->CloseNestedMessage();
    }
  }
  if (msg.oneof_field_case() == ::tensorflow::test::TestAllTypes::kOneofEnum) {
    o->AppendEnumName("oneof_enum", ::tensorflow::test::EnumName_TestAllTypes_NestedEnum(msg.oneof_enum()));
  }
  if (msg.oneof_field_case() == ::tensorflow::test::TestAllTypes::kOneofUint32) {
    o->AppendNumeric("oneof_uint32", msg.oneof_uint32());
  }
  if (msg.oneof_field_case() == ::tensorflow::test::TestAllTypes::kOneofNestedMessage) {
    o->OpenNestedMessage("oneof_nested_message");
    ::tensorflow::test::internal::AppendProtoDebugString(o, msg.oneof_nested_message());
    o->CloseNestedMessage();
  }
  if (msg.oneof_field_case() == ::tensorflow::test::TestAllTypes::kOneofString) {
    o->AppendString("oneof_string", ProtobufStringToString(msg.oneof_string()));
  }
  if (msg.oneof_field_case() == ::tensorflow::test::TestAllTypes::kOneofBytes) {
    o->AppendString("oneof_bytes", ProtobufStringToString(msg.oneof_bytes()));
  }
  o->AppendNumericIfNotZero("optional_uint64", msg.optional_uint64());
  o->AppendNumericIfNotZero("optional_int32", msg.optional_int32());
}

}  // namespace internal

bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestAllTypes* msg) {
  msg->Clear();
  Scanner scanner(s);
  if (!internal::ProtoParseFromScanner(&scanner, false, false, msg)) return false;
  scanner.Eos();
  return scanner.GetResult();
}

namespace internal {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestAllTypes* msg) {
  std::vector<bool> has_seen(51, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "optional_int32") {
      if (has_seen[0]) return false;
      has_seen[0] = true;
      int32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_int32(value);
    }
    else if (identifier == "optional_int64") {
      if (has_seen[1]) return false;
      has_seen[1] = true;
      int64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_int64(value);
    }
    else if (identifier == "optional_uint32") {
      if (has_seen[2]) return false;
      has_seen[2] = true;
      uint32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_uint32(value);
    }
    else if (identifier == "optional_uint64") {
      if (has_seen[3]) return false;
      has_seen[3] = true;
      uint64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_uint64(value);
    }
    else if (identifier == "optional_sint32") {
      if (has_seen[4]) return false;
      has_seen[4] = true;
      int32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_sint32(value);
    }
    else if (identifier == "optional_sint64") {
      if (has_seen[5]) return false;
      has_seen[5] = true;
      int64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_sint64(value);
    }
    else if (identifier == "optional_fixed32") {
      if (has_seen[6]) return false;
      has_seen[6] = true;
      uint32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_fixed32(value);
    }
    else if (identifier == "optional_fixed64") {
      if (has_seen[7]) return false;
      has_seen[7] = true;
      uint64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_fixed64(value);
    }
    else if (identifier == "optional_sfixed32") {
      if (has_seen[8]) return false;
      has_seen[8] = true;
      int32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_sfixed32(value);
    }
    else if (identifier == "optional_sfixed64") {
      if (has_seen[9]) return false;
      has_seen[9] = true;
      int64 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_sfixed64(value);
    }
    else if (identifier == "optional_float") {
      if (has_seen[10]) return false;
      has_seen[10] = true;
      float value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_float(value);
    }
    else if (identifier == "optional_double") {
      if (has_seen[11]) return false;
      has_seen[11] = true;
      double value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_optional_double(value);
    }
    else if (identifier == "optional_bool") {
      if (has_seen[12]) return false;
      has_seen[12] = true;
      bool value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseBoolFromScanner(scanner, &value)) return false;
      msg->set_optional_bool(value);
    }
    else if (identifier == "optional_string") {
      if (has_seen[13]) return false;
      has_seen[13] = true;
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, msg->mutable_optional_string());
    }
    else if (identifier == "optional_bytes") {
      if (has_seen[14]) return false;
      has_seen[14] = true;
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, msg->mutable_optional_bytes());
    }
    else if (identifier == "optional_nested_message") {
      if (has_seen[15]) return false;
      has_seen[15] = true;
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', msg->mutable_optional_nested_message())) return false;
    }
    else if (identifier == "optional_foreign_message") {
      if (has_seen[16]) return false;
      has_seen[16] = true;
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', msg->mutable_optional_foreign_message())) return false;
    }
    else if (identifier == "optional_nested_enum") {
      if (has_seen[17]) return false;
      has_seen[17] = true;
      StringPiece value;
      if (!parsed_colon || !scanner->RestartCapture().Many(Scanner::LETTER_DIGIT_DASH_UNDERSCORE).GetResult(nullptr, &value)) return false;
      if (value == "ZERO" || value == "0" || value == "-0") {
        msg->set_optional_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_ZERO);
      } else if (value == "FOO" || value == "1") {
        msg->set_optional_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_FOO);
      } else if (value == "BAR" || value == "2") {
        msg->set_optional_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_BAR);
      } else if (value == "BAZ" || value == "3") {
        msg->set_optional_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_BAZ);
      } else if (value == "NEG" || value == "-1") {
        msg->set_optional_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_NEG);
      } else {
        return false;
      }
    }
    else if (identifier == "optional_foreign_enum") {
      if (has_seen[18]) return false;
      has_seen[18] = true;
      StringPiece value;
      if (!parsed_colon || !scanner->RestartCapture().Many(Scanner::LETTER_DIGIT_DASH_UNDERSCORE).GetResult(nullptr, &value)) return false;
      if (value == "FOREIGN_ZERO" || value == "0" || value == "-0") {
        msg->set_optional_foreign_enum(::tensorflow::test::FOREIGN_ZERO);
      } else if (value == "FOREIGN_FOO" || value == "4") {
        msg->set_optional_foreign_enum(::tensorflow::test::FOREIGN_FOO);
      } else if (value == "FOREIGN_BAR" || value == "5") {
        msg->set_optional_foreign_enum(::tensorflow::test::FOREIGN_BAR);
      } else if (value == "FOREIGN_BAZ" || value == "6") {
        msg->set_optional_foreign_enum(::tensorflow::test::FOREIGN_BAZ);
      } else {
        return false;
      }
    }
    else if (identifier == "optional_cord") {
      if (has_seen[19]) return false;
      has_seen[19] = true;
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, msg->mutable_optional_cord());
    }
    else if (identifier == "repeated_int32") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int32 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_int32(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_int64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int64 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_int64(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_uint32") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        uint32 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_uint32(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_uint64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        uint64 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_uint64(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_sint32") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int32 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_sint32(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_sint64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int64 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_sint64(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_fixed32") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        uint32 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_fixed32(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_fixed64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        uint64 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_fixed64(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_sfixed32") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int32 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_sfixed32(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_sfixed64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int64 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_sfixed64(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_float") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        float value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_float(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_double") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        double value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_repeated_double(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_bool") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        bool value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseBoolFromScanner(scanner, &value)) return false;
        msg->add_repeated_bool(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_string") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        string str_value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
            scanner, &str_value)) return false;
        SetProtobufStringSwapAllowed(&str_value, msg->add_repeated_string());
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_bytes") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        string str_value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
            scanner, &str_value)) return false;
        SetProtobufStringSwapAllowed(&str_value, msg->add_repeated_bytes());
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_nested_message") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!::tensorflow::test::internal::ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->add_repeated_nested_message())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_nested_enum") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        StringPiece value;
        if (!parsed_colon || !scanner->RestartCapture().Many(Scanner::LETTER_DIGIT_DASH_UNDERSCORE).GetResult(nullptr, &value)) return false;
        if (value == "ZERO" || value == "0" || value == "-0") {
          msg->add_repeated_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_ZERO);
        } else if (value == "FOO" || value == "1") {
          msg->add_repeated_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_FOO);
        } else if (value == "BAR" || value == "2") {
          msg->add_repeated_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_BAR);
        } else if (value == "BAZ" || value == "3") {
          msg->add_repeated_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_BAZ);
        } else if (value == "NEG" || value == "-1") {
          msg->add_repeated_nested_enum(::tensorflow::test::TestAllTypes_NestedEnum_NEG);
        } else {
          return false;
        }
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "repeated_cord") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        string str_value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
            scanner, &str_value)) return false;
        SetProtobufStringSwapAllowed(&str_value, msg->add_repeated_cord());
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "oneof_uint32") {
      if (msg->oneof_field_case() != 0) return false;
      if (has_seen[38]) return false;
      has_seen[38] = true;
      uint32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_oneof_uint32(value);
    }
    else if (identifier == "oneof_nested_message") {
      if (msg->oneof_field_case() != 0) return false;
      if (has_seen[39]) return false;
      has_seen[39] = true;
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', msg->mutable_oneof_nested_message())) return false;
    }
    else if (identifier == "oneof_string") {
      if (msg->oneof_field_case() != 0) return false;
      if (has_seen[40]) return false;
      has_seen[40] = true;
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, msg->mutable_oneof_string());
    }
    else if (identifier == "oneof_bytes") {
      if (msg->oneof_field_case() != 0) return false;
      if (has_seen[41]) return false;
      has_seen[41] = true;
      string str_value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseStringLiteralFromScanner(
          scanner, &str_value)) return false;
      SetProtobufStringSwapAllowed(&str_value, msg->mutable_oneof_bytes());
    }
    else if (identifier == "oneof_enum") {
      if (msg->oneof_field_case() != 0) return false;
      if (has_seen[42]) return false;
      has_seen[42] = true;
      StringPiece value;
      if (!parsed_colon || !scanner->RestartCapture().Many(Scanner::LETTER_DIGIT_DASH_UNDERSCORE).GetResult(nullptr, &value)) return false;
      if (value == "ZERO" || value == "0" || value == "-0") {
        msg->set_oneof_enum(::tensorflow::test::TestAllTypes_NestedEnum_ZERO);
      } else if (value == "FOO" || value == "1") {
        msg->set_oneof_enum(::tensorflow::test::TestAllTypes_NestedEnum_FOO);
      } else if (value == "BAR" || value == "2") {
        msg->set_oneof_enum(::tensorflow::test::TestAllTypes_NestedEnum_BAR);
      } else if (value == "BAZ" || value == "3") {
        msg->set_oneof_enum(::tensorflow::test::TestAllTypes_NestedEnum_BAZ);
      } else if (value == "NEG" || value == "-1") {
        msg->set_oneof_enum(::tensorflow::test::TestAllTypes_NestedEnum_NEG);
      } else {
        return false;
      }
    }
    else if (identifier == "map_string_to_message") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_map_string_to_message())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "map_int32_to_message") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_map_int32_to_message())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "map_int64_to_message") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_map_int64_to_message())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "map_bool_to_message") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_map_bool_to_message())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "map_string_to_int64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_map_string_to_int64())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "map_int64_to_string") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_map_int64_to_string())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "another_map_string_to_message") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_another_map_string_to_message())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
    else if (identifier == "packed_repeated_int64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        int64 value;
        if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
        msg->add_packed_repeated_int64(value);
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
  }
}

}  // namespace internal

string ProtoDebugString(
    const ::tensorflow::test::NestedTestAllTypes& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, false);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

string ProtoShortDebugString(
    const ::tensorflow::test::NestedTestAllTypes& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, true);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

namespace internal {

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::NestedTestAllTypes& msg) {
  if (msg.has_child()) {
    o->OpenNestedMessage("child");
    ::tensorflow::test::internal::AppendProtoDebugString(o, msg.child());
    o->CloseNestedMessage();
  }
  if (msg.has_payload()) {
    o->OpenNestedMessage("payload");
    ::tensorflow::test::internal::AppendProtoDebugString(o, msg.payload());
    o->CloseNestedMessage();
  }
  {
    std::vector<string> keys;
    for (const auto& e : msg.map_string_to_int64()) keys.push_back(e.first);
    std::stable_sort(keys.begin(), keys.end());
    for (const auto& key : keys) {
      o->OpenNestedMessage("map_string_to_int64");
      o->AppendString("key", ProtobufStringToString(key));
      o->AppendNumeric("value", msg.map_string_to_int64().at(key));
      o->CloseNestedMessage();
    }
  }
}

}  // namespace internal

bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::NestedTestAllTypes* msg) {
  msg->Clear();
  Scanner scanner(s);
  if (!internal::ProtoParseFromScanner(&scanner, false, false, msg)) return false;
  scanner.Eos();
  return scanner.GetResult();
}

namespace internal {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::NestedTestAllTypes* msg) {
  std::vector<bool> has_seen(3, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "child") {
      if (has_seen[0]) return false;
      has_seen[0] = true;
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', msg->mutable_child())) return false;
    }
    else if (identifier == "payload") {
      if (has_seen[1]) return false;
      has_seen[1] = true;
      const char open_char = scanner->Peek();
      if (open_char != '{' && open_char != '<') return false;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      if (!::tensorflow::test::internal::ProtoParseFromScanner(
          scanner, true, open_char == '{', msg->mutable_payload())) return false;
    }
    else if (identifier == "map_string_to_int64") {
      const bool is_list = (scanner->Peek() == '[');
      do {
        if (is_list) {
          scanner->One(Scanner::ALL);
          ProtoSpaceAndComments(scanner);
        }
        const char open_char = scanner->Peek();
        if (open_char != '{' && open_char != '<') return false;
        scanner->One(Scanner::ALL);
        ProtoSpaceAndComments(scanner);
        if (!ProtoParseFromScanner(
            scanner, true, open_char == '{', msg->mutable_map_string_to_int64())) return false;
      } while (is_list && scanner->Peek() == ',');
      if (is_list && !scanner->OneLiteral("]").GetResult()) return false;
    }
  }
}

}  // namespace internal

string ProtoDebugString(
    const ::tensorflow::test::ForeignMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, false);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

string ProtoShortDebugString(
    const ::tensorflow::test::ForeignMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, true);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

namespace internal {

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::ForeignMessage& msg) {
  o->AppendNumericIfNotZero("c", msg.c());
}

}  // namespace internal

bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::ForeignMessage* msg) {
  msg->Clear();
  Scanner scanner(s);
  if (!internal::ProtoParseFromScanner(&scanner, false, false, msg)) return false;
  scanner.Eos();
  return scanner.GetResult();
}

namespace internal {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::ForeignMessage* msg) {
  std::vector<bool> has_seen(1, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
    if (identifier == "c") {
      if (has_seen[0]) return false;
      has_seen[0] = true;
      int32 value;
      if (!parsed_colon || !::tensorflow::strings::ProtoParseNumericFromScanner(scanner, &value)) return false;
      msg->set_c(value);
    }
  }
}

}  // namespace internal

string ProtoDebugString(
    const ::tensorflow::test::TestEmptyMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, false);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

string ProtoShortDebugString(
    const ::tensorflow::test::TestEmptyMessage& msg) {
  string s;
  ::tensorflow::strings::ProtoTextOutput o(&s, true);
  internal::AppendProtoDebugString(&o, msg);
  o.CloseTopMessage();
  return s;
}

namespace internal {

void AppendProtoDebugString(
    ::tensorflow::strings::ProtoTextOutput* o,
    const ::tensorflow::test::TestEmptyMessage& msg) {
}

}  // namespace internal

bool ProtoParseFromString(
    const string& s,
    ::tensorflow::test::TestEmptyMessage* msg) {
  msg->Clear();
  Scanner scanner(s);
  if (!internal::ProtoParseFromScanner(&scanner, false, false, msg)) return false;
  scanner.Eos();
  return scanner.GetResult();
}

namespace internal {

bool ProtoParseFromScanner(
    ::tensorflow::strings::Scanner* scanner, bool nested, bool close_curly,
    ::tensorflow::test::TestEmptyMessage* msg) {
  std::vector<bool> has_seen(0, false);
  while(true) {
    ProtoSpaceAndComments(scanner);
    if (nested && (scanner->Peek() == (close_curly ? '}' : '>'))) {
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
      return true;
    }
    if (!nested && scanner->empty()) { return true; }
    scanner->RestartCapture()
        .Many(Scanner::LETTER_DIGIT_UNDERSCORE)
        .StopCapture();
    StringPiece identifier;
    if (!scanner->GetResult(nullptr, &identifier)) return false;
    bool parsed_colon = false;
    ProtoSpaceAndComments(scanner);
    if (scanner->Peek() == ':') {
      parsed_colon = true;
      scanner->One(Scanner::ALL);
      ProtoSpaceAndComments(scanner);
    }
  }
}

}  // namespace internal

}  // namespace test
}  // namespace tensorflow
