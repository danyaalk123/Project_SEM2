#ifndef MAINMENU_H
#define MAINMENU_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDialog>
#include "game_options.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_Exit_clicked();

    void on_Start_clicked();

    void on_How_clicked();

private:
    Ui::MainMenu *ui;
    Game_Options *Game_Options;

};
#endif // MAINMENU_H
