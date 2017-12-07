#include "Score.h"

// this is static so that only one copy is made of the score amount
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
