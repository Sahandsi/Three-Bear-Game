#ifndef HoleH
#define HoleH
#include "constants.h"

class Hole {
public:
	//constructors
	Hole();
	explicit Hole(int x, int y);
	//assessors
	int get_x() const;
	int get_y() const;
	static int get_max_holes();
	char get_symbol() const;
	bool is_at_position(int x, int y) const; 
private:
	 static const int MAXHOLES = 3; //number of holes in underground
									//data members
	const char symbol_ = HOLE;
	int x_, y_;
};

#endif // !HoleH