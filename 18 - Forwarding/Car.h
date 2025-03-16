#pragma once

#ifndef CAR_H
#define CAR_H

#include <iostream>

class CarBuilder;

class Car
{
	std::string model, mark, colour;
	int year, cost;

public:
	Car(std::string model = "Car",
		std::string mark = "Mark",
		std::string colour = "Colour",
		int year = 2007,
		int cost = 69)
		: model(model)
		, mark(mark)
		, colour(colour)
		, year(year)
		, cost(cost)
	{ }
	~Car() = default;

	Car(CarBuilder& builder);

	Car(Car const& other)
	{
		model	= other.model;
		mark	= other.mark;
		colour	= other.colour;
		year	= other.year;
		cost	= other.cost;
	}

	Car& operator=(Car const& other)
	{
		model	= other.model;
		mark	= other.mark;
		colour	= other.colour;
		year	= other.year;
		cost	= other.cost;
		return *this;
	}

	Car(Car&& other)
	{
		std::swap(model,	other.model	);
		std::swap(mark,		other.mark	);
		std::swap(colour,	other.colour);
		std::swap(year,		other.year	);
		std::swap(cost,		other.cost	);
	}

	Car& operator=(Car&& other)
	{
		std::swap(model,	other.model	);
		std::swap(mark,		other.mark	);
		std::swap(colour,	other.colour);
		std::swap(year,		other.year	);
		std::swap(cost,		other.cost	);
		return *this;
	}

	friend CarBuilder;
	friend std::ostream& operator<<(std::ostream& str, Car const& car);
};


std::ostream& operator<<(std::ostream& str, Car const& car)
{
	str << car.mark << ' ' << car.model << '\n';
	str << "Year: "		<< car.year	<< '\n';
	str << "Cost: "		<< car.cost	<< "$\n";
	str << "Colour: "	<< car.colour << "\n\n";
	return str;
}


class CarBuilder
{
	Car car;

public:
	CarBuilder() : car()
	{ }
	CarBuilder(CarBuilder const&) = delete;
	~CarBuilder() = default;

	CarBuilder& setMark(std::string mark)
	{
		car.mark = mark;
		return *this;
	}

	CarBuilder& setModel(std::string model)
	{
		car.model = model;
		return *this;
	}

	CarBuilder& setYear(int year)
	{
		car.year = year;
		return *this;
	}

	CarBuilder& setCost(int cost)
	{
		car.cost = cost;
		return *this;
	}

	CarBuilder& setColour(std::string colour)
	{
		car.colour = colour;
		return *this;
	}

	Car create()
	{
		return car;
	}
};

Car::Car(CarBuilder& builder)
{
	Car car = builder.create();

	model	= car.model;
	mark	= car.mark;
	colour	= car.colour;
	year	= car.year;
	cost	= car.cost;
}
#endif