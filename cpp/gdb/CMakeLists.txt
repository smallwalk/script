project(examples)

set(CMAKE_CXX_FLAGS "-g3")

# Create build rules for all the simple examples that only require a
# single file.

ADD_EXECUTABLE(test test.cpp fun.cpp)
