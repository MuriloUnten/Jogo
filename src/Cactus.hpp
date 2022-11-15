#pragma once

#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        class Cactus : public Obstacle
        {
        protected:    
            int damage;

        public:
            Cactus(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f), int newDamage=50);
            Cactus();
            ~Cactus();
            
            void setDamage(const int newDamage);
            const int getDamage() const;

            void execute();
        };

    }// namespace StaticEntities
}// namespace Entities

