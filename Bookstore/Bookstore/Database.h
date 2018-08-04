#ifndef DATABASE_H
#define DATABASE_H

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace sql;
using namespace std;

#define DB_NAME "bookStore_db"
#define DB_HOST "tcp://127.0.0.1/"
#define DB_PORT 3306
#define DB_USER "root"
#define DB_PASS "shenkar1234"

#define CON Database& db = Database::getInstance(); Connection* con = db.getConnection();

class Database 
{
	static Database* instance; // singleton instance
	Driver* driver;
	ConnectOptionsMap connection_properties;
	Database(); // private CTOR (singleton)

public:
	static Database& getInstance();
	Connection *getConnection();
	virtual ~Database() {}
};

#endif