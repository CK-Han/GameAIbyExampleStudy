#include "Miner.h"
#include <iostream>

int main()
{
	Miner miner(0);

	while (true)
	{
		::_sleep(1000);
		std::cout << std::endl;
		miner.Update();
	}
}