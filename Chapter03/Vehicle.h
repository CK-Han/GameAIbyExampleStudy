#pragma once

#include "../Common/Vector2D.h"
#include "../Common/C2DMatrix.h"
#include "SteeringBehaviors.h"
#include <vector>
#include <memory>


class Vehicle
{
public:
	Vehicle(const C2DMatrix& worldTransform);
	Vehicle(const Vehicle&);
	~Vehicle();

	void SetPosition(const Vector2D& position);

	void Update(double elapsedTime);
	void Render(HDC hDc);

private:
	void InitializeShape();

private:
	std::vector<Vector2D>		vertices;
	
	C2DMatrix					worldMatrix;
	Vector2D					remainedForce;

	std::unique_ptr<SteeringBehaviors>	steeringBehaviors;
};

