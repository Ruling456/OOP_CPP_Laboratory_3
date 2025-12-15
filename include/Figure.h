#pragma once

#include "Point.h"
#include <iostream>

// Абстрактный базовый класс для геометрических фигур
class Figure
{
public:
    virtual ~Figure() = default;

    // Получение геометрического центра фигуры
    virtual Point center() const = 0;

    // Вычисление площади фигуры
    virtual double area() const = 0;

    // Вывод координат вершин в поток
    virtual void printVertices(std::ostream& os) const = 0;

    // Чтение параметров фигуры из потока
    virtual void readFromStream(std::istream& is) = 0;

    // Создание копии фигуры
    virtual Figure* clone() const = 0;

    // Сравнение фигур на равенство
    virtual bool isEqual(const Figure* other) const = 0;

    // Получение названия типа фигуры
    virtual const char* typeName() const = 0;

    // Оператор приведения к double (площадь)
    explicit operator double() const
    {
        return area();
    }
};

// Перегрузка оператора вывода для фигуры
inline std::ostream& operator<<(std::ostream& os, const Figure& fig)
{
    fig.printVertices(os);
    return os;
}

// Перегрузка оператора ввода для фигуры
inline std::istream& operator>>(std::istream& is, Figure& fig)
{
    fig.readFromStream(is);
    return is;
}

// Оператор сравнения фигур
inline bool operator==(const Figure& lhs, const Figure& rhs)
{
    return lhs.isEqual(&rhs);
}