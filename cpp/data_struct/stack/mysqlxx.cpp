#include "include/mysqlxx.h"
#include <mysql/mysql.h>
#include <iostream>

using namespace std;

MysqlXX::MysqlXX() : connection(NULL), names("utf-8")
{   
    connection = mysql_init(connection);
    if (connection == NULL) {
        errno = mysql_errno(connection);
        error = mysql_error(connection);
        cout << error << endl;
        exit(1);
    }
}

bool MysqlXX::Connect(const std::string host,
        const std::string user,
        const std::string passwd,
        const std::string db,
        unsigned int port)
{
    if (mysql_real_connect(connection, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, NULL, 0) == NULL) {
        errno = mysql_errno(connection);
        error = mysql_error(connection);
        return false;
    }
    //return SetNames(names);
    return true;
}

MysqlXX::~MysqlXX()
{
    if (connection != NULL) {
        mysql_close(connection);
        connection = NULL;
    }
}

bool MysqlXX::SetNames(std::string csname)
{
    int status;
    status = mysql_set_character_set(connection, csname.c_str());
    if (status != 0) {
        errno = mysql_errno(connection);
        error = mysql_error(connection);
        return false;
    }

    names = csname;
    return true;
}

string MysqlXX::GetNames() const 
{
    return names;
}

bool MysqlXX::Query(std::string sql)
{
    int status;
    status = mysql_query(connection, sql.c_str());
    if (status != 0) {
        errno = mysql_errno(connection);
        error = mysql_error(connection);
        return false;
    }
    MYSQL_RES *result = mysql_store_result(connection);
    unsigned int field_count = mysql_field_count(connection);


    if (result) {
        unsigned int i = 0;
        std::map<unsigned int, std::string> field_id_2_field_name;
        MYSQL_FIELD* field;
        while((field = mysql_fetch_field(result))) {
            field_id_2_field_name[i] = field->name;
            ++i;
        }
        MYSQL_ROW mysql_row;
        Row row;
        while ((mysql_row = mysql_fetch_row(result))) {
            unsigned long *lengths = mysql_fetch_lengths(result); 
            for (int i=0; i < field_count; i++) {
                if (mysql_row[i] == NULL) {
                    row[field_id_2_field_name[i]] = "";
                }
                else {
                    row[field_id_2_field_name[i]] = string(mysql_row[i], lengths[i]);
                }
            }
            rows.push_back(row);
        }
        mysql_free_result(result);
        return true;
    }
    else {
       if (field_count == 0) {
            //query does not return data (it was not a select)
            return false;
       }
       else {
            //mysql_store_result() should have returned data
            errno = mysql_errno(connection);
            error = mysql_error(connection);
            return false;
       }
    }
}

MysqlXX::iterator MysqlXX::begin()
{
    return rows.begin();
}

MysqlXX::const_iterator MysqlXX::begin() const
{
    return rows.begin();
}

MysqlXX::iterator MysqlXX::end()
{
    return rows.end();
}

MysqlXX::const_iterator MysqlXX::end() const
{
    return rows.end();
}

int MysqlXX::GetLastErrno() const
{
    return errno;
}

std::string MysqlXX::GetLastError() const
{
    return error;
}
