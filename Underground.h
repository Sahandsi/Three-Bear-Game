// Underground.h: UserInterface for the Underground class 
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made & justification (if needed)
//---------------------------------------------------------------------
// 1.11.17   Pascale		TODO: Need to be amended for Assignment 1 [Q1 to 4 and 8]
//                          TODO: Declare class data and function members private where possible.
//                          TODO: Declare const instances, parameters and class functions (wherever possible).
//                          TODO: Create constructors with their initialisation list in same order as declaration list
//                          TODO: Place code in separate module
//                   		TODO: Check design and implementation of relationships to other classes
//                   		TODO: Follow UML design.
//							TODO: etc.
//---------------------------------------------------------------------

#if !defined(UndergroundH)
#define UndergroundH


#include <vector>
using namespace std;

#include "Hole.h"


class Underground {
	public:
		Underground();
		bool is_hole_at_position(int x, int y) const;
		char get_holes_symbol() const;
	private:
		// support function
		bool is_valid_hole_number(int n) const;
		// vector for holes
		const vector<Hole> holes_;

};

#endif // !defined(UndergroundH) 
