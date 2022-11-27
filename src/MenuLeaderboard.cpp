#include "MenuLeaderboard.hpp"
#include "Game.hpp"

#define LEADERBOARD_TXT_PATH "../assets/Saves/Leaderboard.txt"

namespace Menu
{
    MenuLeaderboard::MenuLeaderboard(Game* game, std::string fileName, sf::Vector2f size, sf::Vector2f position):
    Menu(stateID::leaderboard, fileName, size, position)
    {
        setInstance();
        active = true;
        pGame =  game;
        Button* bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 200));
        bt->setMessage("EXIT");
        bt->select(true);
        buttonList.pushElement(bt);
        selected = buttonList.getHead();

        loadData();
    }

    MenuLeaderboard::~MenuLeaderboard()
    {
        pGame = NULL;
    }

    void MenuLeaderboard::loadData()
    {
        std::ifstream leaderboardData(LEADERBOARD_TXT_PATH, std::ios::in);
        if (!leaderboard) 
        {
        std::cout << "Cant Open txt on Load Map" << std::endl;
        exit(100);
        }

        if (leaderboardData.is_open())
        {
            std::string name;
            std::string pontuation;
            sf::Text* text = NULL;

            text = new sf::Text;
            text->setString("TOP 10");
            text->setFont(*pGraphics->getFont());
            text->setCharacterSize(50);
            sf::FloatRect textRect = text->getLocalBounds();
            text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            text->setPosition(sf::Vector2f(pos.x + hitBox->getSize().x/2, 90));
            text->setOutlineColor(sf::Color::Black);
            text->setOutlineThickness(4);

            int amount = 0;

            while (getline(leaderboardData, name) && getline(leaderboardData, pontuation) && amount < 10)
            {
                text = new sf::Text;
                text->setString(name + ": " + pontuation);
                text->setFont(*pGraphics->getFont());
                text->setPosition({ WIDTH / 2 - 200, 100.0f + (amount * 50.0f)});
                ranking.push_back(text);
                amount++;
            }
	    }

	    leaderboardData.close();

    }

    void MenuLeaderboard::draw()
    {
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
    
            //draw button 
            for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
            {
                it->getData()->draw();
            }
            //draw Text
            for(std::list<sf::Text*>::iterator it = ranking.begin(); it != ranking.end(); it++)
            {
                pGraphics->getWindow()->draw(**it);
            }
        }


    }
    void MenuLeaderboard::execute()
    {
        draw();
    }
    void MenuLeaderboard::pushButton()
    {
        switch (hoveredButton)
        {
        case -1:
            break;

        case 0:
            changeState(stateID::mainMenu);
            active = false;
            break;
        }
    }

    void MenuLeaderboard::resetState()
    {
        active = true;
        selected->getData()->select(false);
        hoveredButton = 0;
        selected = buttonList.getHead();
        selected->getData()->select(true);
    }

}//namespace Menu