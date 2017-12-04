// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "constants.h"
#include "RandomNumberGenerator.h"

class Snake {
	public:
		Snake(Mouse * mp);
		bool is_at_position(int x, int y) const;  
		bool has_caught_mouse() const ;
		int get_x() const;
		int get_y() const;
		char get_symbol() const;
		char get_tail_symbol() const;
		void move_tail();
		void chase_mouse();
		void position_at_random();
		void set_position(int dx, int dy);
		void update_position(int dx, int dy);

	private:
		const Mouse* p_mouse_;
		vector<Snake> tails_;
		static RandomNumberGenerator rng_;
		const char symbol_ = SNAKEHEAD;
		const char tail_symbol = SNAKEBODY;
		int x_, y_;
		void set_direction(int& dx, int& dy);
};

#endif // !defined(SnakeH)
