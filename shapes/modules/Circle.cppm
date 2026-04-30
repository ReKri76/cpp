module;
#include <QPainter>
export module Shapes:Circle;
import :Figure;

export struct CircleConfig: FigureConfig
{
	double radius;
};

export class Circle : public Figure
{
protected:
	double radius{};
public:
	explicit Circle(const CircleConfig& config);
	[[nodiscard]] double getRadius() const;
	void draw(QPainter& painter) const override;
};