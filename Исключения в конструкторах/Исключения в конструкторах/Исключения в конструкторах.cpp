#include <iostream>
#include <vector>
#include <stdexcept>
#include <windows.h>

class Figure {
public:
    Figure(const char* n) : name(n) {}
    virtual ~Figure() {}
    std::vector<double> getSides() const {
        return sides;
    }
    std::vector<double> getAngles() const {
        return angles;
    }
    const char* getName() const {
        return name;
    }
protected:
    const char* name;
    std::vector<double> sides;
    std::vector<double> angles;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c, double A, double B, double C) : Figure("Треугольник") {
        if ((a + b > c) && (a + c > b) && (b + c > a) && (A + B + C == 180)) {
            sides = { a, b, c };
            angles = { A, B, C };
            std::cout << "Треугольник (стороны a=" << a << ", b=" << b << ", c=" << c
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ") создан" << std::endl;
        }
        else {
            throw std::domain_error("Ошибка создания фигуры. Причина: неверные параметры");
        }
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("Четырёхугольник") {
        if (A + B + C + D != 360) {
            sides = { a, b, c, d };
            angles = { A, B, C, D };
            std::cout << "Четырёхугольник (стороны a=" << a << ", b=" << b << ", c=" << c << ", d=" << d
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << ") создан" << std::endl;
        }
        else {
            throw std::domain_error("Ошибка создания фигуры. Причина: неверные параметры");
        }
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c) : Triangle(a, b, c, 45, 45, 90) {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double c) : Triangle(a, b, c, 60, 60, 60) {
        if (a != c) {
            name = "Равнобедренный треугольник";
        }
        else {
            throw std::domain_error("Ошибка создания фигуры. Причина: у равнобедренного треугольника должны быть равны стороны a и c");
        }
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
        if (a != sides[1] || a != sides[2] || angles[0] != 60 || angles[1] != 60 || angles[2] != 60) {
            throw std::domain_error("Ошибка создания фигуры. Причина: у равностороннего треугольника должны быть равны все стороны и все углы равны 60");
        }
        name = "Равносторонний треугольник";
    }
};

class Rectangl : public Quadrilateral {
public:
    Rectangl(double a, double b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
        if (a != sides[0] || a != sides[2] || b != sides[1] || b != sides[3] ||
            angles[0] != 90 || angles[1] != 90 || angles[2] != 90 || angles[3] != 90) {
            throw std::domain_error("Ошибка создания фигуры. Причина: у прямоугольника должны быть равны стороны a и c, стороны b и d, и все углы должны быть равны 90");
        }
        name = "Прямоугольник";
    }
};

class Square : public Quadrilateral {
public:
    Square(double a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90) {
        if (a != sides[0] || a != sides[2] || a != sides[1] || a != sides[3] ||
            angles[0] != 90 || angles[1] != 90 || angles[2] != 90 || angles[3] != 90) {
            throw std::domain_error("Ошибка создания фигуры. Причина: у квадрата все стороны должны быть равны, и все углы должны быть равны 90");
        }
        name = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double a, double b, double A) : Quadrilateral(a, b, a, b, A, 180 - A, A, 180 - A) {
        if (a != sides[0] || a != sides[2] || b != sides[1] || b != sides[3] ||
            angles[0] != A || angles[1] != (180 - A) || angles[2] != A || angles[3] != (180 - A)) {
            throw std::domain_error("Ошибка создания фигуры. Причина: у параллелограмма должны быть равны стороны a и c, стороны b и d, углы A и C, углы B и D");
        }
        name = "Параллелограмм";
    }
};

class Rhombus : public Quadrilateral {
public:
    Rhombus(double a, double A) : Quadrilateral(a, a, a, a, A, 180 - A, A, 180 - A) {
        if (a != sides[0] || a != sides[2] || a != sides[1] || a != sides[3] ||
            angles[0] != A || angles[1] != (180 - A) || angles[2] != A || angles[3] != (180 - A)) {
            throw std::domain_error("Ошибка создания фигуры. Причина: у ромба должны быть равны все стороны и углы A и C, углы B и D");
        }
        name = "Ромб";
    }
};

int main() {
    SetConsoleOutputCP(65001);
    try {
        Triangle triangle(10, 10, 10, 60, 60, 60);
        Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
        RightTriangle rightTriangle(10, 20, 30);
        IsoscelesTriangle isoscelesTriangle(10, 20, 10);
        EquilateralTriangle equilateralTriangle(30);
        Rectangl rectangle(10, 20);
        Square square(20);
        Parallelogram parallelogram(20, 30, 30);
        Rhombus rhombus(30, 30);
    }
    catch (const std::domain_error& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
    return 0;
}