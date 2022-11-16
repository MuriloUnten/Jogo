#include "Ground.hpp"

namespace Entities{
    namespace StaticEntities{
        
        Ground::Ground(const std::string fileName, sf::Vector2f size, sf::Vector2f position):
        Obstacle(fileName, size, position)
        {
            Odamage = false;
        }

        Ground::Ground():
        Obstacle()
        {

        }

        Ground::~Ground()
        {
            
        }

        void Ground::execute()
        {

        }

    }//namespace StaticEntities
}//namespace Entities