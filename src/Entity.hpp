#pragma once

#include <SFML/Graphics.hpp>
#include "Arquetype.hpp"

class Entity : public Arquetype
{
protected:
	sf::Vector2f pos;
	sf::RectangleShape* hitBox;
	sf::Texture* texture;

public:
	Entity(const std::string fileName, sf::Vector2f size,
		sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
	Entity();
	~Entity();
	virtual void execute();

	void setPos(sf::Vector2f position);
	sf::Vector2f getPos();

	void setSize(sf::Vector2f size);
	sf::Vector2f getSize();

	bool loadTexture(const std::string fileName);

	sf::RectangleShape* getHitBox();


	//virtual void draw();
};