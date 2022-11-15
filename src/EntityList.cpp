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


	List<Entities::Entity>& EntityList::getList()
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


	/* Iterates through the list, calling the execute() method of all entities */
	void EntityList::execute()
	{
		List<Entities::Entity>::Element<Entities::Entity>* iterator = entityList.getHead();
		while(iterator != NULL)
		{
			iterator->getData()->execute();
			iterator = iterator->getNext();
		}
	}

	/* Iterates through the list, calling the draw() method of all entities */
	void EntityList::draw()
	{
		List<Entities::Entity>::Element<Entities::Entity>* iterator = entityList.getHead();
		while(iterator != NULL)
		{
			iterator->getData()->draw();
			iterator = iterator->getNext();
		}
	}

}// namespace Lists