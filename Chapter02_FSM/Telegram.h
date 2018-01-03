#pragma once

struct Telegram
{
	int Sender;
	int Receiver;
	int Msg;

	double DispatchTime;
	void* ExtraInfo;

	Telegram(int sender, int receiver
		, int msg, double dispatchTime, void* extraInfo)
		: Sender(sender)
		, Receiver(receiver)
		, Msg(msg)
		, DispatchTime(dispatchTime)
		, ExtraInfo(extraInfo)
	{}
};


