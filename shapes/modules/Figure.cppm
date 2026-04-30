module;
#include <QPainter>
export module Shapes:Figure;

export struct FigureConfig
{
	double x;
	double y;
	bool visible;
};

export class Figure
{
protected:
	double x{};
	double y{};
	bool visible{};
public:
	explicit Figure(const FigureConfig& config);
	explicit Figure(const Figure& figure);

	[[nodiscard]] double getX() const noexcept;
	[[nodiscard]] double getY() const noexcept;
	[[nodiscard]] bool isVisible() const;

	void virtual hide();
	void virtual show();
	void virtual move(double dx, double dy);

	virtual void draw(QPainter& painter) const = 0;
	virtual ~Figure() noexcept = default;
};