#pragma once
#include "State.h"

template <class Entity_Type>
class StateMachine
{
public:
	StateMachine(Entity_Type* owner)
		: owner(owner)
		, currentState(nullptr)
		, previousState(nullptr)
		, globalState(nullptr)
	{}

	~StateMachine() {};

	State<Entity_Type>* GetCurrentState() const { return currentState; }
	State<Entity_Type>* GetPreviousState() const { return previousState; }
	State<Entity_Type>* GetGlobalState() const { return globalState; }

	void SetCurrentState(State<Entity_Type>* state) { currentState = state; }
	void SetPreviousState(State<Entity_Type>* state) { previousState = state; }
	void SetGlobalState(State<Entity_Type>* state) { globalState = state; }

	void Update() const
	{
		if (globalState)
			globalState->Execute(owner);

		if (currentState)
			currentState->Execute(owner);
	}

	void ChangeState(State<Entity_Type>* newState)
	{
		if (newState == nullptr || currentState == nullptr)
		{
			//error
		}

		previousState = currentState;
		currentState->Exit(owner);
		currentState = newState;
		currentState->Enter(owner);
	}

	void RevertToPreviousState()
	{
		ChangeState(previousState);
	}

	bool IsInState(const State<Entity_Type>& state) const
	{
		if (currentState == state)
			return true;
		return false;
	}

	bool HandleMessage(const Telegram& msg) const
	{
		if (currentState && currentState->OnMessage(owner, msg))
			return true;
		if (globalState && globalState->OnMessage(owner, msg))
			return true;
		return false;
	}

private:
	Entity_Type*				owner;
	State<Entity_Type>*			currentState;
	State<Entity_Type>*			previousState;
	State<Entity_Type>*			globalState;
};

