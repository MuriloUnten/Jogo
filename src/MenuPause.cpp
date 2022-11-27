#include "MenuPause.hpp"
#include "Game.hpp"

#define MENU_PATH "../assets/Menu/PrincipalMenu.png"

namespace Menu
{
    MenuPause::MenuPause(Game* pG, std::string fileName, sf::Vector2f size , sf::Vector2f position):
    Menu(stateID::pause, fileName, size, position)
    {
        active = false;
        pGame = pG;

        gamePaused.setString("GAME PAUSED");
        gamePaused.setFont(*pGraphics->getFont());
        gamePaused.setCharacterSize(50);
        sf::FloatRect textRect = gamePaused.getLocalBounds();
        gamePaused.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        gamePaused.setPosition(sf::Vector2f(pos.x + hitBox->getSize().x/2, 90.0f));
        gamePaused.setOutlineColor(sf::Color::Black);
        gamePaused.setOutlineThickness(4);

        Button *bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 280.0f));
        bt->setMessage("RESUME");
        bt->select(true);
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 360.0f));
        bt->setMessage("EXIT");
        buttonList.pushElement(bt);

        selected = buttonList.getHead();
    }


    MenuPause::~MenuPause()
    {
        pGame =  NULL;
    }


    void MenuPause::draw()
    {
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
            drawButtons();
        }
    }


    void MenuPause::execute()
    {
        draw();
    }


    void MenuPause::pushButton()
    {
        switch (hoveredButton)
        {
        case -1:
            break;

        case 0:
            changeState(stateID::level);
            active = false;
            break;
        
        case 1:
            pGame->getpLevel()->setLvlEnded(true);
            changeState(stateID::mainMenu);
            active = false;
            break;

        }
    }


    void MenuPause::resetState()
    {
        active = true;
        selected->getData()->select(false);
        hoveredButton = 0;
        selected = buttonList.getHead();
        selected->getData()->select(true);
    }
}//namespace Menu