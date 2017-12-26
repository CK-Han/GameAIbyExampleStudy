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
	if(miner->GetLocation() != Location_Type::GOLDMINE)
	{
		std::cout << miner->GetId() << " : " << "walkin' to the gold mine\n";
		miner->ChangeLocation(Location_Type::GOLDMINE);
	}
}

void EnterMineAndDigForNugget::Execute(Miner* miner)
{
	std::cout << miner->GetId() << " : " << "diggin' mine\n";
	miner->AddToGold(1);
	miner->IncreaseFatigue();

	if (miner->IsPocketFull())
	{
		std::cout << miner->GetId() << " : " << "umm... pocket is full\n";
		miner->ChangeState(VisitBankAndDepositGold::GetInstance());
	}
	else if (miner->IsThirsty())
	{
		std::cout << miner->GetId() << " : " << "I'm so thirsty. I'll go to Pub\n";
		miner->ChangeState(QuenchThirst::GetInstance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner* miner)
{
	std::cout << miner->GetId() << " : " << "leavin' goldmine\n";
}

bool EnterMineAndDigForNugget::OnMessage(Miner*, const Telegram&)
{
	return false;
}

//EnterMineAndDigForNugget
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//VisitBankAndDepositGold
VisitBankAndDepositGold*
VisitBankAndDepositGold::GetInstance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* miner)
{
	if (miner->GetLocation() != Location_Type::BANK)
	{
		std::cout << miner->GetId() << " : " << "walkin' to the bank\n";
		miner->ChangeLocation(Location_Type::BANK);
	}
}

void VisitBankAndDepositGold::Execute(Miner* miner)
{
	if (miner->IsPocketFull())
	{
		std::cout << miner->GetId() << " : " << "save golds for future!\n";
		miner->DepositGold();
	}

	if (miner->IsEnoughDepositGold())
	{
		std::cout << miner->GetId() << " : " << "oh! I'm so working hard! go to home and meet my quty wife!\n";
		miner->ChangeState(GoHomeAndSleepTilRested::GetInstance());
	}
	else // get to gold
	{
		std::cout << miner->GetId() << " : " << "I need more gold!\n";
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
}

void VisitBankAndDepositGold::Exit(Miner* miner)
{
	std::cout << miner->GetId() << " : " << "leavin' bank\n";
}

bool VisitBankAndDepositGold::OnMessage(Miner*, const Telegram&)
{
	return false;
}

//VisitBankAndDepositGold
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//GoHomeAndSleepTilRested
GoHomeAndSleepTilRested*
GoHomeAndSleepTilRested::GetInstance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* miner)
{
	if (miner->GetLocation() != Location_Type::HOME)
	{
		std::cout << miner->GetId() << " : " << "walkin' to the HOME\n";
		miner->ChangeLocation(Location_Type::HOME);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner* miner)
{
	if (miner->IsEnoughRested())
	{
		std::cout << miner->GetId() << " : " << "ah! I rested enough!! \n";
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
	else
	{
		std::cout << miner->GetId() << " : " << "umm... I need more rest... \n";
		miner->SleepAndRest();
	}
}

void GoHomeAndSleepTilRested::Exit(Miner* miner)
{
	std::cout << miner->GetId() << " : " << "leavin' home\n";
}

bool GoHomeAndSleepTilRested::OnMessage(Miner*, const Telegram&)
{
	return false;
}

//GoHomeAndSleepTilRested
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//QuenchThirst
QuenchThirst*
QuenchThirst::GetInstance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner* miner)
{
	if (miner->GetLocation() != Location_Type::PUB)
	{
		std::cout << miner->GetId() << " : " << "walkin' to the PUB\n";
		miner->ChangeLocation(Location_Type::PUB);
	}
}

void QuenchThirst::Execute(Miner* miner)
{
	if (miner->IsEnoughDrinked())
	{
		std::cout << miner->GetId() << " : " << "I'm drinked enough!\n";
		miner->ChangeState(EnterMineAndDigForNugget::GetInstance());
	}
	else
	{
		std::cout << miner->GetId() << " : " << "hmm... I'm still thirsty\n";
		miner->DrinkBeer();
	}
}

void QuenchThirst::Exit(Miner* miner)
{
	std::cout << miner->GetId() << " : " << "leavin' pub\n";
}

bool QuenchThirst::OnMessage(Miner*, const Telegram&)
{
	return false;
}

//QuenchThirst
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
//MinerGlobalState
MinerGlobalState*
MinerGlobalState::GetInstance()
{
	static MinerGlobalState instance;
	return &instance;
}

void MinerGlobalState::Enter(Miner* miner)
{
}

void MinerGlobalState::Execute(Miner* miner)
{

}

void MinerGlobalState::Exit(Miner* miner)
{

}

bool MinerGlobalState::OnMessage(Miner*, const Telegram&)
{
	return false;
}

//MinerGlobalState
//////////////////////////////////////////////////////////////////////////