#pragma once

#include <SFML/Graphics.hpp>
#include "EntityList.hpp"

class GraphicsManager
{
private:
	sf::RenderWindow* window;

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

    void draw(EntityList entities);
};