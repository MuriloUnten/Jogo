#pragma once

#include "Entity.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class MovingEntity: public Entity
        {
        protected:
            // True if facing right, false if facing left.
            bool facingRight;
            
            int damage; // Talvez damage deve ser atributo de Entity


        public:
            MovingEntity(ID id, const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1);
            MovingEntity();
            virtual ~MovingEntity();

            const int getDamage() const;

            void setFacingRight(const bool isFacingRight);
            const bool getFacingRight() const;

            void flipImage();

            virtual void execute() = 0;

            virtual void affectPlayer(MovingEntities::Player* player) = 0;
        };

    }// namespace MovingEntities
}// namespace Entities