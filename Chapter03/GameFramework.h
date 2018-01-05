#pragma once

#include <vector>
#include "Vehicle.h"
#include "../Common/Timer.h"


class GameFramework
{
public:
	GameFramework();
	~GameFramework();

	void Update();
	void Render(HDC hDc);

	void Clicked(const POINTS& points);

	Vector2D GetClickedPosition() const { return clickedPosition; }
	void ModifyVehicleMass(int slot, double value) { vehicles[slot].ModifyMass(value); }

private:
	std::vector<Vehicle>		vehicles;

	int							clientWidth;
	int							clientHeight;

	Vector2D					clickedPosition;
	Timer						timer;

	bool						isClicked;
};

