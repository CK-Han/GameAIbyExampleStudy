#include "BaseGameEntity.h"

int BaseGameEntity::nextValidId;

void BaseGameEntity::SetId(int newId)
{
	if (newId < nextValidId)
	{
		//error
	}
	else
	{
		id = newId;
		nextValidId = id + 1;
	}
}