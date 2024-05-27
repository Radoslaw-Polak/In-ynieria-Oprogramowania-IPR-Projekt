#include "SQLmanager.h"
using namespace std;

SQLmanager::SQLmanager() {
    try {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);

    }
    catch (sql::SQLException e) {
        system("pause");
        exit(1);

    }
    con->setSchema("kino-ipr");

}

SQLmanager::~SQLmanager() {
    delete con;

}

SQLmanager& SQLmanager::getInstance() {
    static SQLmanager instance;
    return instance;

}

list<string> SQLmanager::executeQuery(string q, int expected_cols, bool updateOnly) {
    list<string> out = {};
    if (updateOnly) {
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement(q);
        //pstmt->setString(1, "banana");
        //pstmt->setInt(2, 150);
        pstmt->executeUpdate();
        delete pstmt;
        return out;

    }
    else {
        sql::Statement* stmt;
        sql::ResultSet* res;
        stmt = con->createStatement();
        res = stmt->executeQuery(q);
        string temp;
        while (res->next()) {
            // Parses all rows into single, / separated string
            temp = "";
            for (int i = 0; i < expected_cols; i++) {
                temp += res->getString(i + 1);
                temp += "~";

            }
            out.push_back(temp);

        }
        delete res;
        delete stmt;

    }
    return out;

}