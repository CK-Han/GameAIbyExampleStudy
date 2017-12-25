#pragma once
#include "BaseGameEntity.h"
#include "State.h"

class Miner
	: public BaseGameEntity
{
public:
	Miner(int newId);
	virtual ~Miner();

	void Update();
	void ChangeState(State* newState);
	void ChangeLocation(Location_Type newLocation);

	void AddToGold(int count);
	void IncreaseFatigue();

	bool IsThirsty() const;
	bool IsPocketFull() const;
	bool IsMaxFatigue() const;

private:
	State*			currentState;
	Location_Type	location;
	int				goldsInPocket;
	int				goldsInBank;
	int				thirstyCount;
	int				fatigueCount;
};

