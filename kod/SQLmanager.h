#ifndef SQL
#define SQL
#include "singleton.h"
#include <string>
#include <list>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/prepared_statement.h>

class SQLmanager : singleton {
private:
    // localhost
    const std::string server = "tcp://127.0.0.1:3306";
    const std::string username = "root";
    const std::string password = "admin";
    sql::Driver* driver;
    sql::Connection* con;
    SQLmanager();
public:
    ~SQLmanager();
    static SQLmanager& getInstance();
    ///@brief Executes query + parses output to string
    ///@param expected_cols Expected number of output columns (indexing from 1)
    ///@param updateOnly Perform update/insert instead of query
    std::list<std::string> executeQuery(std::string q, int expected_cols, bool updateOnly = false);

};

#endif