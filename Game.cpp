#include <sstream> // for os
#include <iostream>
#include "Game.h"


Game::Game(UserInterface* pui, string name) : mouse_(), snake_(&mouse_), underground_(), p_ui(pui), player_(name)
{
}

void Game::run() {
	assert(p_ui != nullptr);
	

		p_ui->draw_grid_on_screen(prepare_grid());
		key_ = p_ui->get_keypress_from_user();

		while (!has_ended(key_))
		{
			if (is_arrow_key_code(key_))
			{
				mouse_.scamper(key_);
				snake_.chase_mouse();
				p_ui->draw_grid_on_screen(prepare_grid());
				//display score at all times
				apply_rules();
				show_score();
				// if the mouse is at the nut, the nut is colleced and dissapears
				if (can_mouse_collect_nut(nut_))
				{
					nut_.disappears();
				}
			}
			key_ = p_ui->get_keypress_from_user();
		}
	p_ui->show_results_on_screen(prepare_end_message());
}
string Game::prepare_grid() const {
	//prepare a string that holds the grid information
	ostringstream os;
	for (int row(1); row <= SIZE; ++row)	//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if ((row == snake_.get_y()) && (col == snake_.get_x())) 
			{
				// draw the snake head last so that head appears first on grid
				os << snake_.get_symbol();	//show snake
			}
			else 
				// check if tail is at position
				if (snake_.is_tail_at_position(col, row))
				{
					// draw a piece of tail
					os << snake_.get_tail_symbol();
				}
			else
				if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
					os << mouse_.get_symbol();	//show mouse
				else
					// make sure nut has not been collected
					if ((row == nut_.get_y()) && (col == nut_.get_x() && (!nut_.has_been_collected())))
						os << nut_.get_symbol();	//show mouse
					else
						{
							const int hole_no(find_hole_number_at_position(col, row));
							if (hole_no != -1)
								os << underground_.get_hole_no(hole_no).get_symbol();	//show hole
							else
								os << FREECELL;	//show free grid cell
						}
		} //end of col-loop
		os << endl;
	} //end of row-loop
	return os.str();
} //end prepare_grid

bool Game::is_arrow_key_code(int keycode) const {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}
int Game::find_hole_number_at_position(int x, int y) const {
	for (int h_no(0); h_no < underground_.get_holes().size(); ++h_no)
		if (underground_.get_hole_no(h_no).is_at_position(x, y))
			return h_no;		//number of the hole
	return -1;				//not a hole
}

void Game::apply_rules() {
	if (snake_.has_caught_mouse())
	{
		mouse_.die();
		// decrease score when mouse gets caught
		player_.update_score_amount(-1);
	}	
	else
		if (mouse_.has_reached_a_hole(underground_) && nut_.has_been_collected())
		{ 
			player_.update_score_amount(1);
			mouse_.escape_into_hole();
		}
}
bool Game::has_ended(char key) const {
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}
string Game::prepare_end_message() const {
	ostringstream os;
	if (mouse_.has_escaped())
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
	else
		if (!mouse_.is_alive())
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	return os.str();
}



string Game::save_game() const
{
	stringstream ss;
	// convert integer to string and store in file
	ss << mouse_.get_x() << "\n" << mouse_.get_y()
	<< "\n" << snake_.get_x() << "\n" << snake_.get_y();
	return ss.str();
	
}

void Game::load_game(ifstream& fin)
{
	int mouseDX, mouseDY, snakeDX, snakeDY;
	if (fin.is_open())
	{
		string line;
		
		// x value for mouse stored in file
		getline(fin, line);
		mouseDX = atoi(line.c_str());
		// y value for mouse stored in file
		getline(fin, line);
		mouseDY = atoi(line.c_str());

		// set the position of the mouse to be the same as x and y from the txt file
		mouse_.set_position(mouseDX, mouseDY);

		// x value for mouse stored in file
		getline(fin, line);
		snakeDX = atoi(line.c_str());
		// y value for mouse stored in file
		getline(fin, line);
		snakeDY = atoi(line.c_str());
		
		// set the position of the snake to be the same as x and y from the txt file
		snake_.set_position(snakeDX, snakeDY);
		fin.close();
	}
	

	
}

bool Game::can_mouse_collect_nut(const Nut& nut_) const
{
	return mouse_.can_collect_nut(nut_);
}

void Game::show_score() const
{
	cout << "Player Score: " << player_.get_score_amount();
}

bool Game::play_again()
{
	char play_again;
	cout << "\nDo you want to play agian: 'y' or 'Y' ";
	cin >> play_again;
	if (toupper(play_again) == 'Y')
	{
		return true;
	}
	return false;
}

//for output: save game into file 
void operator<<(ofstream& fout, const Game& game)
{
	fout << game.save_game();
}

//for input: read game from file
void operator>>(ifstream& fin, Game& game)
{
	game.load_game(fin);
}

