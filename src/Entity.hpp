#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Being.hpp"
#include "Id.hpp"

#define GRAVITY 1000

class GraphicsManager;

namespace Entities
{
	namespace MovingEntities
	{
		class Player;
	}

	class Entity : public Being
	{
	protected:

		sf::Vector2f vel;
		sf::Vector2f acc;
		bool executable;
		ID Id;

		static Entities::MovingEntities::Player* pPlayer1;

	public:
		Entity(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));
		Entity();
		~Entity();

		ID getId() const;

		virtual void execute() = 0;
		void update();

		void setVel(sf::Vector2f velocity);
        sf::Vector2f getVel() const;

		void setAcc(sf::Vector2f newAcc);
		sf::Vector2f getAcc() const;

		void setExecutable(const bool newExecutable);
		const bool getExecutable() const;

		static void setPlayer1(MovingEntities::Player* newPlayer);

		virtual void affectPlayer(MovingEntities::Player* player) = 0;

	};
}// namespace Entities