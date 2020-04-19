#ifndef WINCONDITION_H
#define WINCONDITION_H

#include <QtWidgets/QDialog>
#include "Game.h"

namespace Ui {
class wincondition;
}

class wincondition : public QDialog
{
    Q_OBJECT

public:
    explicit wincondition(QWidget *parent = nullptr);
    ~wincondition();
   void SetText(int);

private slots:
   void on_Win_Button_clicked();

private:
    Ui::wincondition *ui;

};

#endif // WINCONDITION_H
