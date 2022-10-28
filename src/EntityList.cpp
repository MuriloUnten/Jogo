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


void EntityList::removeEntity(int index)
{
	List<Entity>::Element<Entity>* pAux = entityList.getHead();
	while (pAux != NULL)
	{
		if (pAux->getData()->getId() == index)
		{
			if (pAux->getPrev() != NULL)
			{
				pAux->getPrev()->setNext(pAux->getNext());
			}
			if (pAux->getNext() != NULL)
			{
				pAux->getNext()->setPrev(pAux->getPrev());
			}

			List<Entity>::Element<Entity>* pAux2 = pAux->getNext();
			delete pAux;
			pAux = pAux2;
		}
	}
}