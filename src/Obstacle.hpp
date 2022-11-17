#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        class Obstacle : public Entity
        {
        protected:
            int slow;
            bool Odamage; // Q isso????
            float buoyancy;

        public:
            Obstacle(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f), int newSlow=0);
            Obstacle();
            ~Obstacle();

            const bool getDamage();
            
            void setSlow(const int newSlow);
            const int getSlow() const;

            void execute();
        };

    }// namespace StaticEntities
}// namespace Entities