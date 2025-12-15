#pragma once

#include "Figure.h"
#include <array>
#include <cmath>
#include <stdexcept>

// Класс правильного восьмиугольника
class Octagon : public Figure
{
private:
    std::array<Point, 8> vertices;

public:
    // Конструктор по умолчанию
    Octagon();

    // Конструктор с восемью вершинами
    Octagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4,
            const Point &p5, const Point &p6, const Point &p7, const Point &p8);

    // Копирующий конструктор
    Octagon(const Octagon &other);

    // Перемещающий конструктор
    Octagon(Octagon &&other) noexcept;

    // Оператор копирующего присваивания
    Octagon &operator=(const Octagon &other);

    // Оператор перемещающего присваивания
    Octagon &operator=(Octagon &&other) noexcept;

    // Деструктор
    ~Octagon() override = default;

    // Оператор сравнения для Octagon
    bool operator==(const Octagon &other) const;

    // Реализация абстрактных методов Figure
    Point center() const override;
    double area() const override;
    void printVertices(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;
    Figure *clone() const override;
    bool isEqual(const Figure* other) const override;
    const char* typeName() const override;

    // Получение вершин
    const std::array<Point, 8> &getVertices() const { return vertices; }

private:
    // Проверка корректности восьмиугольника
    bool isValid() const;
};