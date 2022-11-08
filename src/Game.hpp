#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include "FirstLevel.hpp"
#include "GraphicsManager.hpp"
#include "EntityList.hpp"
#include "Entity.hpp"
#include "Character.hpp"
#include "Player.hpp"

class Game
{
private:
	Managers::GraphicsManager* graphics;
	Levels::FirstLevel firstLevel;
	Entities::MovingEntities::Player player;

public:
	Game();
	~Game();

	void execute();
};
