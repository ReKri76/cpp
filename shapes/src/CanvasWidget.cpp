module;
#include <QPainter>
#include<QWidget>
#include<queue>
module Shapes;

void CanvasWidget::paintEvent(QPaintEvent *event)
{
	if (shapes->empty())
		throw std::runtime_error("Have not shapes to draw");

	QPainter painter(this);

	std::queue<Figure*> tempQueue = *shapes;

	while (!tempQueue.empty())
	{
		auto shape = tempQueue.front();
		if (shape != nullptr && shape->isVisible())
		{
			shape->draw(painter);
		}
		tempQueue.pop();
	}
}

CanvasWidget::CanvasWidget(QWidget *parent) : QWidget(parent), shapes(new std::queue<Figure*>())
{ }
void CanvasWidget::push(Figure* figure) const {shapes->push(figure);}
Figure* CanvasWidget::get() const {return shapes->front();}

CanvasWidget::~CanvasWidget()
{
	while (!shapes->empty())
	{
		delete shapes->front();
		shapes->pop();
	}
	delete shapes;
}