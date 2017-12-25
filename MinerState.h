#pragma once

#include "State.h"

class EnterMineAndDigForNugget
	: public State
{
public:
	static EnterMineAndDigForNugget* GetInstance();
	
	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	EnterMineAndDigForNugget() {};
	~EnterMineAndDigForNugget() {}

	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&) = delete;
	EnterMineAndDigForNugget(EnterMineAndDigForNugget&&) = delete;
	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&) = delete;
};

