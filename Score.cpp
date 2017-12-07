#include "Score.h"

int Score::amount_ = 0;

Score::Score() 
{}


int Score::get_amount() const
{
	return amount_;
}

void Score::update_amount(int amount)
{
	amount_ += amount;
}
