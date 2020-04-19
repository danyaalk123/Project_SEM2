#ifndef GAME_OPTIONS_H
#define GAME_OPTIONS_H

#include <QtWidgets/QDialog>
#include "Game.h"
#include "team_select.h"
#include "maingame.h"
#include "wincondition.h"

namespace Ui {
class Game_Options;
}

class Game_Options : public QDialog
{
    Q_OBJECT

public:
    explicit Game_Options(QWidget *parent = nullptr);
    ~Game_Options();

private slots:


    void on_Single_clicked();

    void on_Multi_clicked();

    void on_Timed_clicked();

    void on_Goals_clicked();

    void on_Game_Options_2_clicked();

private:
    Ui::Game_Options *ui;
  MainGame *maingame;

};

#endif // GAME_OPTIONS_H
