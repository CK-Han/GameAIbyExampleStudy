#include "stdafx.h"
#include "SteeringBehaviors.h"
#include "Vehicle.h"
#include "GameFramework.h"

SteeringBehaviors::SteeringBehaviors(const Vehicle* pVehicle)
	: vehicle(pVehicle)
	, movingFlag(behavior_type::none)
{
}


SteeringBehaviors::~SteeringBehaviors()
{
}


Vector2D SteeringBehaviors::Calculate() 
{
	Vector2D resultVelocity;

	//현재 Seek만 존재
	if (On(behavior_type::seek))
	{
		resultVelocity = Seek(vehicle->GetFramework()->GetClickedPosition());
	}
	
	return resultVelocity;
}

Vector2D SteeringBehaviors::Seek(Vector2D targetPos)
{
	Vector2D desiredVelocity 
		= Vec2DNormalize(targetPos - vehicle->GetPosition()) * vehicle->GetMaxSpeed();

	return desiredVelocity - vehicle->GetVelocity();
}

Vector2D SteeringBehaviors::Arrive(Vector2D targetPos, Deceleration deceleration)
{
	Vector2D toTarget = targetPos - vehicle->GetPosition();

	double dist = toTarget.Length();

	if (dist > 0)
	{
		static const double DecelerationTweaker = 0.3;
		double speed = dist / ((double)deceleration * DecelerationTweaker);
	}
}