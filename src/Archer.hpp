#pragma once

#define TIME_ARCHER 0.5
#define ARCHER_ATTACK_COOLDOWN 3.0f

#include "Enemy.hpp"
#include "Arrow.hpp"
#include "Player.hpp"
#include "Level.hpp"

#include <math.h>


namespace Entities
{
    namespace MovingEntities
    {
        class Archer : public Enemy
        {

            private:
                Arrow* pArrow;
                Player* pPlayer;

            public:
                Archer(const std::string fileName, sf::Vector2f size, sf::Vector2f position = sf::Vector2f(0, 0), int hp=2, Player* player = NULL);
                Archer();
                ~Archer();

                void setPlayer(Player* player);
                Arrow* getArrow() const;

                bool alcancePlayer();

                void execute();

        };
    }//namespace MovingEntities
}//namespace Entities