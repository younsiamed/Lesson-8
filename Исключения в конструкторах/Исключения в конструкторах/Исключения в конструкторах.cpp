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

class FigureCreationError : public std::domain_error {
public:
    FigureCreationError(const std::string& msg) : std::domain_error(msg) {}
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
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class RightTriangle : public Figure {
public:
    RightTriangle(double a, double b, double c, double A, double B, double C) : Figure("Прямоугольный треугольник") {
        if ((A + B + C == 180) && (C != 90)) {
            sides = { a, b, c };
            angles = { A, B, C };
            std::cout << "Прямоугольный треугольник (стороны a=" << a << ", b=" << b << ", c=" << c
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class IsoscelesTriangle : public Figure {
public:
    IsoscelesTriangle(double a, double b, double c, double A, double B, double C) : Figure("Равнобедренный треугольник") {
        if ((A + B + C == 180) && (a == c)) {
            sides = { a, b, c };
            angles = { A, B, C };
            std::cout << "Равнобедренный треугольник (стороны a=" << a << ", b=" << b << ", c=" << c
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class EquilateralTriangle : public Figure {
public:
    EquilateralTriangle(double a, double b, double c, double A, double B, double C) : Figure("Равносторонний треугольник") {
        if ((A + B + C == 180) && (a == b && b == c) && (A == B && B == C)) {
            sides = { a, b, c };
            angles = { A, B, C };
            std::cout << "Равносторонний треугольник (стороны a=" << a << ", b=" << b << ", c=" << c
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("Четырёхугольник") {
        if (A + B + C + D == 360) {
            sides = { a, b, c, d };
            angles = { A, B, C, D };
            std::cout << "Четырёхугольник (стороны a=" << a << ", b=" << b << ", c=" << c << ", d=" << d
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class Rectangl : public Figure {
public:
    Rectangl(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("Прямоугольник") {
        if ((A == 90 && B == 90 && C == 90 && D == 90) && ((a == c) && (b == d))) {
            sides = { a, b, c, d };
            angles = { A, B, C, D };
            std::cout << "Прямоугольник (стороны a=" << a << ", b=" << b << ", c=" << c << ", d=" << d
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class Square : public Figure {
public:
    Square(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("Квадрат") {
        if (A + B + C + D == 360 || a == b == c == d) {
            sides = { a, b, c, d };
            angles = { A, B, C, D };
            std::cout << "Квадрат (стороны a=" << a << ", b=" << b << ", c=" << c << ", d=" << d
            << "; углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class Parallelogram : public Figure {
public:
    Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("Параллелограмм") {
        if (a == c || b == d || B == C || A + C == 180) {
            sides = { a, b, c, d };
            angles = { A, B, C, D };
            std::cout << "Параллелограмм (стороны a=" << a << ", b=" << b << ", c=" << c << ", d=" << d
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

class Rhombus : public Figure {
public:
    Rhombus(double a, double b, double c, double d, double A, double B, double C, double D) : Figure("Ромб") {
        if (a == b && b == c && c == d && A == B && B == C && C == D && A + B + C + D == 360) {
            sides = { a, b, c, d };
            angles = { A, B, C, D };
            std::cout << "Ромб (стороны a=" << a << ", b=" << b << ", c=" << c << ", d=" << d
                << "; углы A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << ") создан" << std::endl;
        }
        else {
            throw FigureCreationError("Причина: неверные параметры");
        }
    }
};

int main() {
    SetConsoleOutputCP(65001);
    try {
        Triangle triangle(30, 30, 30, 60, 60, 60);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Треугольник. " << e.what() << std::endl;
    }
    try {
        RightTriangle rightTriangle(5, 13, 12, 60, 30, 90);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Прямоугольный треугольник. " << e.what() << std::endl;
    }
    try {
        IsoscelesTriangle isoscelesTriangle(20, 20, 20, 60, 60, 60);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Равнобедренный треугольник. " << e.what() << std::endl;
    }
    try {
        EquilateralTriangle equilateralTriangle(30, 30, 30, 60, 60, 60);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Равносторонний треугольник. " << e.what() << std::endl;
    }
    try {
        Quadrilateral quadrilateral(20, 20, 20, 20, 90, 90, 90, 90);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Четырёхугольник. " << e.what() << std::endl;
    }
    try {
        Rectangl rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Прямоугольник. " << e.what() << std::endl;
    }
    try {
        Square square(20, 20, 20, 20, 90, 90, 90, 90);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Квадрат. " << e.what() << std::endl;
    }
    try {
        Parallelogram parallelogram(30, 20, 30, 20, 100, 80, 100, 80);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Параллелограмм. " << e.what() << std::endl;
    }
    try {
        Rhombus rhombus(30, 30, 30, 30, 90, 90, 90, 90);
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка создания Ромб. " << e.what() << std::endl;
    }
    return 0;
}
