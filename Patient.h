#pragma once

#ifndef __PATIENT_H__
#define _PATIENT_H__

#include "qstring.h"

using namespace std;

class Patient
{
private:
    QString nationalcode;
    QString name;
	int age;
	bool haveHeartProblem;
public:
	Patient();
    Patient(QString, int, bool, QString);

    void setName(QString name);
    void setNationalCode(QString nationalcode);
    void setAge(int age);
    void setHeartProblem(bool HeartProblem);

    QString getName();
    QString getNationalCode();
	int getAge();
	bool getHeartProblem();
};
#endif
