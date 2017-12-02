
#if !defined(GameH)
#define GameH

#include "Mouse.h"
#include "Snake.h"
#include "UserInterface.h"

class Game
{
	// THESE SHOULD BE PRIVATE AND RELATIONSHIP IMPLEMENTED CORRECTLY
public:
	
	
	int key_;
	Game(UserInterface* p_ui);
	void run();
	string prepare_grid();
	bool is_arrow_key_code(int keycode);
	void apply_rules();
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);
	string prepare_end_message();

	// how to run the snake constructor which takes a mouse pointer?
private:
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
};

#endif