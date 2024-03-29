// Mouse.h: UserInterface for the Mouse class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------

#if !defined(MouseH)
#define MouseH

#include "constants.h"
#include "Underground.h"
#include "Nut.h"

class Mouse {
	public:
		//constructor
		Mouse();
		//assessors
		int get_x() const;
		int get_y() const;
		char get_symbol() const;
		bool is_at_position(int x, int y) const;
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(const Underground& ug) const;
		//mutators
		void die();
		void escape_into_hole();
		void scamper(char k);
		// used to set position from the file and includes checks to make sure
		// position is valid
		void set_position(int dx, int dy);
		bool can_collect_nut(Nut nut_) const;

	private:
		//data members
		const char symbol_;
		int  x_, y_;
		bool alive_, escaped_;
		int mouse_dx_, mouse_dy_;
		//supporting functions 
		void position_in_middle_of_grid();
		void update_position(int dx, int dy);

};

#endif // !defined(MouseH)
