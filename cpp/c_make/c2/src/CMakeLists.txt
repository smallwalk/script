include_directories("/Users/guochao/Script/cpp/c_make/c2/include")
aux_source_directory(. DIR_TEST1_SRCS)
add_library ( te ${DIR_TEST1_SRCS})
