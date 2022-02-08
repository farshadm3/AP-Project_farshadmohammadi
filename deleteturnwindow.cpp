#include "deleteturnwindow.h"
#include "ui_deleteturnwindow.h"
#include "qmessagebox.h"
#include "Turn.h"

DeleteTurnWindow::DeleteTurnWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteTurnWindow)
{
    ui->setupUi(this);
    ui->txtnationalcode->setInputMask("9999999999");
    t = nullptr;
    result = false;
}

DeleteTurnWindow::~DeleteTurnWindow()
{
    delete ui;
}

void DeleteTurnWindow::on_btnsearch_clicked()
{
    QString pcode = ui->txtnationalcode->text().trimmed().replace(" ", "");
    if(pcode.length() < 10)
    {
        QMessageBox::question(this, "پیغام", "لطفا کد ملی بیمار را وارد کنید", QMessageBox::Ok);
        ui->txtnationalcode->setFocus();
        return;
    }
    t = m->GetTurn(pcode);
    if(t == nullptr)
    {
        QMessageBox::question(this, "پیغام", "کد ملی وارد شده یافت نشد", QMessageBox::Ok);
        ui->txtnationalcode->setFocus();
        return;
    }
    ui->lblnationalcode->setText(t->getPatient().getNationalCode());
    ui->lblname->setText(t->getPatient().getName());
    ui->lblage->setText(QString::number(t->getPatient().getAge()));
}

void DeleteTurnWindow::on_btndelete_clicked()
{
    if(t == nullptr)
    {
        QMessageBox::question(this, "پیغام", "بیماری انتخاب نشده است", QMessageBox::Ok);
        ui->txtnationalcode->setFocus();
        return;
    }
    m->DeleteTurn(t);
    m->WriteFile();
    result = true;
    this->close();
}
