#pragma once

#include "Enemy.hpp"


namespace Entities::MovingEntities
{
    class Boss : public Enemy
    {
    private:



    public:
        Boss();
        ~Boss();

        void execute();


    };

}//namespace Entities::MovingEntities