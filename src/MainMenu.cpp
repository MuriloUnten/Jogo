#include "MainMenu.hpp"
#include "Game.hpp"

namespace Menu
{
    MainMenu::MainMenu(Game* pG, std::string fileName, sf::Vector2f size , sf::Vector2f position):
    Menu(stateID::mainMenu, fileName, size, position)
    {
        setInstance();
        active = true;
        pGame =  pG;
        Button* bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;
        
        
        nameGame.setString("FOREST++");
        nameGame.setFont(*pGraphics->getFont());
        nameGame.setCharacterSize(50);
        sf::FloatRect textRect = nameGame.getLocalBounds();
        nameGame.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        nameGame.setPosition(sf::Vector2f(pos.x + hitBox->getSize().x/2, 50));
        nameGame.setOutlineColor(sf::Color::Black);
        nameGame.setOutlineThickness(4);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 200));
        bt->setMessage("LEVEL 1");
        bt->select(true);
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 280));
        bt->setMessage("LEVEL 2");
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 360));
        bt->setMessage("LOAD GAME");
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 440));
        bt->setMessage("LEADERBOARD");
        buttonList.pushElement(bt);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 620));
        bt->setMessage("QUIT GAME");
        buttonList.pushElement(bt);

        selected = buttonList.getHead();
    }

    MainMenu::~MainMenu()
    {
        pGame = NULL;
    }


    void MainMenu::draw()
    {
        // updateView(); PRA QUE O UPDATEVIEW()????
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
            pGraphics->getWindow()->draw(nameGame);
        }
            

        for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
        {
            // std::cout << "dentro do loop\n";
            it->getData()->draw();
        }
    }


    void MainMenu::execute()
    {
        draw();
    }


    void MainMenu::pushButton()
    {
        switch (hoveredButton)
        {
        case -1:
            break;

        case 0:
            // pGame->setCurrentLevel(1);
            pGame->getpLevel()->setCurrentLevel(LEVEL1);
            pStateManager->changeState(stateID::level);
            active = false;
            break;

        case 1:
            // pGame->setCurrentLevel(2);
            pGame->getpLevel()->setCurrentLevel(LEVEL2);
            pStateManager->changeState(stateID::level);
            active = false;
            break;

        case 2:
            // pGame->loadGame();
            break;
        
        case 3:
            // pGame->showLeaderBoard();
            break;
        
        case 4:
            pGame->endGame();
            break;
        }
    }


    void MainMenu::resetState()
    {
        active = true;
        selected->getData()->select(false);
        hoveredButton = 0;
        selected->getData()->select(true);
    }

}//namespace Menu
