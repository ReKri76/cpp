module;
#include <QPainter>
#include <QPointF>
module Shapes;

Circle::Circle(const CircleConfig& config) : Figure(config), radius(config.radius)
{ }
double Circle::getRadius() const {return radius;}
void Circle::draw(QPainter& painter) const {
	painter.drawEllipse(QPointF(x, y), radius, radius);
}