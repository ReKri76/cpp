module;
#include <cassert>
#include <iostream>
module Shapes;

void test_circle_logic() {
    CircleConfig cfg{};
    cfg.x = 10.0;
    cfg.y = 20.0;
    cfg.visible = true;
    cfg.radius = 5.0;

    Circle circle(cfg);

    assert(circle.getX() == 10.0);
    assert(circle.getY() == 20.0);
    assert(circle.isVisible() == true);
    assert(circle.getRadius() == 5.0);

    circle.move(5.0, 7.0);
    assert(circle.getX() == 15.0);
    assert(circle.getY() == 27.0);

    circle.hide();
    assert(circle.isVisible() == false);

    circle.show();
    assert(circle.isVisible() == true);

    std::cout << "Circle test: OK" << std::endl;
}

void test_isosceles_triangle_logic() {
    IsoscelesTriangleConfig cfg{};
    cfg.x = 0.0;
    cfg.y = 0.0;
    cfg.visible = true;
    cfg.a = 10.0;
    cfg.heightOfTriangle = 8.0;

    IsoscelesTriangle triangle(cfg);

    assert(triangle.getX() == 0.0);
    assert(triangle.getY() == 0.0);
    assert(triangle.isVisible() == true);

    triangle.move(3.0, 4.0);
    assert(triangle.getX() == 3.0);
    assert(triangle.getY() == 4.0);

    triangle.hide();
    assert(triangle.isVisible() == false);

    std::cout << "IsoscelesTriangle test: OK" << std::endl;
}

void test_complex_figure_logic() {
    ComplexFigureConfig cfg{};
    cfg.x = 0.0;
    cfg.y = 0.0;
    cfg.visible = true;

    cfg.circle.radius = 10.0;
    cfg.circle.x = 0.0;
    cfg.circle.y = 0.0;

    cfg.triangle.a = 12.0;
    cfg.triangle.heightOfTriangle = 8.0;
    cfg.triangle.x = 0.0;
    cfg.triangle.y = 0.0;

    ComplexFigure complex(cfg);

    assert(complex.getX() == 0.0);
    assert(complex.getY() == 0.0);
    assert(complex.isVisible() == true);

    complex.move(10.0, 20.0);
    assert(complex.getX() == 10.0);
    assert(complex.getY() == 20.0);

    assert(complex.getCircle() && complex.getCircle()->getX() == 10.0);
    assert(complex.getCircle() && complex.getCircle()->getY() == 20.0);
    assert(complex.getIsoscelesTriangle() && complex.getIsoscelesTriangle()->getX() == 10.0);
    assert(complex.getIsoscelesTriangle() && complex.getIsoscelesTriangle()->getY() == 20.0);

    complex.hide();
    assert(complex.isVisible() == false);
    assert(complex.getCircle() && !complex.getCircle()->isVisible());
    assert(complex.getIsoscelesTriangle() && !complex.getIsoscelesTriangle()->isVisible());

    complex.show();
    assert(complex.isVisible() == true);
    assert(complex.getCircle() && complex.getCircle()->isVisible());
    assert(complex.getIsoscelesTriangle() && complex.getIsoscelesTriangle()->isVisible());

    std::cout << "ComplexFigure test: OK" << std::endl;
}

int main() {
    test_circle_logic();
    test_isosceles_triangle_logic();
    test_complex_figure_logic();

    std::cout << "\n--- ALL INTERNAL TESTS PASSED SUCCESSFULLY ---" << std::endl;
    return 0;
}