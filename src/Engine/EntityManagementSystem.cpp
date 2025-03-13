#include "EntityManagementSystem.hpp"


EntityManagementSystem::EntityManagementSystem() {

}

EntityManagementSystem::~EntityManagementSystem() {
	for (Entity* iter : m_entities) 
		delete iter;
	
}

void EntityManagementSystem::addEntity(Entity* entity) {
	m_entities.push_back(entity);
}

void EntityManagementSystem::deleteEntity(Entity* entity) {
	std::vector <Entity*>::iterator iter = std::find(m_entities.begin(), m_entities.end(), entity);
	m_entities.erase(iter);
}

