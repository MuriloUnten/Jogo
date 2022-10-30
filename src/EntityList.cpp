#include "EntityList.hpp"
#include "Entity.hpp"

namespace Lists
{
	EntityList::EntityList()
	{

	}


	EntityList::~EntityList()
	{

	}


	/* Adds Entity element to the list */
	void EntityList::pushEntity(Entity* entity)
	{
		entityList.pushElement(entity);
	}


	/* Deletes all Entity elements in the list */
	void EntityList::clear()
	{
		entityList.clear();
	}


	List<Entity> EntityList::getList()
	{
		return entityList;
	}


	/* Removes Entity element from given index */
	Entity* EntityList::removeEntity(int index)
	{
		return entityList.pop(index);
	}
}// namespace Lists