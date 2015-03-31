#include "m_include.h"
#include "MyDB.h"

int main() 
{
	MyDB db;
	db.initDB("localhost", "", "", "test");
	db.exeSQL("SELECT * FROM t_test_user");
	return 0;
}
