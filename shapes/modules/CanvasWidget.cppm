module;
#include <queue>
#include <QWidget>
export module Shapes:CanvasWidget;
import :Figure;

export class CanvasWidget : public QWidget {
private:
	std::queue<Figure *> *shapes;

public:
	explicit CanvasWidget(QWidget *parent = nullptr);
	void push(Figure* figure) const;
	[[nodiscard]] Figure* get() const;

	~CanvasWidget() override;

protected:
	void paintEvent(QPaintEvent *event) override;
};
