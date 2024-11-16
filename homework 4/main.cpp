#include <iostream>
#include <cmath>

double function(double x) {
	return -0.5 * x * x + 6 * x - 10;
}

double scarysymbol(double x) {
	return (x - 1) / (x + 1);
}

int main() {
	// Number 1
	std::cout << "Give a positive number that is not zero: ";
	int n;
	std::cin >> n;
	double q = 2;
	int d = 1;
	int c = 1;
	for (int i = 1; i < n; i++) {
		c += pow(q, i);
	}
	std::cout << c << "\n\n";

	// Number 2
	std::cout << "Give a number in range from 0 to 1: ";
	std::cin >> q;
	double c2 = 1;
	for (int i = 1; i < 100; i++) {
		c2 += pow(q, i);
	}
	std::cout << "Does " << c2 << " close to " << d/(1-q) << "?\n\n";

	// Number 3
	int const a = 2, b = 10;
	double const h = 0.001;
	double f = 0;
	for (double i = a; i <= b; i += h) {
		double x = a + i * h;
		f += (function(x + h) + function(x)) / 2;
	}
	std::cout << "Square of the integral of the function on [" << a << ',' << b << "] is " << f << "\n\n";

	// Number 4
	std::cout << "Give a number: ";
	double x;
	std::cin >> x;
	double ln = 0;
	for (int n = 0; n < 1000; n++) {
		ln += 2 * (pow(scarysymbol(x), 2 * n + 1)) / (2 * n + 1);
	}
	std::cout << ln;
	return 0;
}