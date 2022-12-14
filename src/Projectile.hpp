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
            Projectile(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1);
            Projectile();
            virtual ~Projectile();

            void shoot(sf::Vector2f newPos, sf::Vector2f newVel);
            
            virtual void execute()=0;

            virtual void affectPlayer(MovingEntities::Player* player) = 0;
        };
    }// namespace MovingEntities
}//namespace Entities#pragma once