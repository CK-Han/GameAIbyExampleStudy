#include "Miner.h"
#include "MinerState.h"
#include "Telegram.h"

Miner::Miner(int newId)
	: BaseGameEntity(newId)
	, stateMachine(new StateMachine<Miner>(this))
	, location(Location_Type::GOLDMINE)
	, goldsInPocket(0)
	, goldsInBank(0)
	, thirstyCount(0)
	, fatigueCount(0)
{
	stateMachine->SetCurrentState(EnterMineAndDigForNugget::GetInstance());
	stateMachine->SetGlobalState(MinerGlobalState::GetInstance());
}

Miner::~Miner()
{
}

void Miner::Update()
{
	++thirstyCount;
	stateMachine->Update();
}

bool Miner::HandleMessage(const Telegram& msg)
{
	return stateMachine->HandleMessage(msg);
}

void Miner::ChangeState(State<Miner>* newState)
{
	stateMachine->ChangeState(newState);
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

void Miner::DepositGold()
{
	goldsInBank += goldsInPocket;
	goldsInPocket = 0;
}

void Miner::SleepAndRest()
{
	fatigueCount -= FATIGUE_HEALING_COUNT;
	if (fatigueCount < 0)
		fatigueCount = 0;
}

void Miner::DrinkBeer()
{
	thirstyCount -= THIRSTY_HEALING_COUNT;
	if (thirstyCount < 0)
		thirstyCount = 0;
}

bool Miner::IsThirsty() const
{
	if(MAX_THIRSTY <= thirstyCount)
		return true;
	return false;
}

bool Miner::IsPocketFull() const
{
	if(POCKET_SIZE <= goldsInPocket)
		return true;
	return false;
}

bool Miner::IsEnoughRested() const
{
	if(FATIGUE_TO_WORK >= fatigueCount)
		return true;
	return false;
}

bool Miner::IsEnoughDrinked() const
{
	if (THIRSTY_TO_WORK <= thirstyCount)
		return true;
	return false;
}

bool Miner::IsEnoughDepositGold() const
{
	if (ENOUGH_DEPOSIT <= goldsInBank)
		return true;
	return false;
}

