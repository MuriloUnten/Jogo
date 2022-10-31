#pragma once

#include "Character.hpp"

namespace Entities
{
    namespace MovingEntities
    {
        class Player : public Character
        {
        private:


        public:
            Player();
            ~Player();

            void execute();

        };
    }// namespace MovingEntities

}// namespace Entities
