#include "stdafx.h"
#include "GameFramework.h"
#include "../Common/C2DMatrix.h"

GameFramework::GameFramework()
	: clientWidth(WINDOW_WIDTH)
	, clientHeight(WINDOW_HEIGHT)
{
	C2DMatrix worldTransform;
	worldTransform.Scale(clientWidth / 20, clientHeight / 20);
	worldTransform.Translate(50, 50);
	vehicles.push_back(worldTransform);
}


GameFramework::~GameFramework()
{
}



void GameFramework::SetPosition(const POINTS& points)
{
	vehicles[0].SetPosition(Vector2D(points.x, points.y));
}

void GameFramework::Update(double elapsedTime)
{
	for (auto& vehicle : vehicles)
		vehicle.Update(elapsedTime);
}

void GameFramework::Render(HDC hDc)
{
	for (auto& vehicle : vehicles)
		vehicle.Render(hDc);
}