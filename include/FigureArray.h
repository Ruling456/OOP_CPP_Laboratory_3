#pragma once

#include "Figure.h"
#include <stdexcept>

// Динамический массив указателей на фигуры
class FigureArray
{
private:
    Figure** figures;    // Динамический массив указателей
    size_t currentSize;  // Текущее количество элементов
    size_t arrayCapacity; // Ёмкость массива

    // Увеличение ёмкости массива при необходимости
    void expandCapacity();

public:
    // Конструкторы
    FigureArray();
    explicit FigureArray(size_t initialCapacity);
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;

    // Операторы присваивания
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;

    // Деструктор
    ~FigureArray();

    // Добавление фигуры в конец массива
    void addFigure(Figure* figure);

    // Удаление фигуры по индексу
    void removeFigure(size_t index);

    // Получение фигуры по индексу
    const Figure* getFigure(size_t index) const;
    Figure* getFigure(size_t index);

    // Получение размера массива
    size_t size() const;

    // Вычисление суммарной площади всех фигур
    double totalArea() const;

    // Вывод информации обо всех фигурах
    void printAll(std::ostream& os) const;

    // Вывод центров и площадей всех фигур
    void printCentersAndAreas(std::ostream& os) const;

    // Оператор индексации
    const Figure* operator[](size_t index) const;
    Figure* operator[](size_t index);
};