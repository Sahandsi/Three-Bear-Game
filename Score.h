#pragma once

using namespace std;
class Score
{
public:
	Score();
	int get_amount() const;
	void update_amount(int amount);

private:
	int amount_;
};
