#ifndef NutH
#define NutH

class Nut
{
public:
	Nut();
	~Nut();
	int get_x() const;
	int get_y() const;
	int get_symbol() const;
	bool has_been_collected() const;
	bool is_at_position(int x, int y) const;

private:
	int x_, y_;
	char symbol_;
	bool collected_;
	void disappears();
};



#endif // !NutH
