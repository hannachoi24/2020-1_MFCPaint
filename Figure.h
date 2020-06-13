#pragma once

#include "pch.h"

class FigureRectangle
{
public:
	FigureRectangle() : p1(0, 0), p2(0, 0) {}
	FigureRectangle(CPoint& _p1, CPoint& _p2) : p1(_p1), p2(_p2) {}
public:
	CPoint p1, p2; /* khlee: 좌상단 및 우하단 꼭지점 */
	void draw(CPaintDC* dc);
};