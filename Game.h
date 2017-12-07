
#if !defined(GameH)
#define GameH

#include <fstream>


#include "Snake.h"
#include "Mouse.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Player.h"


class Game
{
	// THESE SHOULD BE PRIVATE AND RELATIONSHIP IMPLEMENTED CORRECTLY
public:
	Game(UserInterface* p_ui, string name);
	void run();
	string prepare_grid() const;
	bool is_arrow_key_code(int keycode) const;
	void apply_rules();
	int find_hole_number_at_position(int x, int y) const ;
	bool has_ended(char key) const;
	string prepare_end_message() const;
	string save_game() const;
	void load_game(ifstream&);
	bool can_mouse_collect_nut(const Nut& nut_) const;
	

private:
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	Nut nut_;
	UserInterface* p_ui;
	Player player_;
	int key_;
};

void operator<<(ofstream&, const Game&);
void operator>>(ifstream&, Game&);

#endif