#include "Elsa.h"
#include "ElsaState.h"
#include "EntityManager.h"

Elsa::Elsa(int newId)
	: BaseGameEntity(newId)
	, stateMachine(new StateMachine<Elsa>(this))
	, isCooking(false)
{
	stateMachine->SetGlobalState(ElsaGlobalState::GetInstance());
	stateMachine->SetCurrentState(DoHouseworkState::GetInstance());

	EntityManager::GetInstance()->RegisterEntity(this);
}

Elsa::~Elsa()
{
}


void Elsa::Update()
{
	stateMachine->Update();
}

bool Elsa::HandleMessage(const Telegram& msg)
{
	return stateMachine->HandleMessage(msg);
}

void Elsa::ChangeState(State<Elsa>* newState)
{
	stateMachine->ChangeState(newState);
}

void Elsa::SetCooking(bool cooking)
{
	isCooking = cooking;
}

bool Elsa::IsCooking() const
{
	return isCooking;
}