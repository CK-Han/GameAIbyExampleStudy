#include "Miner.h"
#include "Elsa.h"
#include "MessageDispatcher.h"
#include <iostream>
#include <windows.h>



int main()
{
	Miner miner(Entity_Id::BOB);
	Elsa elsa(Entity_Id::ELSA);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true)
	{
		::_sleep(1000);
		std::cout << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
		miner.Update();
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		elsa.Update();
		MessageDispatcher::GetInstance()->DispatchDelayedMessages();
	}
	
}