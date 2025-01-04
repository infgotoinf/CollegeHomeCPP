#include <iostream>

char* left(char* chr, int N) {
	char* a = new char[N];
	for (int i = 0; i < N; i++) {
		a[i] = chr[i];
	}
	return a;
}
char* right(char* chr, int N) {
	int i = 0;
	for (; chr[i] != '\0'; i++) {}
	i = i - N;
	char* a = new char[N];
	for (int i2 = 0; i2<N; i++, i2++) {
		a[i2] = chr[i];
	}
	return a;
}

int main() {
	char str[] = "nitroglycerin";
	char* str2 = left(str, 5);
	char* str3 = right(str, 8);
	std::cout << str2 << '\n';
	std::cout << str3 << '\n';

	delete[] str2;
	delete[] str3;


	short int shorts = 65280;
	char* chorts = *shorts;

	delete chorts;

	return 0;
}