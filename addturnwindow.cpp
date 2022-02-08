#include "addturnwindow.h"
#include "ui_addturnwindow.h"
#include "addturnwindow.h"
#include "qmessagebox.h"
#include "Turn.h"
#include "Date.h"
#include "Patient.h"

AddTurnWindow::AddTurnWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTurnWindow)
{
    ui->setupUi(this);
    t = new Turn();
    result = false;
    ui->cmbheartproblem->addItem("ندارد");
    ui->cmbheartproblem->addItem("دارد");
    ui->cmbheartproblem->setCurrentIndex(0);
    ui->cmbservicetype->addItem("ارتودنسی");
    ui->cmbservicetype->addItem("جرم گیری");
    ui->cmbservicetype->addItem("ایمپلنت");
    ui->cmbservicetype->addItem("لمینیت");
    ui->cmbservicetype->setCurrentIndex(0);
    ui->txtage->setInputMask("99");
    ui->txtdate->setInputMask("9999/99/99");
    ui->txtnationalcode->setInputMask("9999999999");
}

AddTurnWindow::~AddTurnWindow()
{
    delete ui;
}

void AddTurnWindow::on_cmbservicetype_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->lblprice->setText("1000000");
    }
    else if(index == 1)
    {
        ui->lblprice->setText("500000");
    }
    else if(index == 2)
    {
        ui->lblprice->setText("1500000");
    }
    else
    {
        ui->lblprice->setText("2000000");
    }
}

void AddTurnWindow::on_btnaedturn_clicked()
{
    QString pcode = ui->txtnationalcode->text().trimmed().replace(" ", "");
    if(pcode.length() < 10)
    {
        QMessageBox::question(this, "پیغام", "لطفا کد ملی بیمار را وارد کنید", QMessageBox::Ok);
        ui->txtnationalcode->setFocus();
        return;
    }
    QString pname = ui->txtname->text().trimmed();
    if(pname == "")
    {
        QMessageBox::question(this, "پیغام", "لطفا نام بیمار را وارد کنید", QMessageBox::Ok);
        ui->txtname->setFocus();
        return;
    }
    try
    {
        QString ag = ui->txtage->text().trimmed();
        if(ag == "")
        {
            QMessageBox::question(this, "پیغام", "لطفا سن بیمار را وارد کنید", QMessageBox::Ok);
            ui->txtage->setFocus();
            return;
        }
        int age = ag.toInt();
        if(age <= 0)
        {
            QMessageBox::question(this, "پیغام", "سن بیمار نمی تواند کمتر یا مساوی صفر باشد", QMessageBox::Ok);
            ui->txtage->setFocus();
            return;
        }
        switch (ui->cmbservicetype->currentIndex())
        {
        case 0:
            t->setService(new Ortodensi());
            break;
        case 1:
            t->setService(new JermGiri());
            break;
        case 2:
            t->setService(new Implant());
            break;
        case 3:
            t->setService(new Lamineyt());
            break;
        }
        QString dt = ui->txtdate->text().trimmed();
        QStringList datasplit = dt.split("/");
        if(datasplit.length() >= 3)
        {
            if(datasplit[0].trimmed() == "" || datasplit[1].trimmed() == "" || datasplit[2].trimmed() == "")
            {
                QMessageBox::question(this, "پیغام", "تاریخ وارد شده نامعتبر است", QMessageBox::Ok);
                ui->txtdate->setFocus();
                return;
            }
            Date *d = new Date(datasplit[0].toInt(), datasplit[1].toInt(), datasplit[2].toInt());
            if(d->getYear() >= 1400 && d->getYear() <= 1405 && d->getMonth() > 0 && d->getMonth() <= 12 && d->getDay() >= 1 && d->getDay() <= 31)
            {
                if((d->getMonth() <= 6 && d->getDay() <= 31) || (d->getDay() <= 30))
                {
                    if(m->GetTurn(pcode) == nullptr)
                    {
                        Patient *p = new Patient();
                        p->setNationalCode(pcode);
                        p->setName(pname);
                        p->setAge(age);
                        p->setHeartProblem(ui->cmbheartproblem->currentIndex() == 0 ? false:true);
                        t->setPatient(*p);
                        t->setDate(*d);
                        result = true;
                        this->close();
                    }
                    else
                    {
                        QMessageBox::question(this, "پیغام", "برای این کد ملی قبلا نوبت ثبت شده است", QMessageBox::Ok);
                        ui->txtnationalcode->setFocus();
                        return;
                    }
                }
                else
                {
                    QMessageBox::question(this, "پیغام", "تاریخ وارد شده نامعتبر است", QMessageBox::Ok);
                    ui->txtdate->setFocus();
                    return;
                }
            }
            else
            {
                QMessageBox::question(this, "پیغام", "تاریخ وارد شده نامعتبر است", QMessageBox::Ok);
                ui->txtdate->setFocus();
                return;
            }
        }
    } catch (QString)
    {
        QMessageBox::question(this, "اطلاعات وارد شده نامعتبر است", "پیغام", QMessageBox::Ok);
    }
}
