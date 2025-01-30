#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T, typename V>
T print_vector_idx(std::vector<T> vec, V idx)
{
	if (idx != (int)idx)
	{
		throw 1;
	}
	else if (idx > vec.size() || idx < 0)
	{
		throw 2;
	}
	return vec[idx];
}

struct exept
{
	std::string msg;
	exept(int error_code = 0) {
		switch (error_code) {
		case 0:
			msg = "OK";
			break;
		case 1:
			msg = "Invalid argument!";
			break;
		case 2:
			msg = "Out of range!";
			break;
		default:
			msg = "Unknown error!";
		}
	}
};

int main() {
	try
	{
		std::vector<int> vec1 = { 34, 65, 43, 23 };
		exept exe(print_vector_idx(vec1, 1));
	}
	catch (...)
	{
		exept()
	}
	return 0;
}