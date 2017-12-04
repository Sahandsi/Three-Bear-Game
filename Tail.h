#ifndef TailH
#define TailH

#include "Snake.H";

class Tail
{
public:
	Tail(int x, int y, char symbol);
	~Tail();
	int get_x();
	int get_y();
	int get_symbol();

private:
	int x_, y_, symbol_;

};

Tail::Tail(int x, int y, char symbol) : x_(x), y_(y), symbol_(SNAKEBODY)
{

}

Tail::~Tail()
{
}

inline int Tail::get_x()
{
	return x_;
}

inline int Tail::get_y()
{
	return y_;
}

inline int Tail::get_symbol()
{
	return symbol_;
}


#endif // !TailH

