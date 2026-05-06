module;
#include <QPainter>
#include <QPointF>
module Shapes;

Circle::Circle(const CircleConfig& config) : Figure(config), radius(config.radius)
{
	if (radius<=0)
		throw std::invalid_argument{"invalid argument"};
}

double Circle::getRadius() const {return radius;}
void Circle::draw(QPainter& painter) const
{
	painter.drawEllipse(QPointF(x, y), radius, radius);
}