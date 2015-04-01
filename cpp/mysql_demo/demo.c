#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <unistd.h>
#include <string.h>
#include "demo.h"

int main(int argc, char *argv[])
{
	MYSQL *conn;
	MYSQL *conn_str;

	conn = mysql_init(NULL);
	if (!conn) {
		fprintf(stderr, "mysql_init failed\n");
		return 1;
	}

	const char *host = "localhost";
	const char *user = "";
	const char *pass = "";
	const char *dbname = "test";
	unsigned int port_number = 0;

	int res;
	conn_str = mysql_real_connect(conn, host, user, pass, dbname, port_number, NULL, 0);
	if (conn_str) {
		printf("Connected success\n");
	}
	else {
		fprintf(stderr, "cossssnnection failed\n");
		if (mysql_errno(conn)) {
			fprintf(stderr, "Connected error %d: %s\n", mysql_errno(conn), mysql_error(conn));
		}
	}
	res = mysql_query(conn, "SELECT * FROM t_test_user");
	MYSQL_RES *res_ptr;
	MYSQL_ROW rows;
	
	struct user u[15];

	res_ptr = mysql_store_result(conn);

	int num = 0;
	num = mysql_num_rows(res_ptr);
	printf("num:%d\n", num);

	int i = 0;
	while((rows = mysql_fetch_row(res_ptr))) {
		printf("id:%s\t", rows[0]);
		printf("name:%s\n", rows[1]);
		sscanf(rows[0], "%d", &u[i].id);
		strcpy(u[i].name, rows[1]);
		i++;
	}

	printf("%s\n", u[2].name);
	printf("%d\n", u[2].id);
	mysql_free_result(res_ptr);
	/*

	char name[10];
	printf("Input name:");
	scanf("%s", name);

	char sql[100];
	sprintf(sql, "INSERT INTO t_test_user (name) VALUES ('%s')", name); 

	conn_str = mysql_real_connect(conn, host, user, pass, dbname, port_number, NULL, 0);
	if (conn_str) {
		printf("Connected success\n");
	}
	else {
		fprintf(stderr, "cossssnnection failed\n");
		if (mysql_errno(conn)) {
			fprintf(stderr, "Connected error %d: %s\n", mysql_errno(conn), mysql_error(conn));
		}
	}
	res = mysql_query(conn, sql);
	if (!res) {
		printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(conn));
	}
	else {
		fprintf(stderr, "Insert error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	}
	*/

	/*
	sleep(5);

	res = mysql_query(conn, "INSERT INTO t_test_user (name) VALUES ('test2')");
	if (!res) {
		printf("Inserted %lu rows\n", (unsigned long) mysql_affected_rows(conn));
	}
	else {
		fprintf(stderr, "Insert error %d: %s\n", mysql_errno(conn), mysql_error(conn));
	}
	*/
	mysql_close(conn);
	return 0;
}
