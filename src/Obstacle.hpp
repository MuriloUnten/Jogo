#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        class Obstacle : public Entity
        {
        protected:

            bool Odamage;
            float buoyancy;
            float slow;

        public:
            Obstacle(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f), float newSlow = 0.0f);
            Obstacle();
            ~Obstacle();

            const bool getDamage();

            void setSlow( const float newSlow);
            const float getSlow() const;

            void execute();
        };

    }// namespace StaticEntities
}// namespace Entities