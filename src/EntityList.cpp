#include "EntityList.hpp"
#include "Player.hpp"

namespace Lists
{
	EntityList::EntityList()
	{

	}

	/* Deletes all entities, except if that entity is a Player */
	EntityList::~EntityList()
	{
		if(entityList.getHead() != NULL)
		{
			List<Entities::Entity>::Element<Entities::Entity>* pAux = entityList.getHead()->getNext();
			while(pAux != NULL)
			{
				entityList.getHead()->setNext(pAux->getNext());

				Entities::MovingEntities::Player* pAuxPlayer = dynamic_cast<Entities::MovingEntities::Player*>(pAux->getData());
				if(pAuxPlayer == NULL)
					delete pAux;
				else
				{
					pAux->setNext(NULL);
					pAux->setPrev(NULL);
				}

				pAux = entityList.getHead()->getNext();
			}
			Entities::MovingEntities::Player* pAuxPlayer = dynamic_cast<Entities::MovingEntities::Player*>(entityList.getHead()->getData());
			if(pAuxPlayer == NULL)
				delete entityList.getHead();
			else
			{
				entityList.getHead()->setNext(NULL);
				entityList.getHead()->setPrev(NULL);
				entityList.getHead()->setData(NULL);
			}
		}
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
			if(iterator->getData()->getExecutable())
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
			if(iterator->getData()->getExecutable())
				iterator->getData()->draw();
			iterator = iterator->getNext();
		}
	}

}// namespace Lists