#pragma once

#include <vector>
#include "Vehicle.h"


class GameFramework
{
public:
	GameFramework();
	~GameFramework();

	void Update(double elapsedTime);
	void Render(HDC hDc);

	void SetPosition(const POINTS& points);

private:
	std::vector<Vehicle>		vehicles;

	int							clientWidth;
	int							clientHeight;
};

