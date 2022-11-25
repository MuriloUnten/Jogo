#pragma once

#define BOSS_ATTACK_COOLDOWN 2.0f

#include "Enemy.hpp"
#include "Player.hpp"

#include <math.h>

namespace Entities::MovingEntities
{
    class Boss : public Enemy
    {
    private:

        Player* pPlayer1;
        Player* pPlayer2;

        int rage;

    public:

        Boss(const std::string fileName, sf::Vector2f size, sf::Vector2f position = sf::Vector2f(0, 0), int hp=3, Player* player1 = NULL, Player* player2 = NULL);
        ~Boss();

        void setPlayer1(Player* player);
        void setPlayer2(Player* player);


        void execute();
        void affectPlayer(MovingEntities::Player* player);

    };

}//namespace Entities::MovingEntities