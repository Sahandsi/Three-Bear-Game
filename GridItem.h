#if !defined (GridItem)
#define GridItemH

using namespace std;

class GridItem
{
public:
	GridItem();
	char get_symbol()const;

private :
	const char symbol_;
};


#endif