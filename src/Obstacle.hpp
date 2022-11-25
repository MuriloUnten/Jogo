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

        public:
            Obstacle(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
            Obstacle();
            ~Obstacle();

            const bool getBoolDamage();

            

            void execute();
            virtual void affectPlayer(MovingEntities::Player* player) = 0;
        };

    }// namespace StaticEntities
}// namespace Entities