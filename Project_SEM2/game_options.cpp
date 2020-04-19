#include "game_options.h"
#include "ui_game_options.h"


Game_Options::Game_Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game_Options)
{
    ui->setupUi(this);

}

Game_Options::~Game_Options()
{
    delete ui;
}


void Game_Options::on_Single_clicked()
{
    Game::Get().set_game_mode(0);
}

void Game_Options::on_Multi_clicked()
{
     Game::Get().set_game_mode(1);
}

void Game_Options::on_Timed_clicked()
{
    Game::Get().set_win_condition(0);

}

void Game_Options::on_Goals_clicked()
{
    Game::Get().set_win_condition(1);
}

void Game_Options::on_Game_Options_2_clicked()
{
        wincondition dialog;
        dialog.SetText(Game::Get().GetWinCondition());
        dialog.setModal(1);
        dialog.exec();


 std::string text;

Game::Get().getPlayers(0).SetNumPlayers(ui->No_Players->currentText().toInt());
Game::Get().getPlayers(1).SetNumPlayers(ui->No_Players->currentText().toInt());

    for (int i=0; i<2; i++){

for (int j=-1; j< Game::Get().getPlayers(i).GetNumPlayers(); j++){

    if (j==-1){
        text = "Team ";
        text += std::to_string(i+1);
        text = text + std::string(" please enter your name");

    }
    else{
        text = Game::Get().getPlayers(i).GetTeamName()+ std::string(" please enter player ");
         text += std::to_string(j+1);
          text = text + std::string(" number");
    }

    Team_Select Dialog;
    Dialog.SetText(text,j,i);
    Dialog.setModal(1);
    Dialog.exec();

}


    }

Game::Get().coin_toss();
QMessageBox msg;
   msg.setText(QString::fromStdString(Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName())+(" won the coin toss"));
   msg.exec();


   maingame = new MainGame();
   maingame->Setup();
   maingame->show();





}
