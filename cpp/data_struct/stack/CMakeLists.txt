project (stack)

set(CMAKE_CXX_FLAGS "-g3")

aux_source_directory(. DIR_SRCS)

include_directories("/usr/local/Cellar/mysql/5.6.25/include")
link_directories("/usr/local/Cellar/mysql/5.6.25/lib")

add_executable(stack ${DIR_SRCS})

target_link_libraries(stack mysqlclient)
