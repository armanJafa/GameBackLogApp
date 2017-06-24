#include "database.h"


/*!
 * \brief Database::Database
 * \param path Path to SQL database file
 * \param driver QString identifier for the specific flavor of SQL we are using
 * and initializes the driver in inherited class
 */
Database::Database(QString path, QString driver) : QSqlDatabase(addDatabase(driver))
{
    setHostName("localhost");
    setDatabaseName(path);

    //If the database successfully opens
    if(open())
    {
        QSqlQuery create;
        create.exec("CREATE TABLE VideoGames ( `Title` TEXT, `YearOfRelease` INTEGER, `Platform` TEXT, `ESRB` TEXT, `Developer` TEXT, `Publisher` TEXT )");

        //Output the last error message from the database
        qDebug() << "Database opened successfully";
        qDebug() << this->lastError().text();
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
 * \brief Database::AddGame
 * Adds new game to the database with the following attributes
 * \param gameTitle
 * \param gamePlatform
 * \param gameDev
 * \param gameESRB
 * \param gamePublisher
 * \param yearOfRelease
 * \return true if it worked else false
 */
bool Database::AddGame(QString gameTitle, QString gamePlatform, QString gameDev, QString gameESRB, QString gamePublisher, int yearOfRelease)
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
 * \brief Database::removeGame
 * Removes game from database based on the following attributes
 * \param gameTitle
 * \return
 */
bool Database::removeGame(QString gameTitle)
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

QVector<VideoGames> Database::GetAllGames()
{
    QVector<VideoGames> gamesList;
    QSqlQuery query;
    query.exec("SELECT * From VideoGames");

    if(query.isValid())
    {
        while(query.next())
        {
            VideoGames item;
            item.SetTitle(query.record().field("Title").value().toString());
            item.SetYearOfRelease(query.record().field("YearOfRelease").value().toInt());
            item.SetPlatform(query.record().field("Platform").value().toString());
            item.SetESRB(query.record().field("ESRB").value().toString());
            item.SetDeveloper(query.record().field("Developer").value().toString());
            item.SetPublisher(query.record().field("Publisher").value().toString());

            gamesList.push_back(item);
        }
    }


    return gamesList;
}
