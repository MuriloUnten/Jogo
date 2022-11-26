#pragma once


#define LEVEL1 "FirstLevel.txt"
#define LEVEL2 "SecondLevel.txt"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "GraphicsManager.hpp"
#include "EventsManager.hpp"
#include "StateManager.hpp"
#include "EntityList.hpp"
#include "Being.hpp"
#include "Entity.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "MainMenu.hpp"

class Game
{
	
private:

	//Entities::MovingEntities::Player player;
	Managers::GraphicsManager* graphics;
	Managers::EventsManager* events;
	Managers::StateManager* states;

    // Entities::MovingEntities::Player* player1;
	// Entities::MovingEntities::Player* player2;

	//Levels::FirstLevel firstLevel;
	Levels::Level* pLevel;
	
	Menu::MainMenu* mainMenu;
	
	int currentLevel;

public:
	Game();
	~Game();

	void execute();

    Levels::Level* getpLevel() const;
    void setLevel(Levels::Level* pLevel);
	void setCurrentLevel(int num);
    int getCurrentLevel() const;   

    Entities::MovingEntities::Player* getPlayer1();
    Entities::MovingEntities::Player* getPlayer2();
	bool isTwoPlayersActive() const;
    bool isPlaying() const;  

	void newGame();
    void endGame();
    void deleteLevel();
    void resetPlayers();
    void setLvlEnded(bool x);
};
