#include "Arrow.hpp"

#define ARROW_PATH "../assets/inimigos/flecha.png"

namespace Entities
{
    namespace MovingEntities
    {
        Arrow::Arrow(sf::Vector2f size, sf::Vector2f position, int newdamage):
        Projectile(Earrow, ARROW_PATH, size, position)
        {

        }


        Arrow::~Arrow()
        {

        }


        void Arrow::execute()
        {
            update();
        }
    }// namespace MovingEntities
}// namespace Entities