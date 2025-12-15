#include <gtest/gtest.h>
#include "FigureArray.h"
#include "Triangle.h"
#include "Square.h"
#include "Octagon.h"

// Тесты для класса FigureArray

TEST(FigureArrayTest, DefaultConstructor)
{
    FigureArray array;
    EXPECT_EQ(array.size(), 0);
}

TEST(FigureArrayTest, AddFigure)
{
    FigureArray array;

    Triangle *triangle = new Triangle();
    array.addFigure(triangle);

    EXPECT_EQ(array.size(), 1);
}

TEST(FigureArrayTest, AddMultipleFigures)
{
    FigureArray array;

    array.addFigure(new Triangle());
    array.addFigure(new Square());
    array.addFigure(new Octagon());

    EXPECT_EQ(array.size(), 3);
}

TEST(FigureArrayTest, RemoveFigure)
{
    FigureArray array;

    array.addFigure(new Triangle());
    array.addFigure(new Square());
    array.addFigure(new Octagon());

    array.removeFigure(1);

    EXPECT_EQ(array.size(), 2);
}

TEST(FigureArrayTest, RemoveInvalidIndex)
{
    FigureArray array;
    array.addFigure(new Triangle());

    EXPECT_THROW(array.removeFigure(5), std::out_of_range);
}

TEST(FigureArrayTest, GetFigure)
{
    FigureArray array;

    Triangle *triangle = new Triangle();
    double area = triangle->area();
    array.addFigure(triangle);

    const Figure *fig = array.getFigure(0);
    EXPECT_DOUBLE_EQ(fig->area(), area);
}

TEST(FigureArrayTest, GetInvalidIndex)
{
    FigureArray array;

    EXPECT_THROW(array.getFigure(0), std::out_of_range);
}

TEST(FigureArrayTest, GetTotalArea)
{
    FigureArray array;

    Point p1(0, 0), p2(2, 0), p3(2, 2), p4(0, 2);
    Square *square = new Square(p1, p2, p3, p4);
    double squareArea = square->area();

    Point t1(0, 0), t2(4, 0), t3(0, 3);
    Triangle *triangle = new Triangle(t1, t2, t3);
    double triangleArea = triangle->area();

    array.addFigure(square);
    array.addFigure(triangle);

    EXPECT_DOUBLE_EQ(array.totalArea(), squareArea + triangleArea);
}

TEST(FigureArrayTest, IndexOperator)
{
    FigureArray array;

    array.addFigure(new Triangle());

    const Figure *fig = array[0];
    EXPECT_NE(fig, nullptr);
}

TEST(FigureArrayTest, CopyConstructor)
{
    FigureArray array1;

    array1.addFigure(new Triangle());
    array1.addFigure(new Square());

    FigureArray array2(array1);

    EXPECT_EQ(array1.size(), array2.size());
    EXPECT_DOUBLE_EQ(array1.totalArea(), array2.totalArea());
}

TEST(FigureArrayTest, MoveConstructor)
{
    FigureArray array1;

    array1.addFigure(new Triangle());
    array1.addFigure(new Square());

    size_t size = array1.size();
    double area = array1.totalArea();

    FigureArray array2(std::move(array1));

    EXPECT_EQ(array2.size(), size);
    EXPECT_DOUBLE_EQ(array2.totalArea(), area);
    EXPECT_EQ(array1.size(), 0);
}

TEST(FigureArrayTest, CopyAssignment)
{
    FigureArray array1;
    FigureArray array2;

    array1.addFigure(new Triangle());
    array1.addFigure(new Square());

    array2 = array1;

    EXPECT_EQ(array1.size(), array2.size());
    EXPECT_DOUBLE_EQ(array1.totalArea(), array2.totalArea());
}

TEST(FigureArrayTest, MoveAssignment)
{
    FigureArray array1;
    FigureArray array2;

    array1.addFigure(new Triangle());
    array1.addFigure(new Square());

    size_t size = array1.size();
    double area = array1.totalArea();

    array2 = std::move(array1);

    EXPECT_EQ(array2.size(), size);
    EXPECT_DOUBLE_EQ(array2.totalArea(), area);
    EXPECT_EQ(array1.size(), 0);
}