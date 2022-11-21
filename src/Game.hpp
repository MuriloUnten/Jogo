#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"
#include "EventsManager.hpp"
#include "FirstLevel.hpp"
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
	Managers::EventsManager* events;

	Levels::FirstLevel firstLevel;

public:
	Game();
	~Game();

	void execute();
};
