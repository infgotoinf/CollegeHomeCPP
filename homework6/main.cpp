#include <iostream>

int main() {
	//Number 1
	const int masslen = 20;
	int massive[20] = { 3, 4, 8, -13, 0, 9, 45, 7, -4, -1, 9, 4, 565, -78, 8, 3, 9, -777, -85, 23 };
	double arifmet = 0, sred = 0, med = 0.1, med2 = 0.1;
	int chmod = 0;
	int max = massive[0], min = massive[0], counter = 0;
	int evennes = (masslen % 2 == 0 ? 1 : 0);

	for (int i = 0; i < masslen; i++) {
		arifmet += massive[i];

		(max < massive[i] ? max = massive[i] : max = max);
		(min > massive[i] ? min = massive[i] : min = min);

		int counterlow = 0, counterhigh = 0;
		for (int j = 0; j < masslen; j++) {
			if (i == j) {
				continue;
			}
			if (massive[i] < massive[j]) {
				counterlow++;
			}
			else if (massive[i] > massive[j]) {
				counterhigh++;
			}
		}
		if (med == 0.1) {
			med = (counterlow - counterhigh - evennes == 0 || counterlow - counterhigh + evennes == 0 || counterlow - counterhigh == 0 ? massive[i] : med);
		}
		else {
			med2 = (counterlow - counterhigh - evennes == 0 || counterlow - counterhigh + evennes == 0 || counterlow - counterhigh == 0 ? massive[i] : med2);
		}

		int counternew = 0;
		for (int j = 0; j < masslen; j++) {
			if (massive[i] == massive[j]) {
				counternew++;
			}
		}
		if (counternew > counter) {
			chmod = massive[i];
			counter = counternew;
		}
	}
	arifmet /= masslen;
	std::cout << "Arefmetic mean is " << arifmet <<'\n';
	sred = (min + max) / 2;
	std::cout << "Average is " << sred << '\n';
	std::cout << "Median is " << med;
	if (med2 != 0.1) {
		std::cout << ", " << med2;
	}
	std::cout << '\n';
	std::cout << "Fashion is " << chmod << " repeats " << counter << " times\n\n";

	//Number 2
	std::cout << "Choose < or >\n";
	char ch;
	std::cin >> ch;
	if (ch == '<') {
		for (int i = 0; i < masslen - 1; i++) {
			for (int j = 0; j < masslen - 1; j++) {
				int m = massive[j];
				int m1 = massive[j + 1];
				massive[j] = (m > m1 ? m1 : m);
				massive[j + 1] = (m < m1 ? m1 : m);
			}
		}
	}
	else if (ch == '>') {
		for (int i = 0; i < masslen - 1; i++) {
			for (int j = 0; j < masslen - 1; j++) {
				int m = massive[j];
				int m1 = massive[j + 1];
				massive[j] = (m < m1 ? m1 : m);
				massive[j + 1] = (m > m1 ? m1 : m);
			}
		}
	}
	else {
		std::cout << ">:[\n";
	}
	for (int i = 0; i < masslen; i++) {
		std::cout << massive[i] << " ";
	}
	std::cout << "\n\n";

	//Number 3
	char text[512] = "The other three old people nodded their heads slowly up and down, and said\n\t\'Absolutely true, Just as true as can be\'. And Grandpa Joe said\n- You mean to say I\'ve never told you about Mr Willy Wonka and his factory?\n\t\t- Never - answered little Charlie.\n\t- Good heavens above! I don\'t know what\'s the matter with me!";
	int sentence = 0;
	for (int i = 1; i < sizeof(text); i++) {
		if (text[i] == '.' || text[i] == '!' || text[i] == '?' && text[i-1] != '.') {
			sentence++;
		}
	}
	std::cout << text << '\n';
	std::cout << "Sentence count is " << sentence << "\n\n\n";

	//Number 4
	int mass[5][5] = {{82, -90, 0, 3, -5}, {0, 2, -34, 17, 5}, {90, -14, 9, 3, -3}, {0, 12, 59, -43, -32}, {-14, -15, 12, 49, 66}};
	int diagsumm = 0;
	int diagsumm2 = 0;
	for (int i = 0; i < 5; i++) {
		diagsumm += mass[i][i];
		diagsumm2 += mass[4 - i][i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << mass[i][j] << '\t';
		}
		std::cout << "\n\n";
	}
	std::cout << "Diagonal sum is " << diagsumm << " and the other one is " << diagsumm2 << "\n\n";

	int mass2[6][4] = { {82, -90, 0, 3}, {0, 2, -34, 17}, {90, -14, 9, 3}, {0, 12, 59, -43}, {-14, -15, 12, 49}, {7, -90, 16, 3} };
	int che = 0;
	int nech = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i + j) % 2 == 0) {
				che += mass2[i][j];
			}
			else {
				nech += mass2[i][j];
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << mass2[i][j] << '\t';
		}
		std::cout << "\n\n";
	}
	setlocale(0, "");
	std::cout << "Sum of evens - sum of odds is " << che - nech << " почти как 69, только наоборот " << char(2);
	return 0;
}