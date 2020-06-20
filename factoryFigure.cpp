#include "pch.h"
#include "factoryFigure.h"

Figure* FactoryFigure::generateFigure(Figure* figure) {
	Figure* retFigu = NULL;
	string name = figure->getName();
	if (name == "Rectangle"){
		retFigu = new FigureRectangle(*dynamic_cast<FigureRectangle*>(figure));
	}
	else if (name == "Ellipse") {
		retFigu = new FigureEllipse(*dynamic_cast<FigureEllipse*>(figure));
	}
	else if (name == "Line") {
		retFigu = new FigureLine(*dynamic_cast<FigureLine*>(figure));
	}
	return retFigu;
}

	


