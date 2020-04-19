#ifndef MAINGAME_H
#define MAINGAME_H

#include <QtWidgets/QMainWindow>
#include "Game.h"
#include <vector>
#include "Dice.h"
#include <QtWidgets/QMessageBox>
#include <Qtcore/QTimer>
#include <Qtcore/QDateTime>

namespace Ui {
class MainGame;
}

class MainGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGame(QWidget *parent = nullptr);
    ~MainGame();
    void Setup();
      void SetCombo();
      void ResetVector();
      void Update();


private slots:
      void on_RollDice_clicked();
      void updatetimer();

private:
    Ui::MainGame *ui;
    std::vector <int>  Players[2];
       int choice1;
       int choice2;
       int count;
       QTimer *timer;
};

#endif // MAINGAME_H
