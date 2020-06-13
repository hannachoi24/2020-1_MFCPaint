#include "pch.h"
#include "Figure.h"
void FigureRectangle::draw(CPaintDC* dc) {

    dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}
void FigureEllipse::draw(CPaintDC* dc) {
    dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}

void FigureLine::draw(CPaintDC* dc) {
    dc->MoveTo(p1.x, p1.y);
    dc->LineTo(p2.x, p2.y);
}