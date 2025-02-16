#include "Car.h"
#include <iostream>

int main()
{
	Car car("Semerka ", "Lada ", "Vishnevaya ", 2007, 10000, 100000);

	std::cout << "Would you buy " << car.GetColour() << car.GetModel() << "for " << car.GetCost() << "?\n";
	std::cout << "\"No.\"\n";
	std::cout << ":<\n\n";

	car.FakeColour("Green ");
	car.FakeModel("Porshe ");
	car.FakeMark("Firari ");
	car.FakeYear(2025);
	car.FakeCost(INT_MAX);

	std::cout << "Would you buy " << car.GetMark() << car.GetModel() << car.GetColour() << "for " << car.GetCost() << "?\n";
	std::cout << "\"Yes.\"\n";
	std::cout << "B)";

	Car car2 = car;
	car = car2;
	return 0;
}