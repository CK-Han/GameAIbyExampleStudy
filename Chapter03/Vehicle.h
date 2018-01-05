#pragma once

#include "../Common/Vector2D.h"
#include "../Common/C2DMatrix.h"
#include "SteeringBehaviors.h"
#include <vector>
#include <memory>

class GameFramework;

class Vehicle
{
public:
	Vehicle(GameFramework* const gameFramework, const C2DMatrix& worldTransform);
	~Vehicle();

	void Update(double elapsedTime);
	void Render(HDC hDc);


public:
	GameFramework* const GetFramework() const { return gameFramework; }

	void SetWorldMatrix(const C2DMatrix& matrix) { worldMatrix = matrix; }
	C2DMatrix GetWorldMatrix() const { return worldMatrix; }

	void SetPosition(const Vector2D& position) { worldMatrix._31(position.x); worldMatrix._32(position.y); }
	Vector2D GetPosition() const { return Vector2D(worldMatrix._31(), worldMatrix._32()); }

	void SetMaxSpeed(int speed) { maxSpeed = speed; }
	int GetMaxSpeed() const { return maxSpeed; }

	Vector2D GetVelocity() const { return velocity; }
	SteeringBehaviors* const GetSteering() const { return &(*steeringBehaviors); }
	
	void ModifyMass(double value) { mass += value; if (mass < 0) mass = 0.000001; }
	
private:
	void InitializeShape();

private:
	std::vector<Vector2D>		vertices;
	
	GameFramework* const		gameFramework;
	C2DMatrix					worldMatrix;
	Vector2D					velocity;
	double						mass;

	std::shared_ptr<SteeringBehaviors>	steeringBehaviors;

	int							maxSpeed;
};

