#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}




void MainMenu::on_Exit_clicked()
{
QApplication::quit();
}

void MainMenu::on_Start_clicked()
{
    hide();
    Game_Options = new class::Game_Options(this);
    Game_Options -> show();

}

void MainMenu::on_How_clicked()
{

}
