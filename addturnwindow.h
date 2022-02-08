#ifndef ADDTURNWINDOW_H
#define ADDTURNWINDOW_H

#include <QDialog>
#include "Turn.h"
#include "Managment.h"

namespace Ui {
class AddTurnWindow;
}

class AddTurnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddTurnWindow(QWidget *parent = nullptr);
    ~AddTurnWindow();
    Managment *m;
    Turn *t;
    bool result;

private slots:
    void on_cmbservicetype_currentIndexChanged(int index);

    void on_btnaedturn_clicked();

private:
    Ui::AddTurnWindow *ui;
};

#endif // ADDTURNWINDOW_H
