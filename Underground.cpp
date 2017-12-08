// Underground.cpp: implementation of the Underground class 
//////////////////////////////////////////////////////////////////////
#include <cassert>
#include "Underground.h"

//////////////////////////////////////////////////////////////////////
Underground::Underground() : holes_{ Hole(4, 3), Hole(15, 10), Hole(7, 15) }
{}

Hole Underground::get_hole_no(int no) const {
	assert (is_valid_hole_number(no));	//precondition: valid hole number
	return holes_.at(no);
}

// NEW FUNCTION
vector<Hole> Underground::get_holes() const
{
	// returns each holes in the vector
	return holes_;
}

bool Underground::is_hole_at_position(int x, int y) const
{
	// check each hole and if ANY hole is at the position in grid
	// return true
	for (int h_no(0); h_no < holes_.size(); ++h_no)
	{
		if (holes_.at(h_no).is_at_position(x, y))
		{
			return true;
		}
	}
	return false;
}

bool Underground::is_valid_hole_number(int no) const {
	return (no >= 0) && (no < holes_.size()); 
}
