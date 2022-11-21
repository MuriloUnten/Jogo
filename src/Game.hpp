#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "GraphicsManager.hpp"
#include "EntityList.hpp"
#include "Being.hpp"
#include "Entity.hpp"
#include "Character.hpp"
#include "Player.hpp"
#include "PrincipalMenu.hpp"

class Game
{
private:

	//Entities::MovingEntities::Player player;
	Managers::GraphicsManager* graphics;

	//Levels::FirstLevel firstLevel;
	Levels::Level* pLevel;
	int currentLevel;
	
    Entities::MovingEntities::Player* player1;
	Entities::MovingEntities::Player* player2;

	Menu::PrincipalMenu* principalMenu;

	bool lvlEnded;

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
