//--------------------------------
//include standard libraries
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring
using namespace std;

//include class modules

#include "Game.h"

//using OO approach
//---------------------------------


int main()
{
	UserInterface ui;
	
	// asghar testing here 
	Game game;
	

	
	game.set_up(&ui);
	game.run();

	ui.hold_window();
	return 0;
}