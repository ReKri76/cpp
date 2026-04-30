module;
#include <QPainter>
export module Shapes:ComplexFigure;

import :Figure;
import :Circle;
import :IsoscelesTriangle;


export struct ComplexFigureConfig : FigureConfig
{
	IsoscelesTriangleConfig triangle;
	CircleConfig circle;
};

export class ComplexFigure : public Figure
{
protected:
	IsoscelesTriangle* triangle;
	Circle* circle;
public:
	void  hide() override;
	void  show() override;
	void  move(double dx, double dy) override;

	explicit ComplexFigure(const ComplexFigureConfig& config);
	[[nodiscard]]IsoscelesTriangle* getIsoscelesTriangle() const;
	[[nodiscard]]Circle* getCircle() const;
	void draw(QPainter& painter) const override;
};
