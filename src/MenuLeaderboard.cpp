#include "MenuLeaderboard.hpp"
#include "Game.hpp"

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
        
        sf::Text* text;
        for (int i = 0; i < 10; i++) {
            text = new sf::Text();

            text->setFont(*pGraphics->getFont());
            text->setCharacterSize(TEXT_SIZE);
            text->setFillColor(sf::Color::White);

            ranking.pushElement(text);
        }

        
        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 200));
        bt->setMessage("EXIT");
        bt->select(true);
        buttonList.pushElement(bt);
        selected = buttonList.getHead();
    }

    MenuLeaderboard::~MenuLeaderboard()
    {
        pGame = NULL;
    }

    void MenuLeaderboard::draw()
    {
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
        }
            
        for(Lists::List<sf::Text>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
        {
            // std::cout << "dentro do loop\n";
            it->getData()->draw();
        }

        for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
        {
            // std::cout << "dentro do loop\n";
            it->getData()->draw();
        }

    }
    void MenuLeaderboard::execute()
    {

    }
    void MenuLeaderboard::pushButton()
    {

    }

    void MenuLeaderboard::resetState()
    {

    }

}//namespace Menu