#if !defined (MoveableGridItem)
#define MoveableGridItemH

using namespace std;

class MoveableGridItem
{
public:
	MoveableGridItem();
	~MoveableGridItem();

	int get_x()const;
	int get_y()const;
	bool is_at_position(int x, int y)const;
	void reset_position(int x, int y);
	void update_position(int x, int y);


private:
	int x_,y_;

};

MoveableGridItem::MoveableGridItem()
{
}

MoveableGridItem::~MoveableGridItem()
{
}
#endif 
