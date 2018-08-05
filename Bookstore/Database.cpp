#include "Database.h"

Database* Database::instance = NULL;

Database::Database() : driver(get_driver_instance()) 
{
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;

	Connection *con = driver->connect(connection_properties);
	con->setSchema(DB_NAME);

	delete con;
}

Database& Database::getInstance() 
{
	if (Database::instance == NULL)
		instance = new Database();
	
	return *instance;
}

Connection* Database::getConnection() 
{
	try {
		Connection* con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	}
	catch (SQLException& e) {
		cout << e.what();
	}
	return 0;
}