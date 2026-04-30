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

	if constexpr (A<=2*R)
		return 0;

    QList<Figure*> figures;

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

    figures.push_back(new Circle(*circle));
    figures.push_back(new IsoscelesTriangle(*triangle));
    figures.push_back(new ComplexFigure(*complex));

    CanvasWidget canvas_widget(figures);
	canvas_widget.show();

    return QApplication::exec();
}
