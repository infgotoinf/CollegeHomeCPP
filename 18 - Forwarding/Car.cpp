#include "Car.h"

int main()
{
	Car car;
	std::cout << car;

	CarBuilder carb;
	carb.setModel("UwU").setMark("OwO").setColour("QwQ");
	car = carb.create();
	std::cout << car;

	car = Car("Avtobus", "Kotletki");
	std::cout << car;
	return 0;
}