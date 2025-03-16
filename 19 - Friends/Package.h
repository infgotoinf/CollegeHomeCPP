#pragma once

#ifndef Package_H
#define Package_H

#include <iostream>
#include <list>

class Truck;

class Package
{
	std::string name;
	int weight;

	Package(std::string name, int weight)
		: name(name), weight(weight) {
	}

	/*Package(Package&& other)
	{
		std::swap(name, other.name);
		std::swap(weight, other.weight);
	}*/

	int GetWeight() const
	{
		return weight;
	}

public:
	~Package() = default;

	friend Truck;
};


class Truck
{
	std::string model, mark, colour;
	int year, cost, maxPayload;
	std::list<Package> packages;

public:
	Truck(std::string model = "Car",
		std::string mark = "Mark",
		std::string colour = "Colour",
		int year = 2007,
		int cost = 69,
		int maxPayload = 1337)
		: model(model)
		, mark(mark)
		, colour(colour)
		, year(year)
		, cost(cost)
		, maxPayload(maxPayload)
		, packages({})
	{ }
	~Truck() = default;

	/*void addPackage(std::string name, int weight)
	{
		packages.emplace_back(Package(name, weight));
	}*/

	// Я устал я ухожу, я сделал всё что смог
	/*bool isReady() const
	{
		int payload = 0;
		for (auto i : packages)
		{
			payload += i.GetWeight();
		}
		return (payload > maxPayload ? false : true);
	}*/

	/*void updPackages(const std::list<Package>& pack)
	{
		packages = pack;
	}*/

	friend std::ostream& operator<<(std::ostream& str, Truck const& car);
};


std::ostream& operator<<(std::ostream& str, Truck const& car)
{
	str << car.mark << ' ' << car.model << '\n';
	str << "Year: " << car.year << '\n';
	str << "Cost: " << car.cost << "$\n";
	str << "Colour: " << car.colour << "\n\n";
	return str;
}

#endif