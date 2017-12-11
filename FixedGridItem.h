#if !defined(FixedGridItem)
#define FixedGridItemH

using namespace std;

class FixedGridItem
{
public:
	FixedGridItem();
	~FixedGridItem();

	int get_x()const;
	int get_y() const;
	bool is_at_position(int x, int y);

private:
	int x, y;
};

FixedGridItem::FixedGridItem()
{
}

FixedGridItem::~FixedGridItem()
{
}
#endif
