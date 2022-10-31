#include "EntityList.hpp"


namespace Lists
{
	EntityList::EntityList()
	{

	}


	EntityList::~EntityList()
	{

	}


	/* Adds Entity element to the list */
	void EntityList::pushEntity(Entities::Entity* entity)
	{
		entityList.pushElement(entity);
	}


	/* Deletes all Entity elements in the list */
	void EntityList::clear()
	{
		entityList.clear();
	}


	List<Entities::Entity> EntityList::getList()
	{
		return entityList;
	}


	/* Removes Entity element from given index */
	Entities::Entity* EntityList::removeEntity(int index)
	{
		return entityList.pop(index);
	}


	const unsigned int EntityList::getSize() const
	{
		return (entityList.getSize());
	}
}// namespace Lists