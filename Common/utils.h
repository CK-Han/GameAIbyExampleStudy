#pragma once

#include <cmath>
#include <limits>

//a few useful constants
const int     MaxInt = (std::numeric_limits<int>::max)();
const double  MaxDouble = (std::numeric_limits<double>::max)();
const double  MinDouble = (std::numeric_limits<double>::min)();
const float   MaxFloat = (std::numeric_limits<float>::max)();
const float   MinFloat = (std::numeric_limits<float>::min)();

inline bool isEqual(double a, double b)
{
	if (fabs(a - b) < 1E-12)
		return true;
	return false;
}


//returns the maximum of two values
template <class T>
inline T MaxOf(const T& a, const T& b)
{
	if (a>b) return a; return b;
}

