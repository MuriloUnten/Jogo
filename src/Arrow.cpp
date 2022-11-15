#include "Arrow.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        Arrow::Arrow(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1):
        MovingEntity(fileName, size, position)
        {

        }
        Arrow::Arrow():
        MovingEntity()
        {

        }

        Arrow::~Arrow()
        {

        }

        void Arrow::execute()
        {
            
        }
    }
}