#pragma once

#include "../Common/Vector2D.h"
class Vehicle;

class SteeringBehaviors
{
private:
	enum behavior_type
	{
		none = 0x00000,
		seek = 0x00002,
		flee = 0x00004,
		arrive = 0x00008,
		wander = 0x00010,
		cohesion = 0x00020,
		separation = 0x00040,
		allignment = 0x00080,
		obstacle_avoidance = 0x00100,
		wall_avoidance = 0x00200,
		follow_path = 0x00400,
		pursuit = 0x00800,
		evade = 0x01000,
		interpose = 0x02000,
		hide = 0x04000,
		flock = 0x08000,
		offset_pursuit = 0x10000,
	};
	enum Deceleration { slow = 3, normal = 2, fast = 1 };

public:
	SteeringBehaviors(const Vehicle* pVehicle);
	~SteeringBehaviors();

	Vector2D		Calculate();


public:
	bool On(behavior_type bt) { return (movingFlag & bt) == bt; }

	void FleeOn() { movingFlag |= flee; }
	void SeekOn() { movingFlag |= seek; }
	void ArriveOn() { movingFlag |= arrive; }
	void WanderOn() { movingFlag |= wander; }
	void PursuitOn(Vehicle* v) { movingFlag |= pursuit; targetAgent1 = v; }
	void EvadeOn(Vehicle* v) { movingFlag |= evade; targetAgent1 = v; }
	void CohesionOn() { movingFlag |= cohesion; }
	void SeparationOn() { movingFlag |= separation; }
	void AlignmentOn() { movingFlag |= allignment; }
	void ObstacleAvoidanceOn() { movingFlag |= obstacle_avoidance; }
	void WallAvoidanceOn() { movingFlag |= wall_avoidance; }
	void FollowPathOn() { movingFlag |= follow_path; }
	void InterposeOn(Vehicle* v1, Vehicle* v2) { movingFlag |= interpose; targetAgent1 = v1; targetAgent2 = v2; }
	void HideOn(Vehicle* v) { movingFlag |= hide; targetAgent1 = v; }
	void OffsetPursuitOn(Vehicle* v1, const Vector2D offset) { movingFlag |= offset_pursuit; offSet = offset; targetAgent1 = v1; }
	void FlockingOn() { CohesionOn(); AlignmentOn(); SeparationOn(); WanderOn(); }

	void FleeOff() { if (On(flee))   movingFlag ^= flee; }
	void SeekOff() { if (On(seek))   movingFlag ^= seek; }
	void ArriveOff() { if (On(arrive)) movingFlag ^= arrive; }
	void WanderOff() { if (On(wander)) movingFlag ^= wander; }
	void PursuitOff() { if (On(pursuit)) movingFlag ^= pursuit; }
	void EvadeOff() { if (On(evade)) movingFlag ^= evade; }
	void CohesionOff() { if (On(cohesion)) movingFlag ^= cohesion; }
	void SeparationOff() { if (On(separation)) movingFlag ^= separation; }
	void AlignmentOff() { if (On(allignment)) movingFlag ^= allignment; }
	void ObstacleAvoidanceOff() { if (On(obstacle_avoidance)) movingFlag ^= obstacle_avoidance; }
	void WallAvoidanceOff() { if (On(wall_avoidance)) movingFlag ^= wall_avoidance; }
	void FollowPathOff() { if (On(follow_path)) movingFlag ^= follow_path; }
	void InterposeOff() { if (On(interpose)) movingFlag ^= interpose; }
	void HideOff() { if (On(hide)) movingFlag ^= hide; }
	void OffsetPursuitOff() { if (On(offset_pursuit)) movingFlag ^= offset_pursuit; }
	void FlockingOff() { CohesionOff(); AlignmentOff(); SeparationOff(); WanderOff(); }

	bool isFleeOn() { return On(flee); }
	bool isSeekOn() { return On(seek); }
	bool isArriveOn() { return On(arrive); }
	bool isWanderOn() { return On(wander); }
	bool isPursuitOn() { return On(pursuit); }
	bool isEvadeOn() { return On(evade); }
	bool isCohesionOn() { return On(cohesion); }
	bool isSeparationOn() { return On(separation); }
	bool isAlignmentOn() { return On(allignment); }
	bool isObstacleAvoidanceOn() { return On(obstacle_avoidance); }
	bool isWallAvoidanceOn() { return On(wall_avoidance); }
	bool isFollowPathOn() { return On(follow_path); }
	bool isInterposeOn() { return On(interpose); }
	bool isHideOn() { return On(hide); }
	bool isOffsetPursuitOn() { return On(offset_pursuit); }

//////////////////////////////////////////////////
//behaviors
public:
	Vector2D		Seek(Vector2D targetPos);
	Vector2D		Arrive(Vector2D targetPos, Deceleration deceleration);

private:
	const Vehicle*			vehicle;
	int						movingFlag;

	Vehicle*				targetAgent1;
	Vehicle*				targetAgent2;

	Vector2D				offSet;
};

