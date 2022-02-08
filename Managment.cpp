#include "Managment.h"
Managment::Managment()
{

}

void Managment::addPatient(Turn *t)
{
    patients.append(t);
}
QList<Turn*> Managment::getTurns()
{
    return patients;
}

int Managment::getQueueLength()
{
    return patients.length();
}

void Managment::WriteFile()
{
    QString path = "plist.bin";
    QFile file(path);
    if (file.open(QFile::WriteOnly | QFile::Text))
    {
        for(int i = 0; i < patients.size(); i++)
        {
             Turn t = *patients[i];
             QTextStream out(&file);
             out.setCodec("UTF-8");
             QString q = t.ToString() + "\n";
             q = q.toUtf8();
             out<< q;
        }
    }
    file.flush();
    file.close();
}
void Managment::ReadFile()
{
    patients.clear();
    QString path = "plist.bin";
    QFile file(path);
    if(file.exists())
    {
      if (file.open(QFile::ReadOnly | QFile::Text))
      {
          QTextStream in(&file);
          in.setCodec("UTF-8");
          QString q = in.readAll();
          QStringList qlist = q.split("\n");
          for(int i = 0; i < qlist.length(); i++)
          {
              Turn *t = new Turn();
              QStringList tinfo = qlist[i].split(",");
              if(tinfo.length() == 9)
              {
                  try {
                      QString pnationalcode = tinfo[0];
                      QString pname = tinfo[1];
                      int age = tinfo[2].toInt();
                      bool heartproblem = tinfo[3].toInt();
                      QString servicetype = tinfo[4];
                      double price = tinfo[5].toDouble();
                      int year = tinfo[6].toInt();
                      int month = tinfo[7].toInt();
                      int day = tinfo[8].toInt();
                      t->setPatient(*new Patient(pname, age, heartproblem, pnationalcode));
                      t->setService(new Service(servicetype, price));
                      t->setDate(*new Date(day, month, year));
                      patients.append(t);
                  } catch (QString) {

                  }
              }
          }
          file.close();
      }
    }
}

Turn* Managment::GetTurn(QString pnationalcode)
{
    for(int i = 0; i < patients.length(); i++)
    {
        if(patients[i]->getPatient().getNationalCode() == pnationalcode)
        {
            return patients[i];
        }
    }
    return nullptr;
}

void Managment::DeleteTurn(Turn *t)
{
    patients.removeAll(t);
}
