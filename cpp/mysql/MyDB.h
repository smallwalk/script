#include "m_include.h"

class MyDB
{
	public:
		MyDB();
		~MyDB();
		bool initDB(string host, string user, string pwd, string db_name);
		bool exeSQL(string sql);

	private:
		MYSQL *connection;
		MYSQL_RES *result;
		MYSQL_ROW row;
};
