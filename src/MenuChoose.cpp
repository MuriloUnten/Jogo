#include "MenuChoose.hpp"


#define MENU_PATH "../assets/Menu/PrincipalMenu.png"

namespace Menu
{
    MenuChoose::MenuChoose(Levels::Level* level, std::string fileName, sf::Vector2f size , sf::Vector2f position):
    Menu(stateID::menuChoosePlayers, fileName, size, position)
    {
        setInstance();
        active = true;
        pLevel = level;
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
    }

    MenuChoose::~MenuChoose()
    {
        pLevel = NULL;
    }

    void MenuChoose::draw()
    {
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
        }
            

        for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
        {
            // std::cout << "dentro do loop\n";
            it->getData()->draw();
        }
    }

    void MenuChoose::execute()
    {
        draw();
    }

    void MenuChoose::pushButton()
    {
        switch (hoveredButton)
        {
        case -1:
            break;

        case 0:
            pLevel->SetTwoPlayers(false);
            active = false;
            break;
        
        case 1:
            pLevel->SetTwoPlayers(true);
            active = false;
            break;
        }
    }

    void MenuChoose::resetState()
    {
        active = true;
        selected->getData()->select(false);
        hoveredButton = 0;
        selected->getData()->select(true);

    }

}//namespace Menu