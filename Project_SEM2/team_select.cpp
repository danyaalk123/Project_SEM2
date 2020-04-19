#include "team_select.h"
#include "ui_team_select.h"

Team_Select::Team_Select(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Team_Select)
{
    ui->setupUi(this);



}

Team_Select::~Team_Select()
{
    delete ui;
}


void Team_Select::on_InputTeam_clicked()
{


 if (Team_Select::player==-1){
     Game::Get().getPlayers(Team_Select::team).SetTeamName(ui->line->text().toStdString());
 }
     else  {
     bool check=1;
     check= Game::Get().getPlayers(Team_Select::team).SetPlayers(ui->line->text().toInt());
     if (check==0){
         QMessageBox msg;
            msg.setText("Please input a prime number");
            msg.exec();
            return;
            }
     }




done(1);



}

void Team_Select::SetText(string text, int j,int i){

    ui->inputPT->setText(QString::fromStdString(text));
    Team_Select::player=j;
    Team_Select::team=i;

}
