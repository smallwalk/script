set(CMAKE_CXX_FLAGS "-g3")

include_directories("/Users/MLS/script/cpp/data_struct/link/include")
aux_source_directory(. DIR_TEST1_SRCS)
add_library ( slist ${DIR_TEST1_SRCS})
