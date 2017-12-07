#ifndef NutH
#define NutH

#include "constants.h"
class Nut
{
public:
	Nut();
	~Nut();
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool has_been_collected() const;
	bool is_at_position(int x, int y) const;

private:
	const char symbol_;
	int x_, y_;
	bool collected_;
	void disappears();
};



#endif // !NutH
