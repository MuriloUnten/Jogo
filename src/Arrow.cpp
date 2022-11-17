#include "Arrow.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Arrow::Arrow(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage):
        Projectile(fileName, size, position)
        {

        }


        Arrow::Arrow():
        Projectile()
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