#pragma once

#include <vector>

class HelperFunctions
{
public:
	template <typename T>
	static bool Contains(const std::vector<T>& vec, const T& value);
};

//Function implementation found here: https://stackoverflow.com/questions/6194797/what-is-a-c-container-with-a-contains-operation
template < typename T >
bool HelperFunctions::Contains(const std::vector< T >& vec, const T& value)
{
	return std::find(vec.begin(), vec.end(), value) != vec.end();
}