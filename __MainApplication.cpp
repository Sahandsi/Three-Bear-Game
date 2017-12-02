//--------------------------------
//include standard libraries
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring
using namespace std;

//include class modules
#include "Game.h"

int main()
{

	UserInterface ui;
	// asghar testing here 
	Game game(&ui);
	ofstream fout;
	fout.open("Game.txt", ios::out);
	if (fout.fail())
		cout << "\nAn error has occurred when opening the file.";
	else
		fout << game;	//insertion operator<< for Game instances
	fout.close();

	ifstream fin;
	fin.open("Game.txt", ios::in);
	if (fin.fail())
		cout << "\nAn error has occurred when opening the file.";
	else
		fin >> game; 	//extraction operator>> for Game instances
	fin.close();


	/*game.run();*/

	ui.hold_window();
	return 0;
}