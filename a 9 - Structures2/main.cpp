#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <ctime>

int main() {
	//Number 1
	std::vector<int> vectorni = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };
	std::list<int> listovi = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };
	std::set<int> setovi = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };
	std::unordered_set<int> unordered_setovi = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };

	clock_t ticks1 = clock();
	for (int i = 1; i <= 1000000;) {
			for (int i2 = 0; i2 < 10; i++, i2++) {
				&vectorni[i2];
			}
		}
	ticks1 = clock() - ticks1;
	double time1 = ticks1 / 1000.0;

	clock_t ticks2 = clock();
	const int halfsize = listovi.size() / 2;
	const int nothalfsize = listovi.size();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 0; i2 < 10; i++, i2++) {
			if (halfsize < i2) {
				int i3 = 0;
				auto j = listovi.begin();
				for (; i3 != i2; i3++, j++);
				j;
			}
			else {
				int i3 = nothalfsize;
				auto j = listovi.end();
				for (; i3 != i2; i3--, j--);
				j;
			}
		}
	}
	ticks2 = clock() - ticks2;
	double time2 = ticks2 / 1000.0;

	clock_t ticks3 = clock();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 0; i2 < 10; i++, i2++) {
			if (halfsize < i2) {
				int i3 = 0;
				auto j = setovi.begin();
				for (; i3 != i2; i3++, j++);
				j;
			}
			else {
				int i3 = nothalfsize;
				auto j = setovi.end();
				for (; i3 != i2; i3--, j--);
				j;
			}
		}
	}
	ticks3 = clock() - ticks3;
	double time3 = ticks3 / 1000.0;

	clock_t ticks4 = clock();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 0; i2 < 10; i++, i2++) {
			if (halfsize < i2) {
				int i3 = 0;
				auto j = unordered_setovi.begin();
				for (; i3 != i2; i3++, j++);
				j;
			}
			else {
				int i3 = nothalfsize;
				auto j = unordered_setovi.end();
				for (; i3 != i2; i3--, j--);
				j;
			}
		}
	}
	ticks4 = clock() - ticks4;
	double time4 = ticks4 / 1000.0;

	std::cout << "Time of vector: " << time1 << '\n';			// Time: ~0.004
	std::cout << "Time of list: " << time2 << '\n';				// Time: ~0.989
	std::cout << "Time of set: " << time3 << '\n';				// Time: ~1.126
	std::cout << "Time of unordered set: " << time4 << "\n\n";	// Time: ~1.075

	//Number 2
	ticks1 = clock();
	bool switcher = true;
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 1; i2 <= 10; i++, i2++) {
			if (switcher == true) {
				vectorni.pop_back();
				vectorni.insert(vectorni.begin(), i2);
				switcher = false;
			}
			else {
				vectorni.erase(vectorni.begin());
				vectorni.push_back(i2);
				switcher = true;
			}
		}
	}
	ticks1 = clock() - ticks1;
	time1 = ticks1 / 1000.0;

	ticks2 = clock();
	switcher = true;
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 1; i2 <= 10; i++, i2++) {
			if (switcher == true) {
				listovi.pop_back();
				listovi.push_front(i2);
				switcher = false;
			}
			else {
				listovi.pop_front();
				listovi.push_back(i2);
				switcher = true;
			}
		}
	}
	ticks2 = clock() - ticks2;
	time2 = ticks2 / 1000.0;

	ticks3 = clock();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 1; i2 <= 10; i++, i2++) {
			setovi.erase(i2);
			setovi.insert(i2);
		}
	}
	ticks3 = clock() - ticks3;
	time3 = ticks3 / 1000.0;

	ticks4 = clock();
	for (int i = 0; i <= 1000000;) {
		for (int i2 = 1; i2 <= 10; i++, i2++) {
			unordered_setovi.erase(i2);
			unordered_setovi.insert(i2);
		}
	}
	ticks4 = clock() - ticks4;
	time4 = ticks4 / 1000.0;
	
	std::cout << "Time of vector push/insert back/front: " << time1 << '\n';	// Time: ~0.464
	std::cout << "Time of list push/insert back/front: " << time2 << '\n';		// Time: ~0.471
	std::cout << "Time of set push/insert key: " << time3 << '\n';				// Time: ~1.638
	std::cout << "Time of unordered set push/insert key: " << time4 << "\n\n";	// Time: ~0.983


	// Number 2.5
	vectorni = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };
	listovi = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };
	setovi = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };
	unordered_setovi = { 5, 1, 10, 9, 4, 3, 8, 2, 7, 6 };

	ticks1 = clock();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 0; i2 < 10; i++, i2++) {
			std::find(vectorni.begin(), vectorni.end(), i2);
		}
	}
	ticks1 = clock() - ticks1;
	time1 = ticks1 / 1000.0;

	ticks2 = clock();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 0; i2 < 10; i++, i2++) {
			std::find(listovi.begin(), listovi.end(), i2);
		}
	}
	ticks2 = clock() - ticks2;
	time2 = ticks2 / 1000.0;

	ticks3 = clock();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 0; i2 < 10; i++, i2++) {
			setovi.count(i);
		}
	}
	ticks3 = clock() - ticks3;
	time3 = ticks3 / 1000.0;

	ticks4 = clock();
	for (int i = 1; i <= 1000000;) {
		for (int i2 = 0; i2 < 10; i++, i2++) {
			unordered_setovi.count(i);
		}
	}
	ticks4 = clock() - ticks4;
	time4 = ticks4 / 1000.0;

	std::cout << "Time of vector value search: " << time1 << '\n';			// Time: ~0.356
	std::cout << "Time of list value search: " << time2 << '\n';			// Time: ~0.484
	std::cout << "Time of set value search: " << time3 << '\n';				// Time: ~0.114
	std::cout << "Time of unordered set value search: " << time4 << "\n\n";	// Time: ~0.045
	return 0;
}