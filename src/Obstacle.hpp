#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        class Obstacle : public Entity
        {
        protected:
            int damage;
            int slow;

        public:
            Obstacle(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f), int newDamage=0, int newSlow=0);
            Obstacle();
            ~Obstacle();

            void setDamage(const int newDamage);
            const int getDamage() const;

            void setSlow(const int newSlow);
            const int getSlow() const;

            void execute();
        };

    }// namespace StaticEntities
}// namespace Entities