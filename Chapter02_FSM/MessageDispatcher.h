#pragma once

#include <queue>
#include <vector>
#include "Messages.h"
#include "EntityManager.h"

class MessageDispatcher
{
	class DispatchLessTime
	{
	public:
		bool operator()(const Telegram& lhs, const Telegram& rhs)
		{
			return lhs.DispatchTime > rhs.DispatchTime;
		}
	};

public:
	static MessageDispatcher* GetInstance();
	void DispatchMessage(double delay
		, int sender
		, int receiver
		, int msg
		, void* extraInfo);

	void DispatchDelayedMessages();

private:
	MessageDispatcher();
	~MessageDispatcher() {}

	MessageDispatcher(const MessageDispatcher&) = delete;
	MessageDispatcher(MessageDispatcher&&) = delete;
	MessageDispatcher& operator=(const MessageDispatcher&) = delete;

	void Discharge(BaseGameEntity* receiver, const Telegram& msg);

	std::priority_queue<Telegram, std::vector<Telegram>, DispatchLessTime>	msgQueue;
	EntityManager* entityManager;
};

