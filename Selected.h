#ifndef SELECTED_H
#define SELECTED_H
#include <vector>

class Selected {
public:
	Selected() {}
	void cpy(vector<Figure*>& clipboard);
	void del();


private:
	vector<vector<Figure*>::iterator> selected;
};

void Selected::cpy(vector<Figure*>& clipboard) {

}
void Selected::del() {

}




#endif // !SELECTED_H
