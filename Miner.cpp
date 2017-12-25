#include "Miner.h"




Miner::Miner(int newId)
	: BaseGameEntity(newId)
	, currentState()
	, location()
	, goldsInPocket()
	, goldsInBank()
	, thirstyCount()
	, fatigueCount()
{
}


Miner::~Miner()
{
}

void Miner::Update()
{
	++thirstyCount;
	if (currentState)
	{
		currentState->Execute(this);
	}
}

void Miner::ChangeState(State* newState)
{
	if (currentState == nullptr || newState == nullptr)
	{
		//error
	}

	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
}

void Miner::ChangeLocation(Location_Type newLocation)
{
	location = newLocation;
}


void Miner::AddToGold(int count)
{
	goldsInPocket += count;
}

void Miner::IncreaseFatigue()
{
	++fatigueCount;
}

bool Miner::IsThirsty() const
{
	return true;
}

bool Miner::IsPocketFull() const
{
	return true;
}

bool Miner::IsMaxFatigue() const
{
	return true;
}

