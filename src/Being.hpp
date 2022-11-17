#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraphicsManager.hpp"


class Being
{
protected:
	static Managers::GraphicsManager* pGraphics;
	sf::Vector2f pos;
	sf::RectangleShape* hitBox;
	sf::Texture* texture;

public:
	Being(std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0));
	Being();
	~Being();

	void setPos(const sf::Vector2f position);
	sf::Vector2f getPos() const;

	void setSize(const sf::Vector2f size);
	sf::Vector2f getSize() const;

	void loadTexture(const std::string fileName);
	sf::Texture* getTexture() const;
	
	sf::RectangleShape* getHitBox() const;

	static void setInstance();
	
	virtual void draw();
	virtual void execute() = 0;
};