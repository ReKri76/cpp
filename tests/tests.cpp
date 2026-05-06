#include <QApplication>
#include <cassert>
#include <iostream>
import Shapes;

constexpr double DEFAULT_VALUE = 100;
constexpr bool VISIBLE = true;

constexpr double R = 100;
constexpr double X = 200;
constexpr double Y = 200;
constexpr double A = 300;

constexpr double HEIGHT_OF_TRIANGLE = (2*A*A*R)/(A*A-4*R*R);

std::vector<Figure*> createFigures();
void hideAll(std::vector<Figure*>* figures);
void showAll(std::vector<Figure*>* figures);
void moveAll(std::vector<Figure*>* figures, const double dx, const double dy);
void addAll(std::vector<Figure*>* figures, CanvasWidget*);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    try {
        std::cout << "Starting functional tests..." << std::endl;
//======================================================================================================================
        std::vector<Figure*> figures = createFigures();
        std::for_each(figures.begin(), figures.end(), [](const Figure* figure)
        {
            assert(figure!=nullptr && "Figures dont created");
        });
        std::cout << "Step (a) passed: Figures created." << std::endl;
//======================================================================================================================
        hideAll(&figures);
        std::for_each(figures.begin(), figures.end(), [](const Figure* figure)
        {
            assert(!figure->isVisible() &&  "Figures dont hidden");
        });

        showAll(&figures);
        std::for_each(figures.begin(), figures.end(), [](const Figure* figure)
        {
            assert(figure->isVisible() &&  "Figures dont show");
        });

        std::cout << "Step (b) passed: Visibility toggled." << std::endl;
//======================================================================================================================
        // в) Переместить фигуру
        moveAll(&figures, DEFAULT_VALUE, DEFAULT_VALUE);
        std::for_each(figures.begin(), figures.end(), [](const Figure* figure)
        {
            assert(figure->getX()==X+DEFAULT_VALUE && "Figures dont moved by x");
            assert(figure->getY()==Y+DEFAULT_VALUE &&  "Figures dont moved by y");
        });
        std::cout << "Step (c) passed: Figure moved." << std::endl;
//======================================================================================================================
        CanvasWidget* canvas_widget = new CanvasWidget();
        addAll(&figures, canvas_widget);
        std::cout << "Step (d) passed: Figures added to container." << std::endl;
//======================================================================================================================
        canvas_widget->show();
        std::cout << "Step (e) passed: Container ready for display." << std::endl;
//======================================================================================================================
        delete canvas_widget;
        std::cout << "Step (f) passed: Container deleted." << std::endl;
//======================================================================================================================

        std::cout << "\nAll functional tests passed successfully!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Test failed with error: " << e.what() << std::endl;
    }

    return 0;
}

std::vector<Figure*> createFigures()
{
    std::vector<Figure*> figures;

    CircleConfig circleConfig{};
    circleConfig.radius=R;
    circleConfig.visible=VISIBLE;
    circleConfig.x=X;
    circleConfig.y=Y;
    figures.push_back(new Circle(circleConfig));

    IsoscelesTriangleConfig triangleConfig{};
    triangleConfig.a=A;
    triangleConfig.heightOfTriangle=HEIGHT_OF_TRIANGLE;
    triangleConfig.visible=VISIBLE;
    triangleConfig.x=X;
    triangleConfig.y=Y;
    figures.push_back(new IsoscelesTriangle(triangleConfig));

    ComplexFigureConfig complexFigureConfig{};
    complexFigureConfig.circle = circleConfig;
    complexFigureConfig.triangle = triangleConfig;
    complexFigureConfig.visible=VISIBLE;
    complexFigureConfig.x=X;
    complexFigureConfig.y=Y;
    figures.push_back(new ComplexFigure(complexFigureConfig));

    return figures;
}

void hideAll(std::vector<Figure*>* figures)
{
    std::for_each(figures->begin(), figures->end(), [](Figure* figure)
    {
        figure->hide();
    });
}

void showAll(std::vector<Figure*>* figures)
{
    std::for_each(figures->begin(), figures->end(), [](Figure* figure)
    {
        figure->show();
    });
}

void moveAll(std::vector<Figure*>* figures, const double dx, const double dy)
{
    std::for_each(figures->begin(), figures->end(), [dx, dy](Figure* figure)
    {
        figure->move(dx, dy);
    });
}

void addAll(std::vector<Figure*>* figures, CanvasWidget* canvas_widget)
{
    std::for_each(figures->begin(), figures->end(), [canvas_widget](Figure* figure)
    {
        canvas_widget->push_back(figure);
    });
}