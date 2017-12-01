#ifndef HoleH
#define HoleH


class Hole {
public:
	//constructors
	Hole();
	explicit Hole(int x, int y);
	//assessors
	int get_x() const;
	int get_y() const;
	int get_max_holes() const;
	char get_symbol() const;
	bool is_at_position(int x, int y) const; 
private:
	 static const int MAXHOLES = 3; //number of holes in underground
									//data members
	const char symbol_;
	int x_, y_;
};

#endif // !HoleH