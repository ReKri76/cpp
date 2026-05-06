module;
#include <QPainter>
module Shapes;

ComplexFigure::ComplexFigure(const ComplexFigureConfig& config):
Figure(config), triangle(new IsoscelesTriangle(config.triangle)), circle(new Circle(config.circle))
{ }

void ComplexFigure::draw(QPainter& painter) const
{
    circle->draw(painter);
    triangle->draw(painter);
}

void ComplexFigure::hide()
{
    visible = false;
    circle->hide();
    triangle->hide();
}

void ComplexFigure::show()
{
    visible = true;
    circle->show();
    triangle->show();
}

void ComplexFigure::move(const double dx, const double dy)
{
    x += dx;
    y += dy;
    circle->move(dx, dy);
    triangle->move(dx, dy);
}

IsoscelesTriangle* ComplexFigure::getIsoscelesTriangle() const {return triangle;}
Circle* ComplexFigure::getCircle() const {return circle;}

ComplexFigure::~ComplexFigure()
{
    delete circle;
    delete triangle;
}