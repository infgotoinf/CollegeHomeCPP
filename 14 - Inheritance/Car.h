#pragma once

#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
protected:
	std::string model, mark, colour;
	int year, run, cost;

public:
	Car(std::string model, std::string mark, std::string colour,
		int year, int run, int cost)
		: model(model), mark(mark), colour(colour)
		, year(year), run(run), cost(cost)
	{}
	~Car() = default;

	Car(Car const& other)
		: model(other.model),
		mark(other.mark),
		colour(other.colour),
		year(other.year),
		run(other.run),
		cost(other.cost)
	{}

	Car& operator=(Car const& other)
	{
		model = other.model;
		mark = other.mark;
		colour = other.colour;
		year = other.year;
		run = other.run;
		cost = other.cost;
		return *this;
	}

	std::string GetMark() const
	{
		return mark;
	}
	std::string GetModel() const
	{
		return model;
	}
	std::string GetColour() const
	{
		return colour;
	}
	int GetCost() const
	{
		return cost;
	}
	int GetYear() const
	{
		return year;
	}

	void FakeMark(std::string const& mark)
	{
		this->mark = mark;
	}
	void FakeModel(std::string const& model)
	{
		this->model = model;
	}
	void FakeColour(std::string const& colour)
	{
		this->colour = colour;
	}
	void FakeCost(int const& cost)
	{
		this->cost = cost;
	}
	void FakeYear(int const& year)
	{
		this->year = year;
	}
};

#endif