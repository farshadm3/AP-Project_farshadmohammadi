#pragma once

#ifndef __TURN_H__
#define _TURN__

#include "Patient.h"
#include "Date.h"
#include "Service.h"

using namespace std;

class Turn
{
private:
	Patient patient;
	Date date;
	Service* service;
public:
	Turn() {}
	Turn(Patient, Date, Service*);

    Patient getPatient();
    Date getDate();
	Service* getService();
    void setService(Service*);
    void setDate(Date);
    void setPatient(Patient);
    QString ToString();
};
#endif
