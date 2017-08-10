#include "database.h"

database::database()
{
}
QSqlDatabase database::db = QSqlDatabase::addDatabase("QMYSQL");
bool database::Open()
{
    db.setHostName(QLatin1String("localhost"));
    db.setUserName("root");
    db.setPassword("hello_world");
//    db.setPassword("bonjour");
//    db.setDatabaseName("user");
    db.setDatabaseName("ChatClient");
    if(!db.open())
    {
        return false;
    }
    return true;
}
void database::Close()
{
    db.close();
}

