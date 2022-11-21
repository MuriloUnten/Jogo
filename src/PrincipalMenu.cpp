#include "PrincipalMenu.hpp"
#include "Game.hpp"

//#define MENU_PATH "../assets/Menu/ButtonDissected"
namespace Menu
{
    PrincipalMenu::PrincipalMenu(Game* pG, std::string fileName, sf::Vector2f position , sf::Vector2f size):
    Menu(fileName, position, size)
    {
        pGame =  pG;
        Button* bt = NULL;

        bt = new Button(MENU_PATH, sf::Vector2f(WIDTH/2 , HEIGHT/2));
        bt->setMessage("LEVEL 1");
        bt->select(true);
        vectorOfButtons.push_back(bt);

        bt = new Button(MENU_PATH, sf::Vector2f(WIDTH/2 , HEIGHT/2 + 80));
        bt->setMessage("LEVEL 2");
        vectorOfButtons.push_back(bt);

        bt = new Button(MENU_PATH, sf::Vector2f(WIDTH/2 , HEIGHT/2 + 160));
        bt->setMessage("LOAD GAME");
        vectorOfButtons.push_back(bt);

        bt = new Button(MENU_PATH, sf::Vector2f(WIDTH/2 , HEIGHT/2 + 240));
        bt->setMessage("LEADERBOARD");
        vectorOfButtons.push_back(bt);

        bt = new Button(MENU_PATH, sf::Vector2f(WIDTH/2 , HEIGHT/2 + 320));
        bt->setMessage("QUIT GAME");
        vectorOfButtons.push_back(bt);

        max = 4;
    }

    PrincipalMenu::~PrincipalMenu()
    {

    }

    void PrincipalMenu::update()
    {
        active = true;
    }

    void PrincipalMenu::render()
    {
        updateView();
        for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        {
            (*it)->render();
        }
    }

    void PrincipalMenu::execute()
    {
        if (active) {
            active = false;
            switch (selected) {
            case 0:
                /*pGame->setCurrentLevel(1);
                changeState(stateID::newGame);
                break;*/
            case 1:
                /*
                pGame->setCurrentLevel(2);
                changeState(stateID::newGame);
                break;
                */
            case 2:
            /*
                changeState(stateID::loadGame);
                break;
            */
            case 3:
                /*
                changeState(stateID::leaderboard);
                break;
                */
            case 4:
            /*
                pGame->endGame();
                break;

                */
            default:
                break;
            }
    }
    }

}//namespace Menu
