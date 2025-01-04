#include <iostream>

int N[10000 - 2];

bool check(int a) {
	return N[a];
}


int Lego(int n, int k) {
	int kn = n - k;
	for (int i = n-1; i >= 2; i--) {
		n *= i;
	}
	for (int i = k-1; i >= 2; i--) {
		k *= i;
	}
	for (int i = kn-1; i >= 2; i--) {
		kn *= i;
	}
	return n / (k * kn);
}


int main() {
	for (int i = 0; i < 1000 - 2; i++) {
		N[i] = 1;
	}
	for (int i = 4; i < 1000 - 2; i += 2) {
		N[i] = 0;
	}
	for (int i = 6; i < 1000 - 2; i += 3) {
		N[i] = 0;
	}
	for (int i = 10; i < 1000 - 2; i += 5) {
		N[i] = 0;
	}
	for (int i = 14; i < 1000 - 2; i += 7) {
		N[i] = 0;
	}
	int a;
	std::cout << "Give a number and i'll check if it's prime: ";
	std::cin >> a;
	std::cout << check(a) << "\n\n";


	std::cout << "How many lego bricks do you have? ";
	int n;
	std::cin >> n;
	std::cout << "How many lego bricks do you want? ";
	int k;
	std::cin >> k;
	std::cout << "You have "<< Lego(n, k) << " way to take them!";
	return 0;
}