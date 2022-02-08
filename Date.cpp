#include "Date.h"

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1400;
}

Date::Date(int year, int month, int day)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

QString Date::getDateAsString()
{
    return (QString::number(year) + "/" + QString::number(month) + "/" + QString::number(day));
}
