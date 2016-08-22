cd %~dp0
google\protobuf\cmake\build\protoc -I. --grpc_out=. --plugin=protoc-gen-grpc=third_party\grpc\vsprojects\x64\Release\grpc_cpp_plugin.exe tensorflow/core/protobuf/master_service.proto
google\protobuf\cmake\build\protoc -I. --grpc_out=. --plugin=protoc-gen-grpc=third_party\grpc\vsprojects\x64\Release\grpc_cpp_plugin.exe tensorflow/core/protobuf/worker_service.proto