#include "database.h"

/*!
 * \brief database::database
 * \param path Path to SQL database file
 * \param driver QString identifier for the specific flavor of SQL we are using.
 */
database::database(QString path, QString driver)
{
    setHostName("localhost");
    setDatabaseName(path);

    //If the database successfully opens
    if(open())
    {
        //Output the last error message from the database
        qDebug() << "Database opened successfully";
    }
    else
    {
        //Output the last error message from the database.
        qDebug() << this->lastError().text();
    }

    // Activate foreign key support.
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;");
}

/*!
 * \brief database::AddGame
 * Adds new game to the database with the following attributes
 * \param gameTitle
 * \param gamePlatform
 * \param gameDev
 * \param gameESRB
 * \param gamePublisher
 * \param yearOfRelease
 * \return true if it worked else false
 */
bool database::AddGame(QString gameTitle, QString gamePlatform, QString gameDev, QString gameESRB, QString gamePublisher, int yearOfRelease)
{
    QSqlQuery query;
    query.prepare("INSERT INTO VideoGames(Title, YearOfRelease, Platform, ESRB, Developer, Publisher)"
                  "VALUES(:Title,:YearOfRelease,:Platform,:ESRB,:Developer,:Publisher)");
    query.bindValue(":Title", gameTitle);
    query.bindValue(":YearOfRelease", yearOfRelease);
    query.bindValue(":Platform", gamePlatform);
    query.bindValue(":ESRB", gameESRB);
    query.bindValue(":Developer", gameDev);
    query.bindValue(":Publisher", gamePublisher);
    if(query.exec())
    {
        return true;
    }

    qDebug() << query.lastError().text();
    return false;
}

/*!
 * \brief database::removeGame
 * Removes game from database based on the following attributes
 * \param gameTitle
 * \return
 */
bool database::removeGame(QString gameTitle)
{
    QSqlQuery query;
    query.prepare("DELETE FROM VideoGames WHERE Title = ?");
    query.addBindValue(gameTitle);
    if(query.exec())
    {
        return true;
    }

    qDebug() << query.lastError().text();
    return false;
}
