#include "FirstLevel.hpp"

#define NARUTO_PATH "../assets/personagem/naruto.png"


namespace Levels
{
    FirstLevel::FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Level(fileName, size, position, player)
    {
        pPlayer->loadTexture(NARUTO_PATH);
        pPlayer->getHitBox()->setSize(sf::Vector2f(100, 100));
        pPlayer->getHitBox()->setPosition(sf::Vector2f(0, 0));
        pPlayer->getHitBox()->setTexture(pPlayer->getTexture());
    }


    FirstLevel::~FirstLevel()
    {

    }

}// namespace Levels