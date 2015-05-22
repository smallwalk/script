project (binlog-hunter)

set(CMAKE_CXX_FLAGS "-g3 -std=c++0x")

include_directories("/usr/local/mysql/include")
include_directories("/home/work/script/cpp/conf/include")

link_directories("/usr/local/mysql/include")

aux_source_directory(. DIR_SRCS)

ADD_EXECUTABLE(binlog-hunter ${DIR_SRCS})
TARGET_LINK_LIBRARIES(binlog-hunter mysqlclient)
