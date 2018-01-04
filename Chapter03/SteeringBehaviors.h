#pragma once

class Vehicle;

class SteeringBehaviors
{
public:
	SteeringBehaviors(const Vehicle* pVehicle);
	~SteeringBehaviors();

private:
	const Vehicle*			vehicle;
};

