#include "stdafx.h"
#include "Vehicle.h"
#include "../Common/transformations.h"


Vehicle::Vehicle(GameFramework* const gameFramework
	, const C2DMatrix& worldTransform)
	: gameFramework(gameFramework)
	, worldMatrix(worldTransform)
	, velocity(0, 0)
	, mass(0.5)
	, steeringBehaviors(new SteeringBehaviors(this))
	, maxSpeed(50)
{
	//triangle
	InitializeShape();
}


Vehicle::~Vehicle()
{
}

void Vehicle::InitializeShape()
{
	vertices.emplace_back(+0.0, -0.5);
	vertices.emplace_back(+0.5, +0.5);
	vertices.emplace_back(-0.5, +0.5);
}



void Vehicle::Update(double elapsedTime)
{
	Vector2D oldPosition = GetPosition();
	Vector2D steeringForce = steeringBehaviors->Calculate();

	Vector2D acceleration = steeringForce / mass;
	
	velocity += acceleration * elapsedTime;
	velocity.Truncate(maxSpeed);

	Vector2D newPosition = oldPosition + (velocity * elapsedTime);
	//조금이라도 움직였다면 방향을 새로 잡아준다
	if (velocity.LengthSq() > 0.00000001)
	{
		//...........
	}

	WrapAround(newPosition, WINDOW_WIDTH, WINDOW_HEIGHT);

	C2DMatrix matrix = GetWorldMatrix();
	matrix._31(newPosition.x);
	matrix._32(newPosition.y);
	SetWorldMatrix(matrix);	
}

void Vehicle::Render(HDC hDc)
{
	::MoveToEx(hDc, worldMatrix._31(), worldMatrix._32(), nullptr);

	for (auto& vertex : vertices)
	{
		Vector2D pointToWorld = PointToWorldSpace(vertex
			, Vector2D(worldMatrix._11(), worldMatrix._12())
			, Vector2D(worldMatrix._21(), worldMatrix._22())
			, Vector2D(worldMatrix._31(), worldMatrix._32()));

		::LineTo(hDc, pointToWorld.x, pointToWorld.y);
		::MoveToEx(hDc, pointToWorld.x, pointToWorld.y, nullptr);
	}

	Vector2D firstPointToWorld = PointToWorldSpace(vertices.front()
		, Vector2D(worldMatrix._11(), worldMatrix._12())
		, Vector2D(worldMatrix._21(), worldMatrix._22())
		, Vector2D(worldMatrix._31(), worldMatrix._32()));

	::LineTo(hDc, firstPointToWorld.x, firstPointToWorld.y);
	
	
}