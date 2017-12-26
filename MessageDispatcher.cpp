#include "MessageDispatcher.h"
#include "EntityManager.h"
#include <chrono>

MessageDispatcher::MessageDispatcher()
	: msgQueue(DispatchLessTime())
	, entityManager(EntityManager::GetInstance())
{
}

MessageDispatcher* MessageDispatcher::GetInstance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::DispatchMessage(double delay
	, int sender
	, int receiver
	, int msg
	, void* extraInfo)
{
	using namespace std::chrono;

	BaseGameEntity* receiveEntity = entityManager->GetEntityFromId(receiver);
	Telegram telegram(sender, receiver, msg, delay, extraInfo);
	
	if (delay <= 0.0)
	{
		Discharge(receiveEntity, telegram);
	}
	else
	{
		double currentTime = duration_cast<milliseconds>
			(high_resolution_clock::now().time_since_epoch()).count();
		telegram.DispatchTime += currentTime;
		msgQueue.push(std::move(telegram));
	}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	using namespace std::chrono;
	double currentTime = duration_cast<milliseconds>
		(high_resolution_clock::now().time_since_epoch()).count();

	while (msgQueue.empty() == false)
	{
		Telegram telegram = msgQueue.top();
		
		if ((telegram.DispatchTime - currentTime) <= 0.0)
		{
			BaseGameEntity* receiveEntity =
				entityManager->GetEntityFromId(telegram.Receiver);
			Discharge(receiveEntity, telegram);
			msgQueue.pop();
		}
		else
			break;
	}
}


void MessageDispatcher::Discharge(BaseGameEntity* receiver, const Telegram& msg)
{
	if (receiver)
	{
		receiver->HandleMessage(msg);
	}
}