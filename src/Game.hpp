#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include "FirstLevel.hpp"
#include "SecondLevel.hpp"
#include "GraphicsManager.hpp"
#include "EntityList.hpp"
#include "Being.hpp"
#include "Entity.hpp"
#include "Character.hpp"
#include "Player.hpp"

class Game
{
private:
	Entities::MovingEntities::Player player;
	Managers::GraphicsManager* graphics;
	//Levels::FirstLevel firstLevel;
	Levels::SecondLevel secondLevel;
public:
	Game();
	~Game();

	void execute();
};
