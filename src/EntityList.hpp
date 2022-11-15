#pragma once

#include <SFML/Graphics.hpp>
#include "List.hpp"
#include "Entity.hpp"


namespace Lists
{

	class EntityList
	{
	private:
		List<Entities::Entity> entityList;

	public:
		EntityList();
		~EntityList();

		void pushEntity(Entities::Entity* entity);
		void clear();
		List<Entities::Entity>& getList();
		Entities::Entity* removeEntity(int index);
		const unsigned int getSize() const;

		void execute();
		void draw();
	};
}// namespace Lists