#include <iostream>
#include <limits>
#include <string>
#include "../include/FigureArray.h"
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Octagon.h"

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMenu()
{
    std::cout << "\n=== Меню работы с фигурами ===" << std::endl;
    std::cout << "1. Добавить треугольник" << std::endl;
    std::cout << "2. Добавить квадрат" << std::endl;
    std::cout << "3. Добавить восьмиугольник" << std::endl;
    std::cout << "4. Показать все фигуры" << std::endl;
    std::cout << "5. Показать центры и площади" << std::endl;
    std::cout << "6. Вычислить общую площадь" << std::endl;
    std::cout << "7. Удалить фигуру по индексу" << std::endl;
    std::cout << "8. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

void addTriangle(FigureArray &figures)
{
    std::cout << "Введите координаты трех вершин треугольника (x1 y1 x2 y2 x3 y3):" << std::endl;

    try
    {
        Triangle *triangle = new Triangle();
        std::cin >> *triangle;

        if (std::cin.fail())
        {
            delete triangle;
            clearInput();
            std::cout << "Ошибка ввода!" << std::endl;
            return;
        }

        figures.addFigure(triangle);
        std::cout << "Треугольник успешно добавлен!" << std::endl;
    }
    catch (const std::exception &e)
    {
        clearInput();
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

void addSquare(FigureArray &figures)
{
    std::cout << "Введите координаты четырех вершин квадрата (x1 y1 x2 y2 x3 y3 x4 y4):" << std::endl;

    try
    {
        Square *square = new Square();
        std::cin >> *square;

        if (std::cin.fail())
        {
            delete square;
            clearInput();
            std::cout << "Ошибка ввода!" << std::endl;
            return;
        }

        figures.addFigure(square);
        std::cout << "Квадрат успешно добавлен!" << std::endl;
    }
    catch (const std::exception &e)
    {
        clearInput();
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

void addOctagon(FigureArray &figures)
{
    std::cout << "Введите координаты восьми вершин восьмиугольника (x1 y1 x2 y2 ... x8 y8):" << std::endl;

    try
    {
        Octagon *octagon = new Octagon();
        std::cin >> *octagon;

        if (std::cin.fail())
        {
            delete octagon;
            clearInput();
            std::cout << "Ошибка ввода!" << std::endl;
            return;
        }

        figures.addFigure(octagon);
        std::cout << "Восьмиугольник успешно добавлен!" << std::endl;
    }
    catch (const std::exception &e)
    {
        clearInput();
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

void showAllFigures(const FigureArray &figures)
{
    if (figures.size() == 0)
    {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }

    std::cout << "\nВсе фигуры:" << std::endl;
    figures.printAll(std::cout);
}

void showCentersAndAreas(const FigureArray &figures)
{
    if (figures.size() == 0)
    {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }

    std::cout << "\nЦентры и площади фигур:" << std::endl;
    figures.printCentersAndAreas(std::cout);
}

void showTotalArea(const FigureArray &figures)
{
    if (figures.size() == 0)
    {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }

    double totalArea = figures.totalArea();
    std::cout << "Общая площадь всех фигур: " << totalArea << std::endl;
}

void removeFigure(FigureArray &figures)
{
    if (figures.size() == 0)
    {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }

    std::cout << "Введите индекс фигуры для удаления (0-" << figures.size() - 1 << "): ";
    size_t index;
    std::cin >> index;

    if (std::cin.fail())
    {
        clearInput();
        std::cout << "Ошибка ввода!" << std::endl;
        return;
    }

    try
    {
        figures.removeFigure(index);
        std::cout << "Фигура успешно удалена!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

int main()
{
    FigureArray figures;
    int choice;

    std::cout << "Программа для работы с геометрическими фигурами" << std::endl;

    while (true)
    {
        printMenu();
        std::cin >> choice;

        if (std::cin.fail())
        {
            clearInput();
            std::cout << "Неверный ввод! Попробуйте снова." << std::endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            addTriangle(figures);
            break;
        case 2:
            addSquare(figures);
            break;
        case 3:
            addOctagon(figures);
            break;
        case 4:
            showAllFigures(figures);
            break;
        case 5:
            showCentersAndAreas(figures);
            break;
        case 6:
            showTotalArea(figures);
            break;
        case 7:
            removeFigure(figures);
            break;
        case 8:
            std::cout << "Выход из программы." << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
        }
    }

    return 0;
}