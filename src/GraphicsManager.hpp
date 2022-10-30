#pragma once

#include <SFML/Graphics.hpp>
#include "EntityList.hpp"

class GraphicsManager
{
private:
	sf::RenderWindow* window;

	/* Singleton Design pattern */
	static GraphicsManager* instance;
	GraphicsManager();

public:
	~GraphicsManager();

	static GraphicsManager* getInstance();

	bool isWindowOpen();
	void clear();
	void close();
	void display();
	sf::RenderWindow* getWindow();
	void draw(sf::RectangleShape* rect);
    void draw(Lists::EntityList entities);
};