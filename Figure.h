#pragma once

#include "pch.h"
#include <string>
using namespace std;

enum sizeMousemode
{
	LEFT_TOP,
	MIDDLE_TOP,
	RIGHT_TOP,
	MIDDLE_RIGHT,
	RIGHT_BOTTOM,
	MIDDLE_BOTTOM,
	LEFT_BOTTOM,
	MIDDLE_LEFT
};

class Figure {
public:
	Figure() :p1(0), p2(0), name("") {}
	Figure(CPoint& _p1, CPoint& _p2, string name) :p1(_p1), p2(_p2), name(name) {}
	Figure(const Figure& source) :p1(source.p1), p2(source.p2), name(source.name) {} //복사생성자
	virtual void draw(CPaintDC* dc) = 0;
	CPoint getp1();
	CPoint getp2();
	string getName();
	void setp1(CPoint& _p1);
	void setp2(CPoint& _p2);
	virtual void drawcircle(CPaintDC* dc) = 0;
	bool onCursor(CPoint& current);
	//virtual sizeMousemode pointerSpot(CPoint& current) = 0;





protected:
	CPoint p1;
	CPoint p2;
	string name;

};

inline CPoint Figure::getp1() {
	return this->p1;
}
inline CPoint Figure::getp2() {
	return this->p2;
}
inline string Figure::getName() {
	return this->name;
}
inline void Figure::setp1(CPoint& _p1) {
	this->p1 = _p1;
}

inline void Figure::setp2(CPoint& _p2) {
	this->p2 = _p2;
}

class FigureRectangle :public Figure {
public:
	FigureRectangle() :Figure(CPoint(0, 0), CPoint(0, 0), "Rectangle") {}
	FigureRectangle(CPoint& _p1, CPoint& _p2) : Figure(_p1, _p2, "Rectangle") {}
	FigureRectangle(const FigureRectangle& source) :Figure(source) {}
	virtual void draw(CPaintDC* dc);
	virtual void drawcircle(CPaintDC* dc);
	//virtual sizeMousemode 


};
class FigureEllipse :public Figure {
public:
	FigureEllipse() {}
	FigureEllipse(CPoint& _p1, CPoint& _p2) :Figure(_p1, _p2, "Ellipse") {}
	FigureEllipse(const FigureEllipse& source) :Figure(source) {}
	virtual void draw(CPaintDC* dc);
	virtual void drawcircle(CPaintDC* dc);


};

class FigureLine :public Figure {
public:
	FigureLine() :Figure(CPoint(0, 0), CPoint(0, 0), "Line") {}
	FigureLine(CPoint& _p1, CPoint& _p2) :Figure(_p1, _p2, "Line") {}
	FigureLine(const FigureLine& source) :Figure(source) {}
	virtual void draw(CPaintDC* dc);
	virtual void drawcircle(CPaintDC* dc);
};



