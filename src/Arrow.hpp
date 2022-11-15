#pragma once

#include "MovingEntity.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Arrow : public MovingEntity
        {
        private:
            //checar se colidiu com o chão
            bool discard;

        public:
            Arrow(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1);
            Arrow();
            ~Arrow();

            void execute();

        };

    }//namespace MovingEntities 
}//namespace Entities