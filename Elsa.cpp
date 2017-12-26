#include "Elsa.h"
#include "ElsaState.h"


Elsa::Elsa(int newId)
	: BaseGameEntity(newId)
	, stateMachine(new StateMachine<Elsa>(this))
{
	stateMachine->SetGlobalState(ElsaGlobalState::GetInstance());
	stateMachine->SetCurrentState(DoHouseworkState::GetInstance());
}

Elsa::~Elsa()
{
}


void Elsa::Update()
{
	stateMachine->Update();
}

void Elsa::ChangeState(State<Elsa>* newState)
{
	stateMachine->ChangeState(newState);
}
