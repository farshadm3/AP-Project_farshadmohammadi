#include "Patient.h"
#include <iostream>

Patient::Patient()
{
	this->name = "";
	this->age = 18;
	this->haveHeartProblem = false;
}

Patient::Patient(QString name, int age, bool haveHeartProblem, QString nationalcode)
{
	this->name = name;
	this->age = age;
	this->haveHeartProblem = haveHeartProblem;
    this->nationalcode = nationalcode;
}

void Patient::setName(QString name)
{
	this->name = name;
}
void Patient::setAge(int age)
{
	this->age = age;
}
void Patient::setHeartProblem(bool HeartProblem)
{
    this->haveHeartProblem = HeartProblem;
}

void Patient::setNationalCode(QString nationalcode)
{
    this->nationalcode = nationalcode;
}

QString Patient::getName()
{
	return name;
}
int Patient::getAge()
{
	return age;
}
bool Patient::getHeartProblem()
{
	return haveHeartProblem;
}

QString Patient::getNationalCode()
{
    return nationalcode;
}
