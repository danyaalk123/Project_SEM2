#ifndef TEAM_SELECT_H
#define TEAM_SELECT_H

#include <QtWidgets/QDialog>
#include "Game.h"
#include <QtWidgets/QMessageBox>

namespace Ui {
class Team_Select;
}

class Team_Select : public QDialog
{
    Q_OBJECT

public:
    explicit Team_Select(QWidget *parent = nullptr);
     void SetText(string,int,int);
    ~Team_Select();

private slots:

    void on_InputTeam_clicked();


private:
    Ui::Team_Select *ui;

    int team;
    int player;

};

#endif // TEAM_SELECT_H
