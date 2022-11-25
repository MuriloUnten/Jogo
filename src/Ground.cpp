#include "Ground.hpp"

namespace Entities{
    namespace StaticEntities{
        
        Ground::Ground(const std::string fileName, sf::Vector2f size, sf::Vector2f position):
        Obstacle(Eground,fileName, size, position)
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


        void Ground::affectPlayer(MovingEntities::Player* player)
        {

        }

    }//namespace StaticEntities
}//namespace Entities