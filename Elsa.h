#pragma once
#include "BaseGameEntity.h"
#include "StateMachine.h"
#include <memory>

class Elsa
	: public BaseGameEntity
{
public:
	Elsa(int newId);
	~Elsa();

	void Update();
	void ChangeState(State<Elsa>* newState);

private:
	std::unique_ptr<StateMachine<Elsa>>	stateMachine;
};

