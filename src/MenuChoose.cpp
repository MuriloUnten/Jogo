#include "MenuChoose.hpp"
#include "Game.hpp"

#define MENU_PATH "../assets/Menu/PrincipalMenu.png"

namespace Menu
{
    MenuChoose::MenuChoose(Game* game, std::string fileName, sf::Vector2f size , sf::Vector2f position):
    Menu(stateID::menuChoosePlayers, fileName, size, position)
    {
        setInstance();
        pGame = game;
        active = false;


        Button* bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 200));
        bt->setMessage("ONE PLAYER");
        bt->select(true);
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 280));
        bt->setMessage("TWO PLAYERS");
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 360));
        bt->setMessage("EXIT");
        buttonList.pushElement(bt);

        selected = buttonList.getHead();
    }

    MenuChoose::~MenuChoose()
    {
        pGame = NULL;
    }

    void MenuChoose::draw()
    {
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
        }
            

        for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
        {
            it->getData()->draw();
        }
    }

    void MenuChoose::execute()
    {
        active = true;
        draw();
    }

    void MenuChoose::pushButton()
    {
        switch (hoveredButton)
        {
        case -1:
            break;

        case 0:
            pGame->getpLevel()->SetTwoPlayers(false);
            changeState(stateID::level);
            active = false;
            break;
        
        case 1:
            pGame->getpLevel()->SetTwoPlayers(true);
            changeState(stateID::level);
            active = false;
            break;
        case 2:
            changeState(stateID::mainMenu);
            active = false;
            break;
        }
    }

    void MenuChoose::resetState()
    {
        selected->getData()->select(false);
        hoveredButton = 0;
        selected = buttonList.getHead();
        selected->getData()->select(true);
    }

}//namespace Menu