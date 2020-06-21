#ifndef SELECTED_H
#define SELECTED_H
#include <vector>
#include "Figure.h"


class Selected {
public:
	Selected() {}
	void push_back(vector<Figure*>::iterator iter);
	void cpy(vector<Figure*>& clipboard);
	void del(vector<Figure*>& drawings);
	void drawcircle(CPaintDC* dc);
	void clear();
	int size();
	void move(CPoint& distance);
	void Figuresize(CPoint& distance);





private:
	vector<vector<Figure*>::iterator> selected;
};







#endif // !SELECTED_H
