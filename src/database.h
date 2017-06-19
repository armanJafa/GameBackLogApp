#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QtSql>

/*!
 * \brief The database class
 */
class database : public QSqlDatabase
{
public:
    ///Create database from specified db file and driver
    database(QString path, QString driver);

    // Mutators
    ///Add a game to the Video Game database.
    bool AddGame(QString gameTitle, QString gamePlatform, QString gameDev, QString gameESRB, QString gamePublisher, int yearOfRelease );


};

#endif // DATABASE_H
