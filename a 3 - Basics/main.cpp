#include <iostream>

int main() {
	// Number 1
	int a;
	int b;
	std::cout << "Give me a divisible: ";
	std::cin >> a;
	std::cout << "Give me a divisor: ";
	std::cin >> b;
	if (a % b == 0) {
		std::cout << "It's divided without a remainder :>";
	}
	else {
		std::cout << "It's divided with a remainder :<";
	}
	std::cout << "\n\n";

	// Number 2
	system("chcp 1251");
	setlocale(0, "");
	int c;
	std::cout << "How old are you?\n";
	std::cin >> c;
	switch (!(c<=120 && c>=6) ?0 :(c>=80 ?1 :(c>=65 ?2 :(c>=35 ?3 :(c>=21 ?4 :(c>=18 ?5 :(c>=16 ?6 :(c>=14 ?7 :8)))))))) {
	case 0:
		std::cout << "�� �����\n";
		break;
	case 1:
		std::cout << "�� ��������������� �� ��������\n";
	case 2:
		std::cout << "�� ���������\n";
	case 3:
		std::cout << "�� ������ ���� ����������� (���)\n";
	case 4:
		std::cout << "�� ������ ���� ��������� �������\n";
	case 5:
		std::cout << "�� ����������������\n";
	case 6:
		std::cout << "�� ������ �������� �����������\n";
	case 7:
		std::cout << "�� ��������� ���������\n";
	case 8:
		std::cout << "�� �������� �����������\n";
	}
	std::cout << '\n';

	// Number 3
	std::cout << "Give a X coordinate: ";
	double X;
	std::cin >> X;
	std::cout << "Give an Y coordinate: ";
	double Y;
	std::cin >> Y;
	if (X >= 0 && Y >= 0) {
		std::cout << "I ";
	}
	if (X <= 0 && Y >= 0) {
		std::cout << "II ";
	}
	if (X <= 0 && Y <= 0) {
		std::cout << "III ";
	}
	if (X >= 0 && Y <= 0) {
		std::cout << "IV";
	}
	std::cout << "\n\n";

	// Number 4
	std::cout << "Give me a character in hexadecimal number system: ";
	char sixteen;
	std::cin >> sixteen;
	switch (int(sixteen)<= 57 && int(sixteen) >= 48 ? 0 : (int(sixteen) <= 69 && int(sixteen) >= 65 ? 1 : 2)) {
	case 0:
		std::cout << sixteen;
		break;
	case 1:
		std::cout << int(sixteen) - 54;
		break;
	default:
		std::cout << "SuPeR.error/228";
	} // ������ ����� � ����� ��� �� ����� ���� ������� � ���� �� ���� ��������, �� �����
	// � ������� � ����� ����� ����� ������, ��� ���� ������� �� ������ ����
	return 0;
}