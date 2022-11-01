#pragma once

#include "EntityList.hpp"
#include <math.h>

namespace Managers{
    class CollisionManager{
    private:
        //ponteiro para entidades móveis e estáticas
        Lists::EntityList *pStaticEntities;
        Lists::EntityList *pMovingEntities;
    public:
        CollisionManager(Lists::EntityList *pSE, Lists::EntityList *pME);
        ~CollisionManager();
        void Collision();
        //void Clear();
    };
}//namespace CllisionManager