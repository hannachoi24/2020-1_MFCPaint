#include "pch.h"
#include "Figure.h"

void FigureRectangle::draw(CPaintDC* dc)
{
	dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}