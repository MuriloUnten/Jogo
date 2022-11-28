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
#include "MenuGameOver.hpp"
#include "MenuPause.hpp"
#include "MenuLeaderboard.hpp"
#include "MenuChoose.hpp"


class Game
{
	
private:
	/* Managers */
	Managers::GraphicsManager* graphics;
	Managers::EventsManager* events;
	Managers::StateManager* states;

	/* States*/
	Levels::Level* pLevel;
	Menu::MainMenu* mainMenu;
	Menu::MenuGameOver* gameOverMenu;
	Menu::MenuPause* pauseMenu;
	Menu::MenuLeaderboard* leaderboardMenu;
	Menu::MenuChoose* chooseMenu;

	int currentLevel;

public:
	Game();
	~Game();

	void execute();
	
	void createLevel();
    Levels::Level* getpLevel() const;
    void setLevel(Levels::Level* pLevel);
	void setCurrentLevel(int num);
    int getCurrentLevel() const;

	void newGame();
    void endGame();
    void deleteLevel();
    void resetPlayers();
    void setLvlEnded(bool x);
};
