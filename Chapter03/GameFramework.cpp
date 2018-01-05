#include "stdafx.h"
#include "GameFramework.h"
#include "../Common/C2DMatrix.h"

GameFramework::GameFramework()
	: clientWidth(WINDOW_WIDTH)
	, clientHeight(WINDOW_HEIGHT)
	, clickedPosition(Vector2D(0, 0))
	, timer()
	, isClicked(false)
{
	C2DMatrix worldTransform;
	worldTransform.Scale(clientWidth / 20, clientHeight / 20);
	worldTransform.Translate(50, 50);
	vehicles.emplace_back(this, worldTransform);
}


GameFramework::~GameFramework()
{
}



void GameFramework::Clicked(const POINTS& points)
{
	clickedPosition = Vector2D(points.x, points.y);
	vehicles[0].GetSteering()->SeekOn();
	isClicked = true;
}

void GameFramework::Update()
{
	double elapsedTime = timer.ElapsedTime() / 1000.0; //ms to sec

	for (auto& vehicle : vehicles)
		vehicle.Update(elapsedTime);
}

void GameFramework::Render(HDC hDc)
{
	if (isClicked)
	{
		Ellipse(hDc, clickedPosition.x - 2, clickedPosition.y - 2, clickedPosition.x + 2, clickedPosition.y + 2);
	}

	for (auto& vehicle : vehicles)
		vehicle.Render(hDc);
}