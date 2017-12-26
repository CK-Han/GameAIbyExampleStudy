#pragma once

struct Telegram;

enum class Location_Type { HOME, GOLDMINE, PUB, BANK };

template <typename Entity>
class State
{
public:
	State() {}
	virtual ~State() {}

	virtual void Enter(Entity*) = 0;
	virtual void Execute(Entity*) = 0;
	virtual void Exit(Entity*) = 0;
	
	virtual bool OnMessage(Entity*, const Telegram&) = 0;

private:
	State(const State&) = delete;
	State(State&&) = delete;
	State& operator=(const State&) = delete;
};

