#include "MyMath.h"
#include <random>

int MyMath::GetRandInteger(int from, int to)
{
	static std::default_random_engine dre;
	std::uniform_int_distribution<> ui(from, to);

	return ui(dre);
}
