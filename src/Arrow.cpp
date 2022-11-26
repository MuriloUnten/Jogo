#include "Arrow.hpp"
#include "Player.hpp"


#define ARROW_PATH "../assets/inimigos/flechaBranca.png"

namespace Entities
{
    namespace MovingEntities
    {
        Arrow::Arrow(sf::Vector2f size, sf::Vector2f position, int newdamage):
        Projectile(Earrow, ARROW_PATH, size, position)
        {
            damage = newdamage;
        }


        Arrow::~Arrow()
        {

        }


        void Arrow::execute()
        {
            update();
        }


        void Arrow::affectPlayer(MovingEntities::Player* player)
        {
            player->takeDamage(damage);
        }
    }// namespace MovingEntities
}// namespace Entities