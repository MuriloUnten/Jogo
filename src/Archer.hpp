#pragma once

#include "Enemy.hpp"
#include "Arrow.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Archer : public Enemy
        {

            private:
                Arrow* pArrow;
                float attacktime;

            public:
                Archer(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=1);
                Archer();
                ~Archer();

                void execute();
                Arrow* shoot();

        };
    }//namespace MovingEntities
}//namespace Entities