#pragma once

#include <chrono>
using namespace std::chrono;

//millisecond
class Timer
{
public:
	Timer() { Start(); }
	~Timer() {}

	void Start()
	{
		start = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
		last = start;
	}

	long long ElapsedTime() 
	{
		long long now = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
		long long elapsedTime = now - last;
		last = now;

		return elapsedTime;
	}
	

private:
	long long		start;
	long long		last;
};