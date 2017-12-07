#ifndef ScoreH
#define ScoreH

using namespace std;
class Score
{
public:
	Score();
	int amount(int amount);
	int get_amount() const;
	int update_amount();

private:
	int amount_;
};

#endif // !ScoreH