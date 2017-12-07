#include "Player.h"

Player::Player(string s) : name_(s)
{}

string Player::get_name() const
{
	return name_;
}

int Player::get_score_amount() const
{
	return score_.get_amount();
}

void Player::update_score_amount(int amount)
{
	score_.update_amount(amount);
}
