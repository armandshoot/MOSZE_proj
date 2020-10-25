cmake_minimum_required(VERSION 2.6)
 
project(json_test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 

# and the GTest and pthread library
add_executable(runTests unit_test.cpp ../Jsonparser.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

