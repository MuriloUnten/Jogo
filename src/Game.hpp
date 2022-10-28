#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"
#include "Entity.hpp"
#include "EntityList.hpp"

class Game
{
private:
	GraphicsManager* graphics;
	EntityList entityList;

	// Temporary staticly created entities
	Entity background;
	Entity mario;

public:
	Game();
	~Game();

	void execute();
};
