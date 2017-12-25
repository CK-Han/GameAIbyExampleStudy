#include "MinerState.h"
#include "Miner.h"

#include <iostream>

//////////////////////////////////////////////////////////////////////////
//EnterMineAndDigForNugget
EnterMineAndDigForNugget* 
	EnterMineAndDigForNugget::GetInstance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* miner)
{
	std::cout << miner->GetId() << " : " << "walkin' to the gold mine\n";
	miner->ChangeLocation(Location_Type::GOLDMINE);
}

void EnterMineAndDigForNugget::Execute(Miner* miner)
{
	
}

void EnterMineAndDigForNugget::Exit(Miner* miner)
{

}

//EnterMineAndDigForNugget
//////////////////////////////////////////////////////////////////////////