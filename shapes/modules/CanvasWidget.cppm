module;
#include <QWidget>
export module Shapes:CanvasWidget;
import :Figure;

export class CanvasWidget : public QWidget {
private:
	QList<Figure *> *shapes;

public:
	explicit CanvasWidget(QWidget *parent = nullptr);
	void push_top(Figure* figure);
	[[nodiscard]] Figure* put_top() const;
	void push_back(Figure* figure);
	[[nodiscard]] Figure* put_back() const;

	~CanvasWidget() override;

protected:
	void paintEvent(QPaintEvent *event) override;
};
