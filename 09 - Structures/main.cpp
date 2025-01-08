#include <iostream>
#include <cmath>

const double P = 3.141592;

struct Vector {
	double x1, y1, x2, y2;
	Vector(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
};

bool equal(Vector &a, Vector &b) {
	if ((a.x1 == b.x1 && a.y1 == b.y1 && a.x2 == b.x2 && a.y2 == b.y2) ||
		(a.x1 == b.x2 && a.y1 == b.y2 && a.x2 == b.x1 && a.y2 == b.y1)) {
		return true;
	}
	else {
		return false;
	}
}
double distance(Vector &a) {
	return sqrt(pow((a.x1 - a.x2), 2) + pow((a.y1 - a.y2), 2));
}
double angle(Vector &a, Vector &b) {
	if (equal(a, b)) {
		return 0;
	}
	else if (a.x1 == b.x1 && a.y1 == b.y1){
		Vector c(a.x2, b.y2, a.x2, b.y2);
}
	else if (a.x2 == b.x2 && a.y2 == b.y2) {
		Vector c(a.x1, b.y1, a.x1, b.y1);
	}
	else if (a.x1 == b.x2 && a.y1 == b.y2) {
		Vector c(a.x2, b.y2, a.x1, b.y1);
	}
	else if (a.x2 == b.x1 && a.y2 == b.y1) {
		Vector c(a.x1, b.y1, a.x2, b.y2);
	}
	else {
		return 666;
	}
	Vector c(a.x1 != b.x1 && a.y1 != b.y1 ? a.x1, a.y1, b.x1, b.y1 : a.x2, a.y2, b.x2, b.y2);
	double sideA = distance(a);
	double sideB = distance(b);
	double sideC = distance(c);
	return ((sideA * sideA + sideB * sideB - sideC * sideC) / (2 * sideA * sideB)) * (180.0/P);
}
Vector normalize(Vector a) {
	a.x2 -= a.x1;
	a.y2 -= a.y1;
	double v = sqrt(a.x2 * a.x2 + a.y2 * a.y2);
	a.x2 = a.x2 / v + a.x1;
	a.y2 = a.y2 / v + a.y1;
	return a;
}
Vector rotate90(Vector a) {
	if (a.x1 > a.x2) {
		a.x2 -= (a.x2 - a.x1) * 2;
	}
	else {
		a.x2 += (a.x2 - a.x1) * 2;
	}
	return a;
}
bool coleniar(Vector a, Vector b) {
	if (a.x1 > a.x2 && b.x1 < b.x2 ||
		a.x1 < a.x2 && b.x1 > b.x2) {
		double z = a.x1;
		a.x1 = a.x2;
		a.x2 = z;
		z = a.y1;
		a.y1 = a.y2;
		a.y2 = z;
	}
	a.x2 -= a.x1; a.x1 = 0;
	b.x2 -= b.x1; b.x1 = 0;
	a.y2 -= a.y1; a.y1 = 0;
	b.y2 -= b.y1; b.y1 = 0;
	a = normalize(a);
	b = normalize(b);
	if (round(a.x2 * 1000) / 1000 == round(b.x2 * 1000) / 1000 &&
		round(a.y2 * 1000) / 1000 == round(b.y2 * 1000) / 1000) {
		return true;
	}
	else {
		return false;
	}
}



struct Rectangle {
	struct Vector a;
	struct Vector b;
	Rectangle(Vector a, Vector b) {
		this->a.x1 = a.x1; this->a.y1 = a.y1;
		this->a.x2 = a.x2; this->a.y2 = a.y2;
		this->b.x1 = b.x1; this->b.y1 = b.y1;
		this->b.x2 = b.x2; this->b.y2 = b.y2;
	}
};
struct Triangle {
	Vector a;
	double b, c;
	Triangle(Vector a, double b, double c) {
		this->a.x1 = a.x1; this->a.y1 = a.y1;
		this->a.x2 = a.x2; this->a.y2 = a.y2;
		this->b = b;
		this->c = c;
	}
};
struct Circle {
	double a, b, r;
	Circle(double a, double b, double r) {
		this->a = a;
		this->b = b;
		this->r = r;
	}
};
struct Square {
	struct Vector a;
	Square(Vector a) {
		this->a.x1 = a.x1;
		this->a.y1 = a.y1;
		this->a.x2 = a.x2;
		this->a.y2 = a.y2;
	}
};

//void create() { // Не работает ;(
//	char type;
//	start:
//	std::cout << "What do you want to create? Rectangle (R), triangle (T), circle (C) or square (S)?\n";
//	std::cin >> type;
//	switch (tolower(type)) {
//	case 'r':
//		Vector a, b;
//		std::cout << "Please enter x & y of two points of the first diagonal:\n";
//		std::cin >> a.x1 >> a.y1;
//		std::cin >> a.x2 >> a.y2;
//		std::cout << "And now enter x & y of two points of the second diagonal:\n";
//		std::cin >> b.x1 >> b.y1;
//		std::cin >> b.x2 >> b.y2;
//		create(a, b);
//		break;
//	case 't':
//		Vector a2;
//		double b2, c;
//		std::cout << "Enter x & y of two points of a side:\n";
//		std::cin >> a2.x1 >> a2.y1;
//		std::cin >> a2.x2 >> a2.y2;
//		std::cout << "Enter x & y of a point:\n";
//		std::cin >> b2 >> c;
//		create(a2, b2, c);
//		break;
//	case 'c':
//		double a3, b3, r;
//		std::cout << "Enter x & y of a point:\n";
//		std::cin >> a3 >> b3;
//		std::cout << "Enter a radius:\n";
//		std::cin >> r;
//		create(a2, b3, r);
//		break;
//	case 's':
//		Vector a4;
//		std::cout << "Please enter coordinates (x & y) of two points of the first diagonal:\n";
//		std::cin >> a4.x1 >> a4.y1;
//		std::cin >> a4.x2 >> a4.y2;
//		create(a4);
//		break;
//	default:
//		std::cout << "Try again! ";
//		goto start;
//	}
//}
Rectangle create(Vector a, Vector b) {
	Rectangle rect(a, b);
	return rect;
}
Triangle create(Vector a, double b, double c) {
	Triangle tri(a, b, c);
	return tri;
}
Circle create(double a, double b, double r) {
	Circle cirk(a, b, r);
	return cirk;
}
Square create(Vector a) {
	Square sqr(a);
	return sqr;
}

bool isValid(Rectangle rect) {
	Vector a(rect.a.x1, rect.a.y1, rect.b.x1, rect.b.y1);
	Vector b(rect.a.x1, rect.a.y1, rect.b.x2, rect.b.y2);
	Vector c(rect.a.x2, rect.a.y2, rect.b.x1, rect.b.y1);
	Vector d(rect.a.x2, rect.a.y2, rect.b.x2, rect.b.y2);
	if (angle(a, b) && angle(c, d) && distance(a) && distance(b) && distance(c) && distance(d)) {
		return true;
	}
	else {
		return false;
	}
}
bool isValid(Triangle tri) {
	Vector a(tri.a.x1, tri.a.y1, tri.b, tri.c);
	if (coleniar(a, tri.a)) {
		return false;
	}
	else {
		return true;
	}
}
bool isValid(Circle cirk) {
	if (cirk.r) {
		return true;
	}
	else {
		return false;
	}
}
bool isValid(Square sqr) {
	if (distance(sqr.a)) {
		return true;
	}
	else {
		return false;
	}
}

double area(Rectangle rect) {
	if (isValid(rect)) {
		Vector a(rect.a.x1, rect.a.y1, rect.b.x1, rect.b.y1);
		Vector b(rect.a.x1, rect.a.y1, rect.b.x2, rect.b.y2);
		return distance(a) * distance(b);
	}
	else {
		return 2007;
	}
}
double area(Triangle tri) {
	if (isValid(tri)) {
		Vector a = tri.a;
		Vector b(a.x1, a.y1, tri.b, tri.c);
		Vector c(a.x2, a.y2, tri.b, tri.c);
		double angle1 = angle(tri.a, b);
		double angle2 = angle(tri.a, c);
		// Я ЗАБЫЛ О СУЩЕСТВОВАНИИ ФОРМУЛЫ ГЕРОНА
		while (abs(angle1 - 90) > 0.0000001 || abs(angle1 - 90) > 0.0000001) // Дихотомия
		{												// Дихотомия
			a.x1 = b.x1; a.y1 = b.y1;					// Дихотомия
			a.x2 = c.x1; a.y2 = c.y1;					// Дихотомия
			angle1 = angle(a, b);						// Дихотомия
			angle2 = angle(a, c);						// Дихотомия
			if (abs(angle1 - 90) < abs(angle2 - 90)) {	// Дихотомия
				b.x1 = (b.x1 + c.x1) / 2;	// Дихотомия
				b.y1 = (b.y1 + c.y1) / 2;	// Дихотомия
			}								// Дихотомия
			else {							// Дихотомия
				c.x1 = (b.x1 + c.x1) / 2;	// Дихотомия
				c.y1 = (b.y1 + c.y1) / 2;	// Дихотомия
			}								// Дихотомия
		}									// Дихотомия
		double h = abs(angle1 - 90) < abs(angle2 - 90) ? distance(b) : distance(c);
		return h * distance(tri.a) / 2;
	}
	else {
		return 1337;
	}
}
double area(Circle cirk) {
	if (isValid(cirk)) {
		return P * cirk.r * cirk.r;
	}
	else {
		return 228;
	}
}
double area(Square sqr) {
	if (isValid(sqr)) {
		double dist = distance(sqr.a);
		return dist * dist / 2;
	}
	else {
		return 777;
	}
}

double perimeter(Rectangle rect) {
	if (isValid(rect)) {
		Vector a(rect.a.x1, rect.a.y1, rect.b.x1, rect.b.y1);
		Vector b(rect.a.x1, rect.a.y1, rect.b.x2, rect.b.y2);
		return (distance(a) + distance(b)) * 2;
	}
	else {
		return 1984;
	}
}
double perimeter(Triangle tri) {
	if (isValid(tri)) {
		Vector b(tri.a.x1, tri.a.y1, tri.b, tri.c);
		Vector c(tri.a.x2, tri.a.y2, tri.b, tri.c);
		return distance(tri.a) + distance(b) + distance(c);
	}
	else {
		return 101;
	}
}
double perimeter(Circle cirk) {
	if (isValid(cirk)) {
		return 2 * P * cirk.r;
	}
	else {
		return 8.8005553535;
	}
}
double perimeter(Square sqr) {
	if (isValid(sqr)) {
		return distance(sqr.a) * 2 * sqrt(2);
	}
	else {
		return 69;
	}
}

int main() {
	// Number 1
	Vector a(-1, -1, 4, 4);
	Vector b(4, 4, -1, -1);
	Vector c(4, 4, 3, 7);
	Vector d(2, 2, -8, -8);

	std::cout << "Vector length a: " << distance(a) << '\n';
	std::cout << "Vector length c: " << distance(c) << "\n\n";

	std::cout << "Equality of a & b: " << equal(a, b) << '\n';
	std::cout << "Equality of a & c: " << equal(a, c) << "\n\n";

	std::cout << "Angle between a & b: " << angle(a, b) << '\n';
	std::cout << "Angle between a & c: " << angle(a, c) << "\n\n";

	Vector A4 = normalize(a);
	Vector C4 = normalize(c);
	std::cout << "Normalized a: " << A4.x1 << ", " << A4.y1 << ", " << A4.x2 << ", " << A4.y2 << ". Length is " << distance(A4) << '\n';
	std::cout << "Normalized c: " << C4.x1 << ", " << C4.y1 << ", " << C4.x2 << ", " << C4.y2 << ". Length is " << distance(C4) << "\n\n";

	Vector b90 = rotate90(b);
	Vector c90 = rotate90(c);
	std::cout << "Rotated b: " << b90.x1 << ", " << b90.y1 << ", " << b90.x2 << ", " << b90.y2 << '\n';
	std::cout << "Rotated c: " << c90.x1 << ", " << c90.y1 << ", " << c90.x2 << ", " << c90.y2 << "\n\n";

	std::cout << "a & d coleniar: " << coleniar(a, d) << '\n';
	std::cout << "c & d coleniar: " << coleniar(c, d) << "\n\n" << std::endl;

	// Number 2
	Vector A2(0, 0, 2, 2);
	Vector B2(2, 2, 7, 7);
	Vector C2(2, 7, 7, 2);
	Vector D2(0, 0, 0, 0);
	auto rect1 = create(A2, B2);
	auto rect2 = create(C2, B2);

	double a1 = 3, b1 = 3;
	double a2 = -1, b2 = 2;
	auto tri1 = create(A2, a1, b1);
	auto tri2 = create(A2, a2, b2);

	auto cirk1 = create(a1, b1, 0);
	auto cirk2 = create(a2, b2, 3);

	auto sqr1 = create(D2);
	auto sqr2 = create(A2);

	std::cout << "Is valid rectangles: " << isValid(rect1) << ", " << isValid(rect2) << '\n';
	std::cout << "Is valid triangles: " << isValid(tri1) << ", " << isValid(tri2) << '\n';
	std::cout << "Is valid circles: " << isValid(cirk1) << ", " << isValid(cirk2) << '\n';
	std::cout << "Is valid squares: " << isValid(sqr1) << ", " << isValid(sqr2) << "\n\n";

	std::cout << "Area of rectangles: " << area(rect1) << ", " << area(rect2) << '\n';
	std::cout << "Area of triangles: " << area(tri1) << ", " << area(tri2) << '\n';
	std::cout << "Area of circles: " << area(cirk1) << ", " << area(cirk2) << '\n';
	std::cout << "Area of squares: " << area(sqr1) << ", " << area(sqr2) << "\n\n";

	std::cout << "Perimeter of rectangles: " << perimeter(rect1) << ", " << perimeter(rect2) << '\n';
	std::cout << "Perimeter of triangles: " << perimeter(tri1) << ", " << perimeter(tri2) << '\n';
	std::cout << "Perimeter of circles: " << perimeter(cirk1) << ", " << perimeter(cirk2) << '\n';
	std::cout << "Perimeter of squares: " << perimeter(sqr1) << ", " << perimeter(sqr2) << "\n\n";

	// Number 3
	return 0;
}