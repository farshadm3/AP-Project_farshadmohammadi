#include "Service.h"


Service::Service()
{
	type = "";
	price = 0;
}
Service::Service(QString type, double price)
{
	this->type = type;
	this->price = price;
}

void Service::setType(QString type)
{
	this->type=type;

}
void Service::setPrice(double price)
{
	this->price = price;
}

double Service::getPrice()
{
	return price;
}
QString Service::getType()
{
	return type;
}

Ortodensi::Ortodensi()
{
    setType("ارتودنسی");
	setPrice(1000000);
}

JermGiri::JermGiri()
{
    setType("جرمگیری");
	setPrice(500000);
}

Implant::Implant()
{
    setType("ایمپلنت");
	setPrice(1500000);
}

Lamineyt::Lamineyt()
{
    setType("لمینیت");
	setPrice(2000000);
}
