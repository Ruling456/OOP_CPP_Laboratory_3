#pragma once

#include "Figure.h"
#include <array>
#include <cmath>
#include <stdexcept>

// Класс треугольника
class Triangle : public Figure
{
private:
    std::array<Point, 3> vertices;

public:
    // Конструктор по умолчанию
    Triangle();

    // Конструктор с тремя вершинами
    Triangle(const Point &p1, const Point &p2, const Point &p3);

    // Копирующий конструктор
    Triangle(const Triangle &other);

    // Перемещающий конструктор
    Triangle(Triangle &&other) noexcept;

    // Оператор копирующего присваивания
    Triangle &operator=(const Triangle &other);

    // Оператор перемещающего присваивания
    Triangle &operator=(Triangle &&other) noexcept;

    // Деструктор
    ~Triangle() override = default;

    // Оператор сравнения для Triangle
    bool operator==(const Triangle &other) const;

    // Реализация абстрактных методов Figure
    Point center() const override;
    double area() const override;
    void printVertices(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;
    Figure *clone() const override;
    bool isEqual(const Figure* other) const override;
    const char* typeName() const override;

    // Получение вершин
    const std::array<Point, 3> &getVertices() const { return vertices; }

private:
    // Проверка корректности треугольника
    bool isValid() const;
};