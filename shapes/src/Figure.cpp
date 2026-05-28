module;
#include <QPainter>
module Shapes;

Figure::Figure(const FigureConfig &config) : x{config.x}, y{config.y}, visible{config.visible}
{
	if (x<=0 || y<=0)
		throw std::invalid_argument{"invalid argument for Firgure"};
}

Figure::Figure(const Figure &figure) : x(figure.x), y(figure.y), visible(figure.visible)
{ }
bool Figure::isVisible() const {return visible;}
double Figure::getX() const noexcept {return x;}
double Figure::getY() const noexcept {return y;}

void Figure::hide() {visible=false;}
void Figure::show(){visible=true;}
void Figure::move(const double dx, const double dy){x+=dx;y+=dy;}
void Figure::draw(QPainter& painter) const
{ }
