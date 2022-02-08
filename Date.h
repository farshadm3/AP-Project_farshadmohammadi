#pragma once

#ifndef __DATE_H__
#define _DATE_H__

#include <iostream>
#include "qstring.h"

using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int, int, int);
    int getYear();
    int getMonth();
    int getDay();
    QString getDateAsString();
};
#endif
