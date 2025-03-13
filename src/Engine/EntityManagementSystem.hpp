#pragma once
#include <vector>
#include "Entity.hpp"

class EntityManagementSystem {

private:
	std::vector <Entity*> m_entities;

public:
	EntityManagementSystem();
	~EntityManagementSystem();

	void addEntity(Entity* entity);
	void deleteEntity(Entity* entity);
};