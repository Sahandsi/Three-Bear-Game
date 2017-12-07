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
	// ask for name of string (pass string as const reference )
	string name;
	cout << "Please Enter Name: ";
	cin >> name;
	// asghar testing here
	bool play_again;
	do
	{
		play_again = false;
		Game game(&ui, name);
		game.run();
		play_again = game.play_again();
	} while (play_again == true);
	

	ui.hold_window();
	return 0;
}