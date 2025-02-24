#include "Truck.h"

int main()
{
	Package pack1("hleb", 50);
	Package pack2 = pack1;
	Package pack3 = pack2;
	Package pack4 = pack3;

	std::list<Package> packages = {pack1, pack2, pack3, pack4};

	Truck truck("Belaz", "Sigma", "Watermelon", 1337, 100000, 69000000, packages, 249);

	return 0;
}