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
            bool Odamage;

        public:
            Obstacle(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f), int newSlow=0);
            Obstacle();
            ~Obstacle();

            void setSlow(const int newSlow);
            const int getSlow() const;

            virtual void execute() = 0;
        };

    }// namespace StaticEntities
}// namespace Entities