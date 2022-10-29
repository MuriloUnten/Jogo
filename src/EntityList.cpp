#include "EntityList.hpp"
#include "Entity.hpp"

EntityList::EntityList()
{

}


EntityList::~EntityList()
{

}


void EntityList::pushEntity(Entity* entity)
{
	entityList.pushElement(entity);
}


void EntityList::clear()
{
	entityList.clear();
}


List<Entity> EntityList::getList()
{
	return entityList;
}


Entity* EntityList::removeEntity(int index)
{
	return entityList.pop(index);
}