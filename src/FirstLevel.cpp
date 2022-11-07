#include "FirstLevel.hpp"

#define NARUTO_PATH "../assets/personagem/naruto.png"


namespace Levels
{
    FirstLevel::FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position):
    Level(fileName, size, position)
    {
        player.loadTexture(NARUTO_PATH);
        player.getHitBox()->setSize(sf::Vector2f(100, 100));
        player.getHitBox()->setPosition(sf::Vector2f(0, 0));
        player.getHitBox()->setTexture(player.getTexture());
    }


    FirstLevel::~FirstLevel()
    {

    }

}// namespace Levels