#pragma once

#include "State.h"

class Elsa;

class ElsaGlobalState
	: public State<Elsa>
{
public:
	static ElsaGlobalState* GetInstance();

	virtual void Enter(Elsa*);
	virtual void Execute(Elsa*);
	virtual void Exit(Elsa*);

private:
	ElsaGlobalState() {};
	~ElsaGlobalState() {}
};


class DoHouseworkState
	: public State<Elsa>
{
public:
	static DoHouseworkState* GetInstance();
	
	virtual void Enter(Elsa*);
	virtual void Execute(Elsa*);
	virtual void Exit(Elsa*);

private:
	DoHouseworkState() {};
	~DoHouseworkState() {}
};


class VisitBathroomState
	: public State<Elsa>
{
public:
	static VisitBathroomState* GetInstance();

	virtual void Enter(Elsa*);
	virtual void Execute(Elsa*);
	virtual void Exit(Elsa*);

private:
	VisitBathroomState() {};
	~VisitBathroomState() {}
};
