#ifndef MYSQL_MYSQLXX_H
#define MYSQL_MYSQLXX_H

#include <string>
#include <mysql/mysql.h>
#include <vector>
#include <map>

class MysqlXX
{
    public :
        typedef std::map<std::string, std::string> Row;
        typedef std::vector<Row>::iterator iterator;
        typedef std::vector<Row>::const_iterator const_iterator;

        MysqlXX();
        ~MysqlXX();

        bool Connect(std::string host,
                     std::string user,
                     std::string passwd,
                     std::string db,
                     unsigned int port = 3306);
        bool SetNames(std::string csname);
        std::string GetNames() const;
        bool Query(std::string sql);

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

        int GetLastErrno() const;
        std::string GetLastError() const;

    private:
        MYSQL* connection;
        int errno;
        std::string error;
        std::string names;
        std::vector<Row> rows;
};

#endif
