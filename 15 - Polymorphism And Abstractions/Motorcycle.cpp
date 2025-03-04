#include "Motorcycle.h"
#include <iostream>

int main()
{
	Motorcycle motor("leg", "arm", "potata", 5, 666, 777);
	for (int i = 0; i < 10; i++) motor.move();
	std::cout << "wow da movin' fast " << motor.getDistance();
	return 0;
}