#include "pch.h"
#include "Selected.h"
#include "factoryFigure.h"

void Selected::cpy(vector<Figure*>& clipboard) {
	FactoryFigure generate;
	Figure* temp;
	if (clipboard.size() > 0) {
			clipboard.clear();
	}
	for (int i = 0; i < selected.size(); i++) {
		temp = generate.generateFigure(*selected[i]);
		clipboard.push_back(temp);
		
	}

}
void Selected::del(vector<Figure*>& drawings) {
	for (int i = size() - 1; i >= 0; i--) {
		delete* selected[i];
		drawings.erase(selected[i]);
	}
	selected.clear();

}
void Selected::drawcircle(CPaintDC* dc) {
	for (int i = 0; i < selected.size(); i++) {
		(*selected[i])->drawcircle(dc);
	}
}
void Selected::push_back(vector<Figure*>::iterator iter) {
	selected.push_back(iter);
}

void Selected::clear() {
	selected.clear();

}

int Selected::size() {
	return selected.size();

}

void Selected::move(CPoint& distance) {
	for (int i = 0; i < selected.size(); i++) {
		(*this->selected[i])->setp1(CPoint((*this->selected[i])->getp1().x+distance.x, (*this->selected[i])->getp1().y + distance.y));
		(*this->selected[i])->setp2(CPoint((*this->selected[i])->getp2().x + distance.x, (*this->selected[i])->getp2().y + distance.y));	
		
	}
}

void Selected::Figuresize(CPoint& distance) {
	for (int i = 0; i < selected.size(); i++) {
	}
}