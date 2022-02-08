#ifndef ADDTURN_H
#define ADDTURN_H

#include <QDialog>

namespace Ui {
class AddTurn;
}

class AddTurn : public QDialog
{
    Q_OBJECT

public:
    explicit AddTurn(QWidget *parent = nullptr);
    ~AddTurn();

private:
    Ui::AddTurn *ui;
};

#endif // ADDTURN_H
