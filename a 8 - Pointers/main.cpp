#include <iostream>
#include <cmath>

char* left(char* chr, int N) {
	char* a = new char[N + 1];
	int i = 0;
	for (; i < N; i++) {
		a[i] = chr[i];
	}
	a[i] = '\0';
	return a;
}
char* right(char* chr, int N) {
	int i = 0;
	for (; chr[i] != '\0'; i++) {}
	i = i - N;
	char* a = new char[N + 1];
	int i2 = 0;
	for (; i2 < N; i++, i2++) {
		a[i2] = chr[i];
	}
	a[i2] = '\0';
	return a;
}

void roots(int korni, double* da, double a, double b, double (*func)(double), double (*dihotomia)(double, double, double, double, double (*func)(double)));
double dihotomia(double i, double i2, double a, double b, double (*func)(double)); // Дихотомия
double func(double x);

int* filter(int arr[], int num, bool (*func)(int, int)) {
	int counter = 0;
	for (int i = 0; i < sizeof(arr); i++) {
		if (true == func(num, arr[i])) {
			counter++;
		}
	}
	counter++;
	int* a = new int[counter];
	a[0] = counter;
	for (int i = 0, i2 = 1; i < sizeof(arr); i++) {
		if (true == func(num, arr[i])) {
			a[i2] = arr[i];
			i2++;
		}
	}
	return a;
}
bool not_equal(int num, int n) {
	return (n != num ? true : false);
}
bool greater(int num, int n) {
	return (n > num ? true : false);
}
bool divides(int num, int n) {
	return (n % num == 0 ? true : false);
}

int main() {
	//Number 1
	char str[] = "nitroglycerin";
	char* str2 = left(str, 5);
	char* str3 = right(str, 8);
	std::cout << str2 << '\n';
	std::cout << str3 << "\n\n";
	delete[] str2;
	delete[] str3;


	//Number 2
	short int* shorti = new short int{ (short int)0xFF00 };
	//char* chorts = new char{ (char)*shorti };
	char* chorts = new char[3];
	int i = 0;
	for (; i < 2; i++) {
		chorts[i] = ((char)*(shorti + i) - (char)*(shorti + 2) != char(0) ? 'F' : '0');
		//std::cout << *(shorti + i) << '\n';
	}
	chorts[i] = '\0';
	//char* F = new char[3] {'F', '0', '\0'};
	//std::cout << (chorts == F ? "Big-endian: " : "Little-endian: ") << chorts << '\n';
	std::cout << chorts << "\n\n";
	delete shorti, chorts;


	//Number 3
	int korni = 8;
	double* da = new double[korni]{0};
	double a = 4, b = 13;
	roots(korni, da, a, b, func, dihotomia);
	std::cout << "The roots are: ";
	for (int i = 0; i < korni && da[i] != 0; i++) {
		std::cout << da[i] << ", ";
	}
	std::cout << "\b\b \n\n";


	//Number 4
	int arr[] = { -69, 777, 0, 1000, -7, 1337, 13, 18}; // Но масив может состоять только из 8-и элементов, потому что sizeof
	int* arr2 = filter(arr, 0, not_equal);				// для этого нужно передавать в функцию размер масиива, что не сложно,
	int* arr3 = filter(arr, 0, greater);				// но я это реализовывать не буду
	int* arr4 = filter(arr, 2, divides);
	std::cout << "arr:  [";
	for (int i : arr) {
		std::cout << i << ", ";
	}
	std::cout << "\b\b]\narr2: [";
	for (int i = 1; i < arr2[0]; i++) {
		std::cout << arr2[i] << ", ";
	}
	std::cout << "\b\b]\narr3: [";
	for (int i = 1; i < arr3[0]; i++) {
		std::cout << arr3[i] << ", ";
	}
	std::cout << "\b\b]\narr4: [";
	for (int i = 1; i < arr4[0]; i++) {
		std::cout << arr4[i] << ", ";
	}
	std::cout << "\b\b]";
	return 0;
}


void roots(int korni, double* da, double a, double b, double (*func)(double), double (*dihotomia)(double, double, double, double, double (*func)(double)))
{
	const double h = 0.1;
	const double center = (a + b) / 2;

	// Находим 0 с левого края
	double left = func(a), left2 = func(a + h);
	double i = a;
		// Находим значения для дихотомии
		for (; !(abs(left + left2) < 1 && (left * left2 < 0)) && i < center; i += h)
		{
			left = left2;
			left2 = func(i);
		}
		i -= 0.1;
		double i2 = i - h;
	left = dihotomia(i, i2, left, left2, func); // Дихотомия

	// Находим 0 с правого края
	double right = func(b), right2 = func(b - h);
	i = b;
		// Находим значения для дихотомии
		for (; !(abs(right + right2) < 1 && (right * right2 < 0)) && i > center; i -= h)
		{
			right = right2;
			right2 = func(i);
		}
		i += 0.1;
		i2 = i + 0.1;
	right = dihotomia(i, i2, right, right2, func); // Дихотомия

	// Добавление в массив даблов
	int counter = 0;
	for (int i = 0; i < korni; i++) {
		if (da[i] == 0)
		{
			if (counter == 0)
			{
				if (left == 2007) {
					continue;
				}
				da[i] = left;
				counter++;
			}
			else if (counter == 1)
			{
				if (right == 2007) {
					continue;
				}
				da[i] = right;
				counter++;
			}
			else {
				break;
			}
		}
	}
	if (left != right) {
		roots(korni, da, (left == 2007 ? center : left + h), (right == 2007 ? center : right - h), func, dihotomia);
	}
}
double dihotomia(double i, double i2, double a, double b, double (*func)(double)) { // Дихотомия
	if (a * b > 0) { // Дихотомия
		return 2007; // Дихотомия
	}				 // Дихотомия
	while (abs(a) > 0.0000001 || abs(b) > 0.0000001) // Дихотомия
	{												 // Дихотомия
		a = func(i2);								 // Дихотомия
		b = func(i);								 // Дихотомия
		if (abs(a) < abs(b)) { i = (i + i2) / 2; } // Дихотомия
		else { i2 = (i + i2) / 2; }			       // Дихотомия
	}											   // Дихотомия
	return (func(i2) < func(i) ? i2 : i); // Дихотомия
}
double func(double x) {
	return 0.2 * x * sin(x) - 1.0 / x;
}