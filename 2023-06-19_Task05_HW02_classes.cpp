#include <iostream>
#include <Windows.h>
#include <string>

class Figure {
protected:
	int sides_count, a, b, c, d, A, B, C, D;
	std::string name;
public:
	int get_sides() { return sides_count; }
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }
	std::string get_name() { return this->name; }
};

class Triangle : public Figure {
public:
	Triangle() {};
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->sides_count = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->name = "Треугольник";
	};
};

class R_triangle : public Triangle {
public:
	R_triangle(int a, int b, int c, int A, int B) {
		this->sides_count = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = 90;
		this->name = "Прямоугольный треугольник";
	};
};

class I_triangle : public Triangle {
public:
	I_triangle(int a, int b, int A, int B) {
		this->sides_count = 3;
		this->a = a;
		this->b = b;
		this->c = a;
		this->A = A;
		this->B = B;
		this->C = A;
		this->name = "Равнобедренный треугольник";
	};
};

class E_triangle : public Triangle {
public:
	E_triangle(int a) {
		this->sides_count = 3;
		this->a = a;
		this->b = a;
		this->c = a;
		this->A = 60;
		this->B = 60;
		this->C = 60;
		this->name = "Равносторонний треугольник";
	};
};

class Quadrangle : public Figure {
public:
	Quadrangle() {};
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->sides_count = 4;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->name = "Четырёхугольник";
	};
};

class Rectangle_ : public Quadrangle {
public:
	Rectangle_(int a, int b) {
		this->sides_count = 4;
		this->a = a;
		this->b = b;
		this->c = a;
		this->d = b;
		this->A = 90;
		this->B = 90;
		this->C = 90;
		this->D = 90;
		this->name = "Прямоугольник";
	};
};

class Square : public Quadrangle {
public:
	Square(int a) {
		this->sides_count = 4;
		this->a = a;
		this->b = a;
		this->c = a;
		this->d = a;
		this->A = 90;
		this->B = 90;
		this->C = 90;
		this->D = 90;
		this->name = "Квадрат";
	};
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) {
		this->sides_count = 4;
		this->a = a;
		this->b = b;
		this->c = a;
		this->d = b;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->name = "Параллелограмм";
	};
};

class Rhomb : public Quadrangle {
public:
	Rhomb(int a, int A, int B) {
		this->sides_count = 4;
		this->a = a;
		this->b = a;
		this->c = a;
		this->d = a;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->name = "Ромб";
	};
};

void print_info(Figure* p) {
	std::cout << p->get_name() << ":" << std::endl;
	switch (p->get_sides()) {
	case 3:
		std::cout << "Стороны: a=" << p->get_a() << " b=" << p->get_b() << " c=" << p->get_c() << std::endl;
		std::cout << "Углы: A=" << p->get_A() << " B=" << p->get_B() << " C=" << p->get_C() << std::endl;
		break;
	case 4:
		std::cout << "Стороны: a=" << p->get_a() << " b=" << p->get_b() << " c=" << p->get_c() << " d=" << p->get_d() << std::endl;
		std::cout << "Углы: A=" << p->get_A() << " B=" << p->get_B() << " C=" << p->get_C() << " D=" << p->get_D() << std::endl;
		break;
	}
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle triangle{ 10, 20, 30, 50, 60, 70 };				// Треугольник
	R_triangle r_triangle{ 10, 20, 30, 50, 60 };				// Прямоугольный треугольник
	I_triangle i_triangle{ 10, 20, 50, 60 };					// Равнобедренный треугольник
	E_triangle e_triangle{ 30 };									// Равносторонний треугольник
	Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };	// Четырёхугольник
	Rectangle_ rectangle{ 10, 20 };								// Прямоугольник
	Square square{ 20 };										// Квадрат
	Parallelogram parallelogram{ 20, 30, 30, 40 };				// Параллелограмм
	Rhomb rhomb{ 30, 30, 40 };									// Ромб

	print_info(&triangle);
	print_info(&r_triangle);
	print_info(&i_triangle);
	print_info(&e_triangle);
	print_info(&quadrangle);
	print_info(&rectangle);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rhomb);
	system("pause");
}