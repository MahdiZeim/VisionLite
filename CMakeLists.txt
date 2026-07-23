cmake_minimum_required(VERSION 3.15)


project(
    VisionLite
    VERSION 0.1.0
    LANGUAGES CXX
)


set(
    CMAKE_CXX_STANDARD 17
)

set(
    CMAKE_CXX_STANDARD_REQUIRED ON
)


include_directories(
    include
)


add_library(
    visionlite
    src/image.cpp
)


add_executable(
    visionlite_demo
    examples/main.cpp
)


target_link_libraries(
    visionlite_demo
    visionlite
)