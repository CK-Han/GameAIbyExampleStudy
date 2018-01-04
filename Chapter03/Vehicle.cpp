#include "stdafx.h"
#include "Vehicle.h"
#include "../Common/transformations.h"

Vehicle::Vehicle(const C2DMatrix& worldTransform)
	: worldMatrix(worldTransform)
	, remainedForce(0, 0)
	, steeringBehaviors(new SteeringBehaviors(this))
{
	//triangle
	InitializeShape();
}

Vehicle::Vehicle(const Vehicle& other)
	: worldMatrix(other.worldMatrix)
	, remainedForce(0, 0)
	, steeringBehaviors(new SteeringBehaviors(this))
{
	//steeringBehaviors 관련 복사 진행
	
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

void Vehicle::SetPosition(const Vector2D& position)
{
	worldMatrix._31(position.x);
	worldMatrix._32(position.y);
}


void Vehicle::Update(double elapsedTime)
{

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