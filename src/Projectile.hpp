#pragma once

#include "MovingEntity.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        class Projectile : public MovingEntity
        {
        protected:
            //boleano para checar se o projetil vai ser desenhado
            bool discard;

        public:
            Projectile(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1);
            Projectile();
            ~Projectile();

            void shoot(sf::Vector2f newPos, sf::Vector2f newVel);

            bool getDiscard();
            void setDiscard(bool condition);

            virtual void execute()=0;

        };
    }// namespace MovingEntities
}//namespace Entities#pragma once


    
