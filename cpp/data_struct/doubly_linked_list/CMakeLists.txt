project (doubly_link)

set(CMAKE_CXX_FLAGS "-g3")

aux_source_directory(. DIR_SRCS)

include_directories("/Users/MLS/script/cpp/data_struct/doubly_linked_list/include")

add_executable(main ${DIR_SRCS})

