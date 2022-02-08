#pragma once

#ifndef __SERVICE_H__
#define _SERVICE__

#include <iostream>
#include "qstring.h"

using namespace std;

class Service
{
protected:
    QString type;
	double price;
public:
	Service();
    Service(QString, double);
    virtual void setType(QString);
	virtual void setPrice(double);

	virtual double getPrice();
    virtual QString getType();
};


class Ortodensi :public Service
{
public:
	Ortodensi();
};

class JermGiri :public Service
{
public:
	JermGiri();
};

class Implant :public Service
{
public:
	Implant();
};

class Lamineyt :public Service
{
public:
	Lamineyt();
};
#endif
