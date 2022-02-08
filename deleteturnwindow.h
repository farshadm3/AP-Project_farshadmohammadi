#ifndef DELETETURNWINDOW_H
#define DELETETURNWINDOW_H

#include <QDialog>
#include "Managment.h"
#include "Turn.h"

namespace Ui {
class DeleteTurnWindow;
}

class DeleteTurnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteTurnWindow(QWidget *parent = nullptr);
    ~DeleteTurnWindow();
    Managment *m;
    Turn *t;
    bool result;

private slots:
    void on_btnsearch_clicked();

    void on_btndelete_clicked();

private:
    Ui::DeleteTurnWindow *ui;
};

#endif // DELETETURNWINDOW_H
