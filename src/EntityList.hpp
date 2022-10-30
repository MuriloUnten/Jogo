#pragma once


#include <SFML/Graphics.hpp>
#include "List.hpp"

class Entity;

namespace Lists
{

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
}// namespace Lists