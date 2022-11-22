#include "MainMenu.hpp"
#include "Game.hpp"

//#define MENU_PATH "../assets/Menu/ButtonDissected"
namespace Menu
{
    MainMenu::MainMenu(Game* pG, std::string fileName, sf::Vector2f size , sf::Vector2f position):
    Menu(fileName, size, position)
    {
        pGame =  pG;
        Button* bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;


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

    }

    void MainMenu::update()
    {
        active = true;
    }

    void MainMenu::draw()
    {
        // updateView(); PRA QUE O UPDATEVIEW()????
        if(pGraphics->isWindowOpen())
            pGraphics->getWindow()->draw(*hitBox);

        for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
        {
            // std::cout << "dentro do loop\n";
            it->getData()->draw();
        }
    }


    void MainMenu::execute()
    {
        draw();
    //     if (active) {
    //         active = false;
    //         switch (selected) {
    //         case 0:
    //             /*pGame->setCurrentLevel(1);
    //             changeState(stateID::newGame);
    //             break;*/
    //         case 1:
    //             /*
    //             pGame->setCurrentLevel(2);
    //             changeState(stateID::newGame);
    //             break;
    //             */
    //         case 2:
    //         /*
    //             changeState(stateID::loadGame);
    //             break;
    //         */
    //         case 3:
    //             /*
    //             changeState(stateID::leaderboard);
    //             break;
    //             */
    //         case 4:
    //         /*
    //             pGame->endGame();
    //             break;

    //             */
    //         default:
    //             break;
    //         }
    // }
    }

}//namespace Menu
