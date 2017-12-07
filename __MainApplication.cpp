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
	Game game(&ui, name);

	game.run();

	ui.hold_window();
	return 0;
}