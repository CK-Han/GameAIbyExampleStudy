#include "ElsaState.h"
#include "Elsa.h"
#include "MyMath.h"
#include "Messages.h"
#include "MessageDispatcher.h"
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

bool ElsaGlobalState::OnMessage(Elsa* elsa, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_HiHoneyImHome:
	{
		std::cout << elsa->GetId() << " : " << "oh honey! Let me make you some of mah fine country stew\n";
		elsa->ChangeState(CookStewState::GetInstance());
	}
		return true;
	}

	return false;
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

bool DoHouseworkState::OnMessage(Elsa*, const Telegram&)
{
	return false;
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

bool VisitBathroomState::OnMessage(Elsa*, const Telegram&)
{
	return false;
}

//VisitBathroomState
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
//CookStewState
CookStewState*
CookStewState::GetInstance()
{
	static CookStewState instance;
	return &instance;
}

void CookStewState::Enter(Elsa* elsa)
{
}

void CookStewState::Execute(Elsa* elsa)
{
	if (elsa->IsCooking() == false)
	{
		std::cout << elsa->GetId() << " : " << " Puttin' the stew in the oven\n";

		MessageDispatcher::GetInstance()->DispatchMessage(
			1.5, elsa->GetId(), elsa->GetId(), Msg_StewReady, nullptr);
		
		elsa->SetCooking(true);
	}
}

void CookStewState::Exit(Elsa* elsa)
{
}

bool CookStewState::OnMessage(Elsa* elsa, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_StewReady:
		std::cout << elsa->GetId() << " : " << " Stew ready! Let's eat!\n";
		MessageDispatcher::GetInstance()->DispatchMessage(
			0, elsa->GetId(), BOB, Msg_StewReady, nullptr);

		elsa->SetCooking(false);
		elsa->ChangeState(DoHouseworkState::GetInstance());

		return true;
	}
	return false;
}

//CookStewState
//////////////////////////////////////////////////////////////////////////