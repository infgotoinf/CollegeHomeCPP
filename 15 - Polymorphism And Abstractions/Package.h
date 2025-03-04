#pragma once

#ifndef Package_H
#define Package_H

#include <string>

class Package
{
private:
	std::string name;
	int weight;

public:
	Package(std::string name, int weight)
		: name(name), weight(weight) {
	}
	~Package() = default;

	Package(Package const& other)
		: name(other.name), weight(other.weight) {
	}

	int GetWeight() const
	{
		return weight;
	}
};

#endif