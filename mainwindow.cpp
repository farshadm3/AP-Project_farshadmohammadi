#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addturnwindow.h"
#include "qstring.h"
#include "deleteturnwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m = new Managment();
    QStringList qlist;
    ui->datatable->setColumnCount(7);
    qlist<<"کد ملی بیمار"<<"نام بیمار"<<"سن بیمار"<<"بیماری قلبی"<<"نوع سرویس"<<"قیمت سرویس"<<"تاریخ نوبت";
    ui->datatable->setHorizontalHeaderLabels(qlist);
    m->ReadFile();
    foreach (Turn *t, m->getTurns())
    {
        ui->datatable->insertRow(ui->datatable->rowCount());
        int fila = ui->datatable->rowCount() - 1;
        ui->datatable->setItem(fila, 0, new QTableWidgetItem(t->getPatient().getNationalCode()));
        ui->datatable->setItem(fila, 1, new QTableWidgetItem(t->getPatient().getName()));
        ui->datatable->setItem(fila, 2, new QTableWidgetItem(QString::number(t->getPatient().getAge())));
        ui->datatable->setItem(fila, 3, new QTableWidgetItem(t->getPatient().getHeartProblem() == true ? "دارد":"ندارد"));
        ui->datatable->setItem(fila, 4, new QTableWidgetItem(t->getService()->getType()));
        ui->datatable->setItem(fila, 5, new QTableWidgetItem(QString::number(t->getService()->getPrice(), 'f', 0)));
        ui->datatable->setItem(fila, 6, new QTableWidgetItem(t->getDate().getDateAsString()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnaddturn_clicked()
{
    AddTurnWindow a(this);
    a.m = this->m;
    a.exec();
    if(a.result)
    {
        ui->datatable->insertRow(ui->datatable->rowCount());
        int fila = ui->datatable->rowCount() - 1;
        ui->datatable->setItem(fila, 0, new QTableWidgetItem(a.t->getPatient().getNationalCode()));
        ui->datatable->setItem(fila, 1, new QTableWidgetItem(a.t->getPatient().getName()));
        ui->datatable->setItem(fila, 2, new QTableWidgetItem(QString::number(a.t->getPatient().getAge())));
        ui->datatable->setItem(fila, 3, new QTableWidgetItem(a.t->getPatient().getHeartProblem() == true ? "دارد":"ندارد"));
        ui->datatable->setItem(fila, 4, new QTableWidgetItem(a.t->getService()->getType()));
        ui->datatable->setItem(fila, 5, new QTableWidgetItem(QString::number(a.t->getService()->getPrice(), 'f', 0)));
        ui->datatable->setItem(fila, 6, new QTableWidgetItem(a.t->getDate().getDateAsString()));
        m->addPatient(a.t);
        m->WriteFile();
    }
}

void MainWindow::on_btndeleteturn_clicked()
{
    DeleteTurnWindow d(this);
    d.m = this->m;
    d.exec();
    if(d.result)
    {
        ui->datatable->setRowCount(0);
        m->ReadFile();
        foreach (Turn *t, m->getTurns())
        {
            ui->datatable->insertRow(ui->datatable->rowCount());
            int fila = ui->datatable->rowCount() - 1;
            ui->datatable->setItem(fila, 0, new QTableWidgetItem(t->getPatient().getNationalCode()));
            ui->datatable->setItem(fila, 1, new QTableWidgetItem(t->getPatient().getName()));
            ui->datatable->setItem(fila, 2, new QTableWidgetItem(QString::number(t->getPatient().getAge())));
            ui->datatable->setItem(fila, 3, new QTableWidgetItem(t->getPatient().getHeartProblem() == true ? "دارد":"ندارد"));
            ui->datatable->setItem(fila, 4, new QTableWidgetItem(t->getService()->getType()));
            ui->datatable->setItem(fila, 5, new QTableWidgetItem(QString::number(t->getService()->getPrice(), 'f', 0)));
            ui->datatable->setItem(fila, 6, new QTableWidgetItem(t->getDate().getDateAsString()));
        }
    }
}
