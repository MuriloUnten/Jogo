#pragma once
#define ARROW_VELOCITYX 1000.0f

#include "Projectile.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Arrow : public Projectile
        {
        private:

        public:
            Arrow(sf::Vector2f size=sf::Vector2f(20.0f, 5.0f), sf::Vector2f position=sf::Vector2f(0.0f, 0.0f), int newdamage=1);
            ~Arrow();

            void execute();

        };

    }//namespace MovingEntities 
}//namespace Entities