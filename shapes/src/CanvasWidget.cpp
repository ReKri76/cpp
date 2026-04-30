module;
#include <QPainter>
#include <QList>
#include<QWidget>
module Shapes;

void CanvasWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	for (auto& shape : shapes)
	{
		if (shape && shape->isVisible())
			shape->draw(painter);
	}
}

CanvasWidget::CanvasWidget(const QList<Figure*>& shapes, QWidget *parent):
	QWidget(parent), shapes(shapes)
{ }