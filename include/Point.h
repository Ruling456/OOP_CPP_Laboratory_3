#pragma once

#include <iostream>
#include <cmath>

// Структура для представления точки в двумерном пространстве
struct Point
{
    double x;
    double y;

    // Конструкторы
    Point() : x(0.0), y(0.0) {}
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Оператор сравнения (с учётом погрешности)
    bool operator==(const Point& other) const
    {
        const double epsilon = 1e-9;
        return fabs(x - other.x) < epsilon && fabs(y - other.y) < epsilon;
    }

    // Вычисление расстояния до другой точки
    double distanceTo(const Point& other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

// Перегрузка оператора вывода для Point
inline std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}

// Перегрузка оператора ввода для Point
inline std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}