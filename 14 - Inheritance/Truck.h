#pragma once

#ifndef TRUCK_H
#define TRUCK_H

#include "list"
#include "Car.h"
#include "Package.h"

class Truck : public Car
{
private:
	std::list<Package> packages;
	int maxPayload;

public:
	Truck(std::string model, std::string mark, std::string colour,
		int year, int run, int cost,
		std::list<Package> packages,
		int maxPayload)
		: Car(model, mark, colour, year, run, cost)
		, packages(packages)
		, maxPayload(maxPayload)
	{}
	~Truck() = default;

	Truck(Truck const& other)
		: Car(other)
		, packages(other.packages)
		, maxPayload(other.maxPayload)
	{}

	Truck& operator=(Truck const& other)
	{
		model = other.model;
		mark = other.mark;
		colour = other.colour;
		year = other.year;
		run = other.run;
		cost = other.cost;
		packages = other.packages;
		maxPayload = other.maxPayload;
		return *this;
	}

	bool isReady() const
	{
		int payload;
		for (Package &i : packages)
		{
			payload += i.GetWeight();
		}
		return (payload > maxPayload ? false : true);
	}
};

#endif