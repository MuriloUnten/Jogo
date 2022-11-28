#include "MenuEndLevel.hpp"
#include "Game.hpp"

namespace Menu
{
    MenuEndLevel::MenuEndLevel(Game* game, std::string filenameP , sf::Vector2f size, sf::Vector2f position):
    Menu(stateID::menuEndLevel ,filenameP, size, position)
    {
        setInstance();
        pGame = game;

        //mensagem para sinalizar o que o player deve escrever
        message.setString("YOU WON!");
        message.setFont(*pGraphics->getFont());
        message.setCharacterSize(36);
        sf::FloatRect textRect = message.getLocalBounds();
        message.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        message.setPosition(sf::Vector2f(pos.x + hitBox->getSize().x/2, 90));
        message.setOutlineColor(sf::Color::Black);
        message.setOutlineThickness(4);

    }

    MenuEndLevel::~MenuEndLevel()
    {
        pGame = NULL;
    }

    void MenuEndLevel::saveData()
    {

    }
        
    void MenuEndLevel::draw()
    {
       if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
    
            //draw button 
            for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
            {
                it->getData()->draw();
                std::cout << it->getData();
            }
            //draw Text
            pGraphics->getWindow()->draw(message);
        }
    }

    void MenuEndLevel::execute()
    {
        active = true;
        draw();
       //TODO setar nome do Player
    }

    void MenuEndLevel::pushButton()
    {
        if(pGame->getCurrentLevel() == 1)
        {
            switch (hoveredButton)
            {
            case -1:
                break;

            case 0:
                pGame->setCurrentLevel(2);
                pGame->getpLevel()->setCurrentLevel(LEVEL2);
                changeState(stateID::level);
                active = false;
                break;
            case 1:
                changeState(stateID::mainMenu);
                active = false;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (hoveredButton)
            {
            case -1:
                break;

            case 0:
                changeState(stateID::mainMenu);
                active = false;
                break;
            default:
                break;
            }
        }
    }

    void MenuEndLevel::resetState()
    {
        createEndLevelMenu();

        hoveredButton = 0;
        selected = buttonList.getHead();
        selected->getData()->select(true);
        std::cout << "menu reset\n";
    }


    void MenuEndLevel::createEndLevelMenu()
    {
        buttonList.clear();

        Button* bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;

        /* Allows for playing the second level only if the first level is won */
        if(pGame->getCurrentLevel() == 1)
        {
            bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 280));
            bt->setMessage("PLAY NEXT LEVEL");
            bt->select(false);
            buttonList.pushElement(bt);
        }

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 360));
        bt->setMessage("EXIT");
        bt->select(false);
        buttonList.pushElement(bt);


        selected = buttonList.getHead();
        std::cout << "EndLevelMenu recreated\n";
    }

}//namePspace Menu
