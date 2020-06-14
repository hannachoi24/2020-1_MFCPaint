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
 
void FigureRectangle::drawcircle(CPaintDC* dc) {

    dc->Ellipse(p1.x-5, p1.y-5, p1.x+5, p1.y+5);
    dc->Ellipse((p1.x+p2.x)/2-5, p1.y-5, (p1.x+p2.x)/2+5, p1.y+5);
    dc->Ellipse(p2.x-5, p1.y-5, p2.x+5, p1.y+5);
    dc->Ellipse(p2.x-5, (p1.y + p2.y)/2-5, p2.x+5,(p1.y+p2.y)/2+5);
    dc->Ellipse(p2.x-5, p2.y-5, p2.x+5, p2.y+5);
    dc->Ellipse((p1.x + p2.x) / 2 - 5, p2.y - 5, (p1.x + p2.x) / 2 + 5, p2.y + 5);
    dc->Ellipse(p1.x - 5, p2.y - 5, p1.x + 5, p2.y + 5);
    dc->Ellipse(p1.x - 5, (p1.y+ p2.y) / 2 - 5, p1.x + 5, (p1.y + p2.y) / 2 + 5);

}

void FigureEllipse::drawcircle(CPaintDC* dc) {
    dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
    dc->Ellipse(p1.x - 5, p1.y - 5, p1.x + 5, p1.y + 5);
    dc->Ellipse((p1.x + p2.x) / 2 - 5, p1.y - 5, (p1.x + p2.x) / 2 + 5, p1.y + 5);
    dc->Ellipse(p2.x - 5, p1.y - 5, p2.x + 5, p1.y + 5);
    dc->Ellipse(p2.x - 5, (p1.y + p2.y) / 2 - 5, p2.x + 5, (p1.y + p2.y) / 2 + 5);
    dc->Ellipse(p2.x - 5, p2.y - 5, p2.x + 5, p2.y + 5);
    dc->Ellipse((p1.x + p2.x) / 2 - 5, p2.y - 5, (p1.x + p2.x) / 2 + 5, p2.y + 5);
    dc->Ellipse(p1.x - 5, p2.y - 5, p1.x + 5, p2.y + 5);
    dc->Ellipse(p1.x - 5, (p1.y + p2.y) / 2 - 5, p1.x + 5, (p1.y + p2.y) / 2 + 5);
    
}

void FigureLine::drawcircle(CPaintDC* dc) {
    dc->Ellipse(p1.x-5, p1.y-5,p1.x+5,p1.y+5);
    dc->Ellipse(p2.x-5, p2.y-5, p2.x+5, p2.y+5);
}