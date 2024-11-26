#include <iostream>

double square(double a) {
	double x = a / 2;
	for (int i = 0; i < 1000000; i++) {
		x = 0.5 * (x + a / x);
	}
	return x;
}

double square2(double a, const int k) {
	double x = a / k;
	for (int i = 0; i < 1000000; i++) {
		double xxx = x;
		for (int j = 1; j < k - 1; j++) {
			xxx *= x;
		}
		x = 0.5 * (x + a / xxx);
	}
	return x;
}

bool check(char a[], char b[]) {
	bool check = true;
	for (int i = 0; ; i++) {
		if (a[i] == b[i]) {
			if (a[i] == '\0') {
				break;
			}
		}
		else {
			check = false;
			break;
		}
	}
	return check;
}

bool email(char a[]) {
	int cheker = 0;
	for (int i = 0; ; i++) {
		if (a[i] == '@' && i != 0) {
			if (cheker == 0) {
				cheker++;
			}
			else {
				break;
			}
		}
		else if (a[i] == '.') {
			if (cheker == 1 && a[i+1] != '\0' && a[i - 1] != '@') {
				cheker++;
			}
			else {
				cheker--;
				break;
			}
		}
		else if ((int(a[i]) > 48 && int(a[i]) <= 58) || (int(a[i]) > 65 && int(a[i]) <= 91) || (int(a[i]) > 97 && int(a[i]) <= 123) || (a[i] = '_')) {
			continue;
		}
		else {
			if (a[i] != '\0') {
				cheker--;
			}
			break;
		}
	}
	return (cheker == 2 ? true : false);
}

int main() {
	std::cout << "Square of 2 is " << square(2) << '\n';
	std::cout << "Square of 289 is " << square(289) << '\n';
	std::cout << "Square of 826281 is " << square(826281) << "\n\n";

	std::cout << "3 square of 3 is " << square2(3, 3) << '\n';
	std::cout << "2 square of 729 is " << square2(729, 2) << '\n';
	std::cout << "4 square of 10000 is " << square2(10000, 4) << "\n\n";

	std::cout << "Give me a string\n";
	char a[32];
	std::cin >> a;
	std::cout << "Give me another string\n";
	char b[32];
	std::cin >> b;
	std::cout << (check(a, b) != 0 ? "they equal" : "they not equal") << "\n\n";

	std::cout << "Give me your email\n";
	char emal[320];
	std::cin >> emal;
	std::cout << (email(emal) == 0 ? "next time give me your real one" : "thanks");
	return 0;
}