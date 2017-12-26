#pragma once

#include "State.h"

class Miner;

class EnterMineAndDigForNugget
	: public State<Miner>
{
public:
	static EnterMineAndDigForNugget* GetInstance();
	
	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	EnterMineAndDigForNugget() {};
	~EnterMineAndDigForNugget() {}
};


class VisitBankAndDepositGold
	: public State<Miner>
{
public:
	static VisitBankAndDepositGold* GetInstance();

	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	VisitBankAndDepositGold() {};
	~VisitBankAndDepositGold() {}
};


class GoHomeAndSleepTilRested
	: public State<Miner>
{
public:
	static GoHomeAndSleepTilRested* GetInstance();

	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	GoHomeAndSleepTilRested() {};
	~GoHomeAndSleepTilRested() {}
};


class QuenchThirst
	: public State<Miner>
{
public:
	static QuenchThirst* GetInstance();

	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	QuenchThirst() {};
	~QuenchThirst() {}
};


class MinerGlobalState
	: public State<Miner>
{
public:
	static MinerGlobalState* GetInstance();

	virtual void Enter(Miner*);
	virtual void Execute(Miner*);
	virtual void Exit(Miner*);

private:
	MinerGlobalState() {};
	~MinerGlobalState() {}
};