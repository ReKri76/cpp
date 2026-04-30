module;
#include <QWidget>
export module Shapes:CanvasWidget;
import :Figure;

export class CanvasWidget : public QWidget {
private:
	const QList<Figure*>& shapes;

public:
	explicit CanvasWidget(const QList<Figure*>& shapes, QWidget *parent = nullptr);

protected:
	void paintEvent(QPaintEvent *event) override;
};
