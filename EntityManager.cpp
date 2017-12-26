#include "EntityManager.h"

EntityManager* EntityManager::GetInstance()
{
	static EntityManager instance;
	return &instance;
}

void EntityManager::RegisterEntity(BaseGameEntity* newEntity)
{
	entities.insert(std::make_pair(newEntity->GetId(), newEntity));
}

void EntityManager::RemoveEntity(BaseGameEntity* entity)
{
	auto iter = entities.find(entity->GetId());
	if (iter != entities.end())
	{
		entities.erase(iter);
	}
}

BaseGameEntity* EntityManager::GetEntityFromId(int id) const
{
	auto iter = entities.find(id);
	if (iter != entities.end())
		return iter->second;
	else
		return nullptr;
}