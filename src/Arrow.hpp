#pragma once
#define ARROW_VELOCITYX 350

#include "Projectile.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Arrow : public Projectile
        {
        private:

        public:
            Arrow(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1);
            Arrow();
            ~Arrow();

            void execute();

        };

    }//namespace MovingEntities 
}//namespace Entities