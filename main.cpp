#include "Miner.h"
#include "Elsa.h"
#include <iostream>

#include <windows.h>

int main()
{
	Miner miner(0);
	Elsa elsa(3);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true)
	{
		::_sleep(1000);
		std::cout << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
		miner.Update();
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		elsa.Update();
	}
	
}