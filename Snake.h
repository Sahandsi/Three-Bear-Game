// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"

class Snake {
	public:
		
		// remove this when you sort out the game class
		Snake();

		Snake(Mouse * mp);
		~Snake();
		bool is_at_position(int x, int y) const;  
		bool has_caught_mouse() const ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		void position_at_random();
		void update_position(int dx, int dy);
		const char symbol_ = SNAKEHEAD;
		int x_, y_;
	private:
		Mouse* p_mouse_;
		RandomNumberGenerator rng_;
};

#endif // !defined(SnakeH)
