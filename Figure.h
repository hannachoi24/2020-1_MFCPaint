#pragma once

#include "pch.h"

class Figure {
public:
    Figure():p1(0),p2(0) {}
    Figure(CPoint& _p1, CPoint& _p2):p1(_p1), p2(_p2) {}
    virtual void draw(CPaintDC* dc) = 0;
    CPoint getp1();
    CPoint getp2();
    void setp1(CPoint& _p1);
    void setp2(CPoint& _p2);
    virtual void drawcircle(CPaintDC* dc) = 0;



protected:
    CPoint p1;
    CPoint p2;

};

inline CPoint Figure::getp1() {
    return this->p1;
}
inline CPoint Figure::getp2() {
    return this->p2;
}

inline void Figure::setp1(CPoint& _p1) {
    this->p1 = _p1;
}

inline void Figure::setp2(CPoint& _p2) {
    this->p2 = _p2;
}

class FigureRectangle:public Figure {
public:
    FigureRectangle(){}
    FigureRectangle(CPoint& _p1, CPoint& _p2): Figure(_p1, _p2) {}
    virtual void draw(CPaintDC* dc);
    virtual void drawcircle(CPaintDC* dc);
};
class FigureEllipse :public Figure {
public:
    FigureEllipse() {}
    FigureEllipse(CPoint& _p1, CPoint& _p2) :Figure(_p1, _p2) {}
    virtual void draw(CPaintDC* dc);
    virtual void drawcircle(CPaintDC* dc);


};

class FigureLine :public Figure {
public:
    FigureLine() {}
    FigureLine(CPoint& _p1, CPoint& _p2) :Figure(_p1, _p2) {}
    virtual void draw(CPaintDC* dc);
    virtual void drawcircle(CPaintDC* dc);
};

