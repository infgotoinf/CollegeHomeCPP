#pragma once

#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>
#include "LandVehicle.h"

class Motorcycle : public LandVehicle
{
private:
	std::string legs, arms, headlights;
	int old;

public:
	Motorcycle(std::string legs, std::string arms, std::string headlights,
		int old, int currentVelosity, int distance)
		: legs(legs), arms(arms), headlights(headlights)
		, old(old), LandVehicle(currentVelosity, distance)
	{
	}

	~Motorcycle() = default;

	Motorcycle(Motorcycle const& other)
		: legs(other.legs),
		arms(other.arms),
		headlights(other.headlights),
		old(other.old),
		LandVehicle(currentVelosity, distance)
	{
	}

	Motorcycle& operator=(Motorcycle const& other)
	{
		legs = other.legs;
		arms = other.arms;
		headlights = other.headlights;
		old = other.old;
		currentVelosity = other.currentVelosity;
		distance = other.distance;
		return *this;
	}
};

#endif