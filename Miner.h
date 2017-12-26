#pragma once
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include <memory>

class Miner
	: public BaseGameEntity
{
	static const int MAX_THIRSTY = 10;
	static const int POCKET_SIZE = 5;
	static const int FATIGUE_TO_WORK = 5;
	static const int THIRSTY_TO_WORK = 3;
	static const int ENOUGH_DEPOSIT = 20;
	static const int FATIGUE_HEALING_COUNT = 3;
	static const int THIRSTY_HEALING_COUNT = 4;

public:
	Miner(int newId);
	virtual ~Miner();

	void Update();
	bool HandleMessage(const Telegram& msg);
	void ChangeState(State<Miner>* newState);
	void ChangeLocation(Location_Type newLocation);

	void AddToGold(int count);
	void IncreaseFatigue();

	void DepositGold();

	void SleepAndRest();
	void DrinkBeer();

	bool IsThirsty() const;
	bool IsPocketFull() const;
	bool IsEnoughRested() const;
	bool IsEnoughDrinked() const;
	bool IsEnoughDepositGold() const;

	StateMachine<Miner>* GetFSM() const { return &(*stateMachine); }
	Location_Type		 GetLocation() const { return location; }

private:
	std::unique_ptr<StateMachine<Miner>>	stateMachine;

	Location_Type	location;
	int				goldsInPocket;
	int				goldsInBank;
	int				thirstyCount;
	int				fatigueCount;
};

