#pragma once

#include <map>
#include "BaseGameEntity.h"

class EntityManager
{
public:
	static EntityManager* GetInstance();

	void RegisterEntity(BaseGameEntity* newEntity);
	void RemoveEntity(BaseGameEntity* entity);
	BaseGameEntity* GetEntityFromId(int id) const;
	
private:
	typedef std::map<int /*id*/, BaseGameEntity*> EntityMap;

	EntityMap entities;

	EntityManager() {}
	~EntityManager() {}

	EntityManager(const EntityManager&) = delete;
	EntityManager(EntityManager&&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;
};

