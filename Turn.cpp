#include "Turn.h"

Patient Turn::getPatient()
{
	return patient;
}
Date Turn::getDate()
{
	return date;
}
Service* Turn::getService()
{
	return service;
}

Turn::Turn(Patient patient, Date date, Service* service)
{
	this->patient = patient;
	this->date = date;
	this->service = service;
}
void Turn::setService(Service* service)
{
    this->service = service;
}
void Turn::setDate(Date date)
{
    this->date = date;
}
void Turn::setPatient(Patient patient)
{
    this->patient = patient;
}
QString Turn::ToString()
{
    QString pnationalcode = this->getPatient().getNationalCode();
    QString pname = this->getPatient().getName();
    int age = this->getPatient().getAge();
    bool heartproblem = this->getPatient().getHeartProblem();
    QString servicetype = this->getService()->getType();
    QString pr = QString::number(this->getService()->getPrice(), 'f', 0);
    int year = this->getDate().getYear();
    int month = this->getDate().getMonth();
    int day =this->getDate().getDay();
    QString str = "";
    str += pnationalcode + ",";
    str += pname + ",";
    str += QString::number(age) + ",";
    str += QString::number(heartproblem) + ",";
    str += servicetype + ",";
    str += pr +",";
    str += QString::number(year) + ",";
    str += QString::number(month) + ",";
    str += QString::number(day);
    return str;
}
