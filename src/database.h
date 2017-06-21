#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include "videogames.h"

/*!
 * \brief The Database class
 */
class Database : public QSqlDatabase
{
public:
    ///Create database from specified db file and driver
    Database(QString path, QString driver);

    // Mutators
    ///Add a game to the Video Game database.
    bool AddGame(QString gameTitle, QString gamePlatform, QString gameDev, QString gameESRB, QString gamePublisher, int yearOfRelease );

    ///Remove a game from the Video Game database
    bool removeGame(QString gameTitle);

    //Accessors
    ///Return a QVector of videogames from VideoGames Table
    QVector<VideoGames> GetAllGames();
};

#endif // DATABASE_H
