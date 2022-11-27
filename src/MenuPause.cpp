#include "MenuPause.hpp"
#define MENU_PATH "../assets/Menu/PrincipalMenu.png"

namespace Menu
{
    MenuPause::MenuPause( Game* game)
    {
        setInstance();
        pGame = game;
        Button *bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 300));
        bt->setMessage("PLAY");
        bt->select(true);
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 80));
        bt->setMessage("EXIT");
        buttonList.pushElement(bt);

        selected = buttonList.getHead();

    }
    MenuPause::~MenuPause()
    {
        pGame =  NULL;
    }

    void MenuPause::update()
    {
         active = true;
    }

    void MenuPause::draw()
    {
        if(pGraphics->isWindowOpen())
            pGraphics->getWindow()->draw(*hitBox);
        
        for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
            it->getData()->draw();
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
            //pGame->ContinuePlay();
            break;
        
        case 1:
            //pGame->DeleteLevel();
            //pGame->GoMainMenu();
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