#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Arquetype.hpp"

#define GRAVITY 1000

namespace Entities
{
	class Entity : public Arquetype
	{
	protected:
		sf::Vector2f pos;
		sf::RectangleShape* hitBox;
		sf::Texture* texture;

	public:
		Entity(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
		Entity();
		~Entity();
		virtual void execute();

		void setPos(const sf::Vector2f position);
		sf::Vector2f getPos() const;

		void setSize(const sf::Vector2f size);
		sf::Vector2f getSize() const;

		void loadTexture(const std::string fileName);

		sf::RectangleShape* getHitBox() const;

		//virtual void draw();
	};
}// namespace Entities