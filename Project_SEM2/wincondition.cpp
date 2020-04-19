#include "wincondition.h"
#include "ui_wincondition.h"

wincondition::wincondition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wincondition)
{
    ui->setupUi(this);
}

wincondition::~wincondition()
{
    delete ui;
}

void wincondition::SetText(int num){

    if (num){

        ui->Text->setText("Please enter how many goals to win");

    }
    else{

        ui->Text->setText("Please enter how many seconds you want the game to last");

    }
}

void wincondition::on_Win_Button_clicked()
{
    if (Game::Get().GetWinCondition()){
        Game::Get().set_goals_to_win(ui->Win->text().toInt());
        Game::Get().set_time_to_win(-1);

    }
    else{
        Game::Get().set_time_to_win(ui->Win->text().toInt());
                Game::Get().set_goals_to_win(-1);
    }
    this->accept();
}
