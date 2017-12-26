#include "ElsaState.h"
#include "Elsa.h"
#include "MyMath.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////
//ElsaGlobalState
ElsaGlobalState*
	ElsaGlobalState::GetInstance()
{
	static ElsaGlobalState instance;
	return &instance;
}

void ElsaGlobalState::Enter(Elsa* elsa)
{
}

void ElsaGlobalState::Execute(Elsa* elsa)
{
	int bathroomFactor = MyMath::GetRandInteger(1, 10);
	if (bathroomFactor == 1)
	{
		elsa->ChangeState(VisitBathroomState::GetInstance());
	}
}

void ElsaGlobalState::Exit(Elsa* elsa)
{	
}

//ElsaGlobalState
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//DoHouseworkState
DoHouseworkState*
	DoHouseworkState::GetInstance()
{
	static DoHouseworkState instance;
	return &instance;
}

void DoHouseworkState::Enter(Elsa* elsa)
{
}

void DoHouseworkState::Execute(Elsa* elsa)
{
	int factor = MyMath::GetRandInteger(0, 2);

	switch (factor)
	{
	case 0:
		std::cout << elsa->GetId() << " : " << "swip swip\n";
		break;
	case 1:
		std::cout << elsa->GetId() << " : " << "mob mob\n";
		break;
	case 2:
		std::cout << elsa->GetId() << " : " << "washing wahsing\n";
		break;
	default:
		;//error occurred!
	}
}

void DoHouseworkState::Exit(Elsa* elsa)
{
}

//DoHouseworkState
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//VisitBathroomState
VisitBathroomState*
VisitBathroomState::GetInstance()
{
	static VisitBathroomState instance;
	return &instance;
}

void VisitBathroomState::Enter(Elsa* elsa)
{
	std::cout << elsa->GetId() << " : " << "go to bathroom\n";
}

void VisitBathroomState::Execute(Elsa* elsa)
{
	std::cout << elsa->GetId() << " : " << "whooo... sweet relief!\n";
	elsa->ChangeState(DoHouseworkState::GetInstance());
}

void VisitBathroomState::Exit(Elsa* elsa)
{
}

//VisitBathroomState
//////////////////////////////////////////////////////////////////////////