#pragma once

//class BaseGameEntity;
class Miner;

enum class Location_Type { HOME, GOLDMINE, PUB, BANK };

class State
{
public:
	virtual ~State() {}

	virtual void Enter(Miner*) = 0;
	virtual void Execute(Miner*) = 0;
	virtual void Exit(Miner*) = 0;
};

