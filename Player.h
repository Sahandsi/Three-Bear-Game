#pragma once
#include <string>
#include "Score.h"

using namespace std;

class Player
{
public:
	Player(string);
	string get_name() const;
	int get_score_amount() const;
	void update_score_amount(int amount);

private:
	const string name_;
	Score score_;	
};