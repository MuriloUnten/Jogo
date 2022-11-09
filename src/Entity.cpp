#include "Entity.hpp"
#include "GraphicsManager.hpp"

namespace Entities
{

	Entity::Entity(const std::string fileName, sf::Vector2f size, sf::Vector2f position):
	Being(fileName, size, position)
	{
		
	}


	Entity::Entity():
	Being()
	{

	}


	Entity::~Entity()
	{

	}


}// namespace Entities