module;
#include <QPainter>
#include <QList>
#include<QWidget>
module Shapes;

void CanvasWidget::paintEvent(QPaintEvent *event)
{
	if (shapes->empty())
		throw std::runtime_error("Have not shapes to draw");

	QPainter painter(this);

	for (const auto& shape : *shapes)
	{
		if (shape!=nullptr && shape->isVisible())
			shape->draw(painter);
	}
}

CanvasWidget::CanvasWidget(QWidget *parent) : QWidget(parent), shapes(new QList<Figure*>())
{ }
void CanvasWidget::push_top(Figure* figure) {shapes->push_front(figure);}
Figure* CanvasWidget::put_top() const {return shapes->back();}
void CanvasWidget::push_back(Figure* figure) {shapes->push_back(figure);}
Figure* CanvasWidget::put_back() const {return shapes->back();}

CanvasWidget::~CanvasWidget()
{
	std::for_each(shapes->begin(), shapes->end(), [](Figure* figure){delete figure;});
	delete shapes;
}