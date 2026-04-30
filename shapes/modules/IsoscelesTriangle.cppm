module;
#include <QPainter>
export module Shapes:IsoscelesTriangle;
import :Figure;

export struct IsoscelesTriangleConfig: FigureConfig
{
	double heightOfTriangle;
	double a;

};

export class IsoscelesTriangle : public Figure
{
protected:
	double heightOfTriangle{};
	double a{};
	double r{};
public:
	explicit IsoscelesTriangle(const IsoscelesTriangleConfig& config);
	void draw(QPainter& painter) const override;
};