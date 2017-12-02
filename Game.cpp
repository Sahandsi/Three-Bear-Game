#include <sstream> // for os
#include "Game.h"



Game::Game(UserInterface* pui) : mouse_(), snake_(&mouse_), underground_(), p_ui(pui)
{}

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
			apply_rules();
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
				os << snake_.get_symbol();	//show snake
			else
				if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
					os << mouse_.get_symbol();	//show mouse
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
		mouse_.die();
	else
		if (mouse_.has_reached_a_hole(underground_))
			mouse_.escape_into_hole();
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

//for output: save game into file 
void operator<<(ofstream& fout, const Game& game)
{
	fout << game.save_game();
}

//for input: read game from file
void operator>>(ifstream& fin, const Game& game)
{
	
}
