#pragma once

#define PLAYER_ATTACK_COOLDOWN 1

#include "Character.hpp"
#include "Enemy.hpp"
#include "PlayerControl.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        class Player : public Character
        {
        private:

            PlayerControl controls;

            bool  onWeb;
            int score;

        public:
            Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), int hp=3);
            Player();
            ~Player();

            void execute();

            void setOnWeb(bool status);
            bool getOnWeb() const;
            void changeVelocity();

            void jump();
            void move(bool right);
            void moveDown();
            void attack();
            void stopWalking(bool side);
            void stopAttacking();
            void draw();

            void addScore(const int extraScore);
            const int getScore() const;

        };
    }// namespace MovingEntities

}// namespace Entities
