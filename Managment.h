#pragma once

#ifndef __MANAGMENT_H__
#define _MANAGMENT__

#include <queue>
#include "Turn.h"
#include "qlist.h"
#include "qfile.h"
#include "qdatastream.h"
#include "qtextstream.h"

using namespace std;

class Managment
{
private:
    QList<Turn*> patients;
public:
	Managment();

    void addPatient(Turn *t);
    QList<Turn*> getTurns();
    int getQueueLength();
    void WriteFile();
    void ReadFile();
    Turn* GetTurn(QString pnationalcode);
    void DeleteTurn(Turn *t);
};
QDataStream &operator<<(QDataStream& out, Turn& turn);
QDataStream &operator>>(QDataStream& in, Turn* turn);
#endif
