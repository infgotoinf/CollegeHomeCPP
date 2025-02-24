#include "Truck.h"
#include <iostream>

int main()
{
	Package pack1("hleb", 50);
	Package pack2 = pack1;
	Package pack3 = pack2;
	Package pack4 = pack3;

	std::list<Package> packages = {pack1, pack2, pack3, pack4};

	Truck truck("Belaz", "Sigma", "Watermelon", 1337, 100000, 69000000, packages, 249);

	std::cout << truck.GetMark() << " can go: " << truck.isReady() << '\n';

	Truck truck2 = truck;
	truck2.FakeMark("Not sigma");
	packages.push_back(pack1);
	truck2.updPackages(packages);

	std::cout << truck2.GetMark() << " can go: " << truck2.isReady() << '\n';

	truck = truck2;
	return 0;
}