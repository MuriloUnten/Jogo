#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Being.hpp"
#include <vector>

#define GRAVITY 2000
#define TIMECOLLISON 0.3

class GraphicsManager;

namespace Entities
{
	class Entity : public Being
	{
	protected:
		sf::Vector2f vel;
		sf::Vector2f acc;
		float timeCollision;

	public:
		Entity(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
		Entity();
		~Entity();

		virtual void execute() = 0;
		void update();

		void setVel(sf::Vector2f velocity);
        sf::Vector2f getVel() const;

		void setAcc(sf::Vector2f newAcc);
		sf::Vector2f getAcc();

		void setTimeCollision(float time);
		float getTimeCollision() const;

		float getDT() const;
	};
}// namespace Entities