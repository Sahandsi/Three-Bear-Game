// Snake.cpp: implementation of the Snake class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
#include "constants.h"
#include "Snake.h"
// EXAMNPLE CHANGE


// WHAT DOES THIS DO?
RandomNumberGenerator Snake::rng_;



Snake::Snake(Mouse* mp) :  p_mouse_(mp)
{
	position_at_random();
}

bool Snake::is_at_position(int x, int y) const {
	return (x_ == x) && (y_ == y);
}
bool Snake::has_caught_mouse() const {
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

int Snake::get_x() const
{
	return x_;
}

int Snake::get_y() const
{
	return y_;
}

char Snake::get_symbol() const
{
	return symbol_;
}


void Snake::chase_mouse() {	 
	int snake_dx, snake_dy;
	//identify direction of travel
	set_direction(snake_dx, snake_dy);
	//go in that direction
	update_position(snake_dx, snake_dy);
}
void Snake::set_direction(int& dx, int& dy)
{
	assert(p_mouse_ != nullptr);  //Pre-condition: The snake needs to know where the mouse is 
	//assume snake only move when necessary
	dx = 0; dy = 0;
		//update coordinate if necessary
	if (x_ < p_mouse_->get_x())             //if snake on left of mouse
		dx = 1;                          //snake should move right
	else                                    //otherwise
		if (x_ > p_mouse_->get_x())         //if snake on left of mouse
			dx = -1;                     //snake should move left
	if (y_ < p_mouse_->get_y())             //if snake is above mouse
		dy = 1;                          //snake should move down
	else                                    //otherwise
		if (y_ > p_mouse_->get_y())         //if snake is below mouse
			dy = -1;                     //snake should move up
}
void Snake::update_position(int dx, int dy) {
	x_ += dx;
	y_ += dy;
}

void Snake::position_at_random() {
	x_ = rng_.get_random_value(SIZE);        //WARNING: may fall on mouse
	y_ = rng_.get_random_value(SIZE);
	
}