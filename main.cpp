//Чамкин Антон; 25Вп3; Курсовой проект; Сложная фигура - равнобедренный треугольник, окружность
#include <QApplication>
import Shapes;

constexpr double DEFAULT_VALUE = 100;
constexpr bool VISIBLE = true;

constexpr double R = 100;
constexpr double X = 200;
constexpr double Y = 200;
constexpr double A = 300;

constexpr double HEIGHT_OF_TRIANGLE = (2*A*A*R)/(A*A-4*R*R);

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

	if constexpr (HEIGHT_OF_TRIANGLE<=0)
		throw std::runtime_error("Высота треугольника не может быть не не отрицательной");

    CircleConfig circleConfig{};
    circleConfig.radius=R;
    circleConfig.visible=VISIBLE;
    circleConfig.x=X;
    circleConfig.y=Y;
    Circle* circle = new Circle(circleConfig);

    IsoscelesTriangleConfig triangleConfig{};
    triangleConfig.a=A;
    triangleConfig.heightOfTriangle=HEIGHT_OF_TRIANGLE;
    triangleConfig.visible=VISIBLE;
    triangleConfig.x=X;
    triangleConfig.y=Y;
    IsoscelesTriangle* triangle = new IsoscelesTriangle(triangleConfig);

	ComplexFigureConfig complexFigureConfig{};
    complexFigureConfig.circle = circleConfig;
    complexFigureConfig.triangle = triangleConfig;
	complexFigureConfig.visible=VISIBLE;
	complexFigureConfig.x=X;
	complexFigureConfig.y=Y;
    const ComplexFigure* complex = new ComplexFigure(complexFigureConfig);

    circle->hide();
    triangle->move(DEFAULT_VALUE,DEFAULT_VALUE);

	CanvasWidget* canvas_widget = new CanvasWidget();

    canvas_widget->push_back(new Circle(*circle));
    canvas_widget->push_back(new IsoscelesTriangle(*triangle));
    canvas_widget->push_back(new ComplexFigure(*complex));

	canvas_widget->show();

    return QApplication::exec();
}
