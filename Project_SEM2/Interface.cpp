#include"Interface.h"
#include<string>
#include<iostream>
#include"Game.h"
#include"Team.h"
#include "Error_Handeling.h"
#include <Windows.h>
#include "Dice.h"
using namespace std;

void DrawHeader()
{
	cout << ".______  .______       __ .___  ___. _______      .__   __. __    __    .___  ___..______   _______ .______            _______   ______    ______  .___________..______       ___      __       __      " << endl;
	cout << "|   _  \\ |   _  \\     |  ||   \\/   ||   ____|     |  \\ |  ||  |  |  ||   \\/   ||   _  \\ |   ____||   _  \\          |   ____| /  __  \\  /  __  \\ |           ||   _  \\     /   \\    |  |     |  |     " << endl;
	cout << "|  |_)  ||  |_)  |    |  ||  \\  /  ||  |__        |   \\|  ||  |  |  ||  \\  /  ||  |_)  ||  |__   |  |_)  |         |  |__   |  |  |  ||  |  |  |`---|  |----`|  |_)  |   /  ^  \\   |  |     |  |     " << endl;
	cout << "|   ___/ |      /     |  ||  |\\/|  ||   __|       |  . `  ||  |  |  ||  |\\/|  ||   _  < |   __|  |      /          |   __|  |  |  |  ||  |  |  |    |  |     |   _  <   /  /_\\  \\  |  |     |  |     " << endl;
	cout << "|  |     |  |\\  \\----.|  ||  |  |  ||  |____      |  |\\   ||  `--'  ||  |  |  ||  |_)  ||  |____ |  |\\  \\----.     |  |     |  `--'  ||  `--'  |    |  |     |  |_)  | /  _____  \\ |  `----.|  `----." << endl;
	cout << "| _|     | _| `._____||__||__|  |__||_______|     |__| \\__| \\______/ |__|  |__||______/ |_______|| _| `._____|     |__|      \\______/  \\______/     |__|     |______/ /__/     \\__\\|_______||_______|" << endl;
	cout << "" << endl;
}
void DrawMenu(int width, char drawChar)
{
	string firstAndLastRow(width, drawChar);
	cout << firstAndLastRow << endl;
	cout << "\t\t\t.___  ___. _______ .__   __. __    __    " << endl;
	cout << "\t\t\t|   \\/   ||   ____||  \\ |  ||  |  |  |" << endl;
	cout << "\t\t\t|  \\  /  ||  |__   |   \\|  ||  |  |  |" << endl;
	cout << "\t\t\t|  |\\/|  ||   __|  |  . `  ||  |  |  |" << endl;
	cout << "\t\t\t|  |  |  ||  |____ |  |\\   ||  `--'  |" << endl;
	cout << "\t\t\t|__|  |__||_______||__| \\__| \\______/ " << endl;
	cout << "" << endl;
	cout << "\t\t\tPlease Select what mode you would like to play\n\n";
	cout << "\t\t\t1: One PLayer Game\n";
	cout << "\t\t\t2: Two PLayer Game\n";
	cout << "\t\t\t3: End Game\n\n";
	cout << firstAndLastRow << endl;
}
/*
void OnePlayerGame()
{	
	cout << "\tYou Selected One Player Game\n" << endl;
	Team PlayerOne;
	Team PlayerTwo("AI PLayer");
	string name, NumPlayers;
	int NumberOfPlayers = 0, gameType=0;
	cout << "\tPlease enter Player ones Name: ";
	cin >> name;
	PlayerOne.SetTeamName(name);
	//Game::Get().getPlayerOne().SetTeamName(name); // This is throwing and error and see the issue need to look at it further 
	//Game::Get().getPlayerTwo().SetTeamName("AI Player");
	cout << "Please select a Game Type \n\t1:Number of Goals Game \n\t 2:Timed Game" << endl;
	cin >> gameType;
	if (gameType == 1)
	{
		int NumGoals = 0;
		cout << "\tYou selected Number Of Goals\n";
		cout << "\t How many goals would you like to play to?";
		cin >> NumGoals;
		//Game::Get().set_goals_to_win(NumGoals);
	}
	else
	{
		int time = 0;
		cout << "\tYou selected a timed game\n";
		cout << "\tHow long would you like the game to last?(mins):";
		cin >> time;
	}

	cout << "\tPlease enter the Number of Players on each team \n";
	cin >> NumPlayers;
	while (set_if_valid_number(NumPlayers, NumberOfPlayers) != 1) //currently having an error when letter and numbers are mixed 
	{
		cout << "You must enter just numbers and not letters\n ";
		cin >> NumPlayers;
	}
	PlayerOne.SetNumPlayers(NumberOfPlayers);
	PlayerTwo.SetNumPlayers(NumberOfPlayers);
	//Game::Get().getPlayerOne().SetNumPlayers(NumberOfPlayers);
	//Game::Get().getPlayerTwo().SetNumPlayers(NumberOfPlayers);

	for (int i = 0; i < NumberOfPlayers; i++)
	{
		int num = 0;
		cout << "\tPlease enter a prime Nnmber\n ";
		cin >> num;
		while (PlayerOne.getPrimeNumber().CheckPrimeNumber(num) != 1)
		{
			cout << num << "\tIs not a prime Number ... Please enter a prime Number\n";
			cin >> num;
		}
		PlayerOne.SetPlayers(num);
		int n= PlayerTwo.getPrimeNumber().RandomPrimeNumber(); // Generates a random number for the AI PLayer 
		PlayerTwo.SetPlayers(n);
	}

	system("CLS"); // This will clear the screen ready for the game to being !
	

	cout << "\t\t\t\tPlayer Ones name: " << PlayerOne.GetTeamName() << "\t\t\t\tPlayer Twos name: " << PlayerTwo.GetTeamName() << endl<<endl;
	if (gameType == 1)
	{
		cout << "\t\t\t\t\t\t\t Goals to win:\n\n\n";
	}
	else
	{
		cout << "\t\t\t\t\t\t\t Time:\n\n\n";
	}
	cout << " Number of players on the Team.. " << PlayerOne.GetNumPlayers() << endl;
	for (int a = 0; a << PlayerOne.GetPlayers().size(); a++)
	{
		cout << PlayerOne.GetPlayers().at(a)<<" ";
	}

	cout << "Player Twos name:" << PlayerTwo.GetTeamName() << endl;
	cout << " Number of players on the Team.. " << PlayerTwo.GetNumPlayers() << endl;
	for (int a = 0; a < PlayerTwo.GetPlayers().size(); a++)
	{
		cout << PlayerTwo.GetPlayers().at(a) << " ";
	}
}
*/
void TwoPlayerGame()
{

	cout << "\t\tYou Selected A Two Player Game\n\n" << endl;
	//Team PlayerOne, PlayerTwo; // Creates two instances of team 

	string Temp;
	int NumberOfPlayers = 0, gameType = 0;
	for (int i = 0; i < 2; i++) {
		cout << "\t\tPlease enter Players " << i + 1 << " Name\n\n";
		cin >> Temp;
		Game::Get().getPlayers(i).SetTeamName(Temp);
	}

	cout << "\t\tPlease enter the Number of Players on each team \n\n";
	cin >> Temp;
	while (set_if_valid_number(Temp, NumberOfPlayers) != 1)
	{
		cout << "\t\tYou must enter just numbers and not letters\n\n ";
		cin >> Temp;
	}
	Game::Get().getPlayers(0).SetNumPlayers(stoi(Temp));
	Game::Get().getPlayers(1).SetNumPlayers(stoi(Temp));

	for (int i = 0; i < 2; i++) {

		cout << "\t\t" << Game::Get().getPlayers(i).GetTeamName() << " Select your Player Numbers\n\n";
		for (int j = 0; j < NumberOfPlayers; j++)
		{
			int num = 0;
			cout << " \t\tPlease enter player " << j + 1 << " number\n\n ";
			cin >> num;
			while (Game::Get().getPlayers(i).getPrimeNumber().CheckPrimeNumber(num) != 1)
			{
				cout << num << "\t\tIs not a prime Number ... Please enter a prime Number\n\n";
				cin >> num;
			}
			Game::Get().getPlayers(i).SetPlayers(num);
		}
	}

	system("CLS"); // This will clear the screen ready for the game to being !

	cout << "Please select a Game Type \n\t1:Number of Goals Game \n\t 2:Timed Game" << endl;
	cin >> gameType;
	if (gameType == 1)
	{
		int NumGoals = 0;
		cout << "\tYou selected Number Of Goals\n";
		cout << "\t How many goals would you like to play to?";
		cin >> NumGoals;
		Game::Get().set_goals_to_win(NumGoals);
		Game::Get().set_time_to_win(-1);

	}
	else
	{
		int time = 0;
		cout << "\tYou selected a timed game\n";
		cout << "\tHow long would you like the game to last?(mins):";
		cin >> time;
		Game::Get().set_goals_to_win(-1);
		Game::Get().set_time_to_win(time);
	}


	system("CLS");

	cout << "\t\t Coin toss!\n" << endl;
	bool result = Game::Get().coin_toss();

	if (result == 0) {
		cout << "Player 1 has won the coin toss" << endl;
	}
	else {
		cout << "Player 2 has won the coin toss" << endl;
		Game::Get().switch_possesion();
	}
;
	int count = 0;
	while (Game::Get().GameOver()) {
	START:
		
			int choice[2];
			cout << Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName() << " has possesion!" << endl << endl;
			cout << "You need to get past " << Game::Get().getPlayers(1).GetNumPlayers() - count << " players" << endl << endl;;
			Sleep(1);
			cout << "Press enter to roll the dice to tackle" << endl;
			cin.get();

			Dice::Get().diceroll();

			cout << "The dice rolled " << Dice::Get().getState() << endl << endl;


			for (int i = 0; i < 2; i++) {

				cout << Game::Get().getPlayers(i).GetTeamName() << " chose your player" << endl;
				for (int j = 0; j < Game::Get().getPlayers(i).GetNumPlayers(); j++) {
					cout << j + 1 << ": " << Game::Get().getPlayers(i).GetPlayers(j) << endl;
				}
				cin >> choice[i];
				choice[i]--;
			}


				cout << Game::Get().getPlayers(0).GetTeamName() << " has a remainder of " << Game::Get().get_remainder(0, choice[0]) << endl;
					cout << Game::Get().getPlayers(1).GetTeamName() << " has a remainder of " << Game::Get().get_remainder(1, choice[1]) <<endl ;

				if (Game::Get().tackle(choice[0], choice[1], Dice::Get().getIndex())) {

					cout << "Your tackle was sucessfull" << endl;
					count++;


				}
				else {
					cout << "Your tackle was unsucessfull and you have lost possesion" << endl;
					count = 0;
					Game::Get().switch_possesion();
				}

				if (count == Game::Get().getPlayers(1).GetNumPlayers()) {
					Game::Get().getPlayers(Game::Get().get_possesion()).SetGoals();
					count = 0;
					cout << Game::Get().getPlayers(Game::Get().get_possesion()).GetTeamName() << " has scored!" << endl << endl;
					Game::Get().switch_possesion();
					goto START;
					

			}

	}

		}



	






		