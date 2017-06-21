#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include <QString>

class VideoGames
{
public:
    VideoGames();       //constructor
    ~VideoGames();      //destructor

    QString GetTitle();            //returns the title of the game
    QString GetPlatform();         //returns the platform of the game
    QString GetDeveloper();        //returns the developer of the game
    QString GetESRB();             //returns the ESRB of the game
    QString GetPublisher();        //returns the Publisher of the game
    int GetYearOfRelease();        //returns the year of release of the game

    void SetTitle(QString newTitle);                   //Sets the title for a game
    void SetPlatform(QString newPlatform);             //Sets the platform for a game.
    void SetDeveloper(QString newDeveloper);           //Sets the developer for a game.
    void SetESRB(QString newESRB);                     //Sets the ESRB of a game
    void SetPublisher(QString newPublisher);           //Sets the publisher of a game.
    void SetYearOfRelease(int newYearOfRelease);       //Sets the year of release of a game

private:
    QString title;        //Video Game title
    QString platform;     //Video Game platform (pc, ps4, xbox, etc.)
    QString developer;    //Video Game Developer
    QString ESRB;         //Video Game ESRB rating
    QString publisher;    //Video Game Publisher
    int yearOfRelease;    //The year of release of a game
};

#endif // VIDEOGAMES_H
