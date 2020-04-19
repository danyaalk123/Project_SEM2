#include "maingame.h"
#include "ui_maingame.h"

MainGame::MainGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainGame)
{
    ui->setupUi(this);
    if (Game::Get().GetWinCondition()==0){

        timer =new QTimer (this);
        connect (timer, SIGNAL(timeout()),this,SLOT(updatetimer()));
        timer->start(1000);
    }
}

MainGame::~MainGame()
{
    delete ui;
}

void MainGame::ResetVector(){
    this->Players[0] = Game::Get().getPlayers(0).GetAllPlayers();
    this->Players[1] = Game::Get().getPlayers(1).GetAllPlayers();

}
void MainGame::SetCombo(){
     ui->SelectPlayers1->clear();
    ui->SelectPlayers1_2->clear();



for (int j=0; j< Players[1].size(); j++){
ui->SelectPlayers1_2->addItem(QString::number(Players[1][j]));

}

for (int j=0; j< Players[0].size(); j++){
ui->SelectPlayers1->addItem(QString::number(Players[0][j]));

}



}
void MainGame::updatetimer(){
    int secs = Game::Get().get_time_to_win();
    int m = ( secs % 3600 ) / 60;
    int s = ( secs % 3600 ) % 60;
    QTime t(m, s);

    ui->Time->setText(t.toString());

    Game::Get().set_time_to_win(secs-1);
}


void MainGame::Update(){
    ui->Goals1->setText(QString::number(Game::Get().getPlayers(0).GetGoals()));
    ui->Goals2->setText(QString::number(Game::Get().getPlayers(1).GetGoals()));
    ui->Possesion->setText(QString::fromStdString(Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName())+(" has possesion"));
    this->SetCombo();


}
void MainGame::Setup(){

    ui->Team1->setText(QString::fromStdString(Game::Get().getPlayers(0).GetTeamName()));
    ui->Team2->setText(QString::fromStdString(Game::Get().getPlayers(1).GetTeamName()));
    ui->Goals1->setText(QString::number(Game::Get().getPlayers(0).GetGoals()));
    ui->Goals2->setText(QString::number(Game::Get().getPlayers(1).GetGoals()));
    ui->Possesion->setText(QString::fromStdString(Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName())+(" has possesion"));
    this->ResetVector();
    this->SetCombo();
    count=0;


    }








void MainGame::on_RollDice_clicked()
{
Dice::Get().diceroll();
    choice1 = ui->SelectPlayers1->currentIndex();
    choice2 = ui->SelectPlayers1_2->currentIndex();



    QMessageBox msg;
       msg.setText("The dice rolled "+ QString::fromStdString(Dice::Get().getState()));
       msg.exec();



       if (Game::Get().tackle(choice1, choice2, Dice::Get().getIndex())) {
  count++;





           if (Game::Get().get_possesion()){
           Players[0].erase(Players[0].begin()+ (choice2));
           }
           else{
               Players[1].erase(Players[1].begin() + (choice1));
           }
           this->Update();
           msg.setText("Your tackle was sucessfull");
           msg.exec();

           if (count==Game::Get().getPlayers(1).GetNumPlayers())
           {
               Game::Get().getPlayers(Game::Get().get_possesion()).SetGoals();
               msg.setText(QString::fromStdString(Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName())+(" scored a goal!!!"));
               this->ResetVector();
              this->Update();
               msg.exec();
               return;



           }
           if (Game::Get().GameOver()==0){
                msg.setText(QString::fromStdString(Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName())+(" has won!!!"));
                QApplication::quit();
           }

       }
       else {
           count = 0;
           Game::Get().switch_possesion();
           msg.setText("Your tackle was unsucessfull and you have lost possesion");
            this->ResetVector();
           this->Update();
           msg.exec();
           return;

       }


}
