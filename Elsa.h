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
	bool HandleMessage(const Telegram& msg);
	void ChangeState(State<Elsa>* newState);

	void SetCooking(bool cooking);
	bool IsCooking() const;

private:
	std::unique_ptr<StateMachine<Elsa>>	stateMachine;
	bool	isCooking;
};

