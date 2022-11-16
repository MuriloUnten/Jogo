#pragma once

#include "MovingEntity.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        class Projectile : public MovingEntity
        {
        protected:


        public:
            Projectile();
            ~Projectile();

            void execute();

        };
    }// namespace MovingEntities
}//namespace Entities