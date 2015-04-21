set(CMAKE_CXX_FLAGS "-g3")

aux_source_directory(. DIR_SRCS)

include_directories("/Users/guochao/Script/cpp/c_make/c2/include")
link_directories("/Users/guochao/Script/cpp/c_make/c2/lib")

add_executable(main ${DIR_SRCS})

target_link_libraries(main te)
