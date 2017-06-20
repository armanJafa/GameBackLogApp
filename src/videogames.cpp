#include "videogames.h"

VideoGames::VideoGames()
{
    title = "";
    platform = "";
    developer = "";
    ESRB = "";
    publisher = "";
    yearOfRelease = 0;
}

VideoGames::~VideoGames()
{

}

QString VideoGames::GetTitle()
{
    return title;
}

QString VideoGames::GetPlatform()
{
    return platform;
}

QString VideoGames::GetDeveloper()
{
    return developer;
}

QString VideoGames::GetESRB()
{
    return ESRB;
}

QString VideoGames::GetPublisher()
{
    return publisher;
}

int VideoGames::GetYearOfRelease()
{
    return yearOfRelease;
}

void VideoGames::SetTitle(QString newTitle)
{
    title = newTitle;
}

void VideoGames::SetPlatform(QString newPlatform)
{
    platform = newPlatform;
}

void VideoGames::SetDeveloper(QString newDeveloper)
{
    developer = newDeveloper;
}

void VideoGames::SetESRB(QString newESRB)
{
    ESRB = newESRB;
}

void VideoGames::SetPublisher(QString newPublisher)
{
    publisher = newPublisher;
}

void VideoGames::SetYearOfRelease(QString newYearOfRelease)
{
    yearOfRelease = newYearOfRelease.toInt();
}
