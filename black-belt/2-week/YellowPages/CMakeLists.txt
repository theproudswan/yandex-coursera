cmake_minimum_required(VERSION 3.8)

find_package(Protobuf REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(
    PROTO_SRCS
    PROTO_HDRS
    protos/address.proto
    protos/company.proto
    protos/name.proto
    protos/phone.proto
    protos/provider.proto
    protos/signal.proto
    protos/url.proto
    protos/working_time.proto
)

add_executable(CourseraBlackBelt ${PROTO_SRCS} ${PROTO_HDRS} "test.cpp" "merge.cpp" "test_runner.h" "yellow_pages.h")
target_link_libraries(CourseraBlackBelt ${Protobuf_LIBRARIES})