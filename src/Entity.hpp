#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Being.hpp"
#include <vector>

#define GRAVITY 1000

class GraphicsManager;

namespace Entities
{
	class Entity : public Being
	{
	protected:


	public:
		Entity(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
		Entity();
		~Entity();

		virtual void execute() = 0;
	};
}// namespace Entities