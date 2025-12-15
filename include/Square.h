#pragma once

#include "Figure.h"
#include <array>
#include <cmath>
#include <stdexcept>

// Класс квадрата
class Square : public Figure
{
private:
    std::array<Point, 4> vertices;

public:
    // Конструктор по умолчанию
    Square();

    // Конструктор с четырьмя вершинами
    Square(const Point &p1, const Point &p2, const Point &p3, const Point &p4);

    // Копирующий конструктор
    Square(const Square &other);

    // Перемещающий конструктор
    Square(Square &&other) noexcept;

    // Оператор копирующего присваивания
    Square &operator=(const Square &other);

    // Оператор перемещающего присваивания
    Square &operator=(Square &&other) noexcept;

    // Деструктор
    ~Square() override = default;

    // Оператор сравнения для Square
    bool operator==(const Square &other) const;

    // Реализация абстрактных методов Figure
    Point center() const override;
    double area() const override;
    void printVertices(std::ostream &os) const override;
    void readFromStream(std::istream &is) override;
    Figure *clone() const override;
    bool isEqual(const Figure* other) const override;
    const char* typeName() const override;

    // Получение вершин
    const std::array<Point, 4> &getVertices() const { return vertices; }

private:
    // Проверка корректности квадрата
    bool isValid() const;
};