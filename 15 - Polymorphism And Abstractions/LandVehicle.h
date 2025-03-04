#pragma once

#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include "Vehicle.h"

class LandVehicle : public Vehicle
{
protected:
	int currentVelosity, distance;
public:
	LandVehicle(int currentVelosity, int distance)
		: currentVelosity(currentVelosity), distance(distance)
	{
	}
	virtual ~LandVehicle() = default;

	void move() override
	{
		distance += currentVelosity;
	}

	int getDistance()
	{
		return distance;
	}
};

#endif