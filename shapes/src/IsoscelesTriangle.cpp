module;
#include <QPainter>
#include <QPolygonF>
#include <QPointF>
module Shapes;

IsoscelesTriangle::IsoscelesTriangle(const IsoscelesTriangleConfig& config):
Figure(config), heightOfTriangle(config.heightOfTriangle), a(config.a),
r(
	(a*heightOfTriangle)
	/(2*std::sqrt(std::pow(a/2,2)+std::pow(heightOfTriangle,2))+a)
	)
{ }
double IsoscelesTriangle::getHeightOfTriangle() const {return heightOfTriangle;};
void IsoscelesTriangle::draw(QPainter& painter) const {
	const QPolygonF triangle ={
		QPointF(x + heightOfTriangle-r, y),
		QPointF(x - r, y+a/2),
		QPointF(x - r, y-a/2)
	};
    painter.drawPolygon(triangle);
}
