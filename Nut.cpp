#include "Nut.H"

Nut::Nut() : symbol_(NUT), x_(8), y_(9), collected_(false)
{

}

Nut::~Nut() 
{

}

int Nut::get_x() const
{
	return x_;
}

int Nut::get_y() const
{
	return y_;
}

char Nut::get_symbol() const
{
	return symbol_;
}

bool Nut::has_been_collected() const
{
	return collected_ == true;
}

bool Nut::is_at_position(int x, int y) const
{
	return (x_ == x && y_ == y);
}

void Nut::disappears()
{
	collected_ = true;
}
