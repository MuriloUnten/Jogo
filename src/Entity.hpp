#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Being.hpp"
#include "Id.hpp"
#include <vector>

#define GRAVITY 1000

class GraphicsManager;

namespace Entities
{

	class Entity : public Being
	{
	protected:

		sf::Vector2f vel;
		sf::Vector2f acc;
		bool executable;
		ID Id;

	public:
		Entity(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
		Entity();
		~Entity();

		const int getId() const;

		virtual void execute() = 0;
		void update();

		void setVel(sf::Vector2f velocity);
        sf::Vector2f getVel() const;

		void setAcc(sf::Vector2f newAcc);
		sf::Vector2f getAcc() const;

		void setExecutable(const bool newExecutable);
		const bool getExecutable() const;

	};
}// namespace Entities