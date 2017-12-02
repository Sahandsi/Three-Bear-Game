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
	game.run();

	ui.hold_window();
	return 0;
}