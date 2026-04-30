module;
#include <cassert>
#include <iostream>
module Shapes;

void test_circle_logic() {
	CircleConfig cfg;
	cfg.x = 10.0;
	cfg.y = 20.0;
	cfg.visible = true;
	cfg.radius = 5.0;

	Circle circle(cfg);

	assert(circle.getX() == 10.0);
	assert(circle.getY() == 20.0);
	assert(circle.isVisible() == true);

	circle.move(5.0, 5.0);
	assert(circle.getX() == 15.0);

	circle.hide();
	assert(circle.isVisible() == false);

	std::cout << "Circle test: OK" << std::endl;
}

void test_complex_figure_logic() {
	ComplexFigureConfig cfg;
	cfg.x = 0; cfg.y = 0; cfg.visible = true;

	cfg.circle.radius = 10;
	cfg.triangle.a = 5;
	cfg.triangle.heightOfTriangle = 5;

	ComplexFigure complex(cfg);

	complex.move(10, 10);
	assert(complex.getX() == 10.0);

	complex.hide();
	assert(complex.isVisible() == false);

	std::cout << "ComplexFigure test: OK" << std::endl;
}

int main() {
	test_circle_logic();
	test_complex_figure_logic();
	std::cout << "--- ALL INTERNAL TESTS PASSED ---" << std::endl;
	return 0;
}