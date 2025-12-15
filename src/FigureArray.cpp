#include "FigureArray.h"
#include <iomanip>

// Конструктор по умолчанию
FigureArray::FigureArray() : figures(nullptr), arrayCapacity(0), currentSize(0) {}

// Конструктор с начальной ёмкостью
FigureArray::FigureArray(size_t initialCapacity)
    : figures(new Figure*[initialCapacity]),
        arrayCapacity(initialCapacity),
        currentSize(0)
{
    for (size_t i = 0; i < arrayCapacity; ++i)
    {
        figures[i] = nullptr;
    }
}

// Копирующий конструктор
FigureArray::FigureArray(const FigureArray &other)
    : figures(new Figure*[other.arrayCapacity]),
        arrayCapacity(other.arrayCapacity),
        currentSize(other.currentSize)
{
    for (size_t i = 0; i < arrayCapacity; ++i)
    {
        figures[i] = nullptr;
    }
    for (size_t i = 0; i < currentSize; ++i)
    {
        figures[i] = other.figures[i]->clone();
    }
}

// Перемещающий конструктор
FigureArray::FigureArray(FigureArray &&other) noexcept
    : figures(other.figures), 
        arrayCapacity(other.arrayCapacity), 
        currentSize(other.currentSize)
{
    other.figures = nullptr;
    other.arrayCapacity = 0;
    other.currentSize = 0;
}

// Оператор копирующего присваивания
FigureArray &FigureArray::operator=(const FigureArray &other)
{
    if (this != &other)
    {
        // Освобождаем старые данные
        for (size_t i = 0; i < currentSize; ++i)
        {
            delete figures[i];
        }
        delete[] figures;

        // Копируем новые данные
        arrayCapacity = other.arrayCapacity;
        currentSize = other.currentSize;
        figures = new Figure*[arrayCapacity];

        for (size_t i = 0; i < arrayCapacity; ++i)
        {
            figures[i] = nullptr;
        }
        for (size_t i = 0; i < currentSize; ++i)
        {
            figures[i] = other.figures[i]->clone();
        }
    }
    return *this;
}

// Оператор перемещающего присваивания
FigureArray &FigureArray::operator=(FigureArray &&other) noexcept
{
    if (this != &other)
    {
        // Освобождаем старые данные
        for (size_t i = 0; i < currentSize; ++i)
        {
            delete figures[i];
        }
        delete[] figures;

        // Перемещаем данные
        figures = other.figures;
        arrayCapacity = other.arrayCapacity;
        currentSize = other.currentSize;

        // Обнуляем источник
        other.figures = nullptr;
        other.arrayCapacity = 0;
        other.currentSize = 0;
    }
    return *this;
}

// Деструктор
FigureArray::~FigureArray()
{
    for (size_t i = 0; i < currentSize; ++i)
    {
        delete figures[i];
    }
    delete[] figures;
}

// Увеличение ёмкости массива
void FigureArray::expandCapacity()
{
    size_t newCapacity = (arrayCapacity == 0) ? 1 : arrayCapacity * 2;
    Figure** newFigures = new Figure*[newCapacity];

    for (size_t i = 0; i < newCapacity; ++i)
    {
        newFigures[i] = nullptr;
    }

    for (size_t i = 0; i < currentSize; ++i)
    {
        newFigures[i] = figures[i];
    }

    delete[] figures;
    figures = newFigures;
    arrayCapacity = newCapacity;
}

// Добавление фигуры в массив
void FigureArray::addFigure(Figure* figure)
{
    if (currentSize >= arrayCapacity)
    {
        expandCapacity();
    }
    figures[currentSize++] = figure;
}

// Удаление фигуры по индексу
void FigureArray::removeFigure(size_t index)
{
    if (index >= currentSize)
    {
        throw std::out_of_range("Index out of range");
    }

    // Удаляем фигуру
    delete figures[index];

    // Сдвигаем элементы влево
    for (size_t i = index; i < currentSize - 1; ++i)
    {
        figures[i] = figures[i + 1];
    }

    figures[currentSize - 1] = nullptr;
    --currentSize;
}

// Получение фигуры по индексу (константная версия)
const Figure* FigureArray::getFigure(size_t index) const
{
    if (index >= currentSize)
    {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}

// Получение фигуры по индексу (неконстантная версия)
Figure* FigureArray::getFigure(size_t index)
{
    if (index >= currentSize)
    {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}

// Получение размера массива
size_t FigureArray::size() const
{
    return currentSize;
}

// Вычисление общей площади всех фигур
double FigureArray::totalArea() const
{
    double total = 0.0;
    for (size_t i = 0; i < currentSize; ++i)
    {
        total += static_cast<double>(*figures[i]);
    }
    return total;
}

// Печать всех фигур
void FigureArray::printAll(std::ostream& os) const
{
    for (size_t i = 0; i < currentSize; ++i)
    {
        os << i << ": " << *figures[i] << std::endl;
    }
}

// Печать информации о центрах и площадях
void FigureArray::printCentersAndAreas(std::ostream& os) const
{
    os << std::fixed << std::setprecision(4);
    for (size_t i = 0; i < currentSize; ++i)
    {
        Point center = figures[i]->center();
        double area = static_cast<double>(*figures[i]);
        os << i << ": " << figures[i]->typeName()
            << " - Center: " << center
            << ", Area: " << area << std::endl;
    }
}

// Оператор индексации (константная версия)
const Figure* FigureArray::operator[](size_t index) const
{
    return getFigure(index);
}

// Оператор индексации (неконстантная версия)
Figure* FigureArray::operator[](size_t index)
{
    return getFigure(index);
}