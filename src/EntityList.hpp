#pragma once


#include <SFML/Graphics.hpp>
#include "List.hpp"

class Entity;

class EntityList
{
private:
	List<Entity> entityList;

public:
	EntityList();
	~EntityList();

	void pushEntity(Entity* entity);
	void clear();
	List<Entity> getList();
	Entity* removeEntity(int index);
};