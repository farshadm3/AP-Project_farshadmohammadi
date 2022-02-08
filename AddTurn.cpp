#include "AddTurn.h"
#include "ui_AddTurn.h"
#include "qmessagebox.h"

AddTurn::AddTurn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTurn)
{
    ui->setupUi(this);
}

AddTurn::~AddTurn()
{
    delete ui;
}
