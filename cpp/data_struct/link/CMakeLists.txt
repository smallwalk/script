set(CMAKE_CXX_FLAGS "-g3")

aux_source_directory(. DIR_SRCS)

include_directories("/Users/MLS/script/cpp/data_struct/link/include")
link_directories("/Users/MLS/script/cpp/data_struct/link/lib")

add_executable(main ${DIR_SRCS})

target_link_libraries(main slist)
