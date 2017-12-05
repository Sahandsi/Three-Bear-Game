#pragma once
#include <string>
#include "Score.h"
class Player
{
public:
	Player();
	string get_name() const;
	int get_score_amount() const;
	int get_score_amount() const;
	int update_score_amount(int amount);

private:
	const string name_;
	
};

