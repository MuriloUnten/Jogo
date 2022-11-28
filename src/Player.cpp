#include "Player.hpp"

#include <math.h>
#define WALKING "../assets/personagem/kakashi1.png"
#define ATTAKING "../assets/personagem/attacking.png"
namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(Eplayer, fileName, size, position, hp),
        controls(new PlayerControl(this))
        {
            onWeb = false;
            facingRight = true;
            attackTimer->setLimit(PLAYER_ATTACK_COOLDOWN);
            score = 0;
        }


        Player::Player():
        Character(),
        controls(new PlayerControl(this))
        {
            hp = 10;
            facingRight = true;
            attackTimer->setLimit(PLAYER_ATTACK_COOLDOWN);
            score = 0;
        }


        Player::~Player()
        {

        }


        void Player::execute()
        { 
            if(hp <= 0)
                executable = false;
            
            float dt = Managers::GraphicsManager::getDeltaTime();
            collisionTimer->update(dt);


            // TODO Rever
            if(walking)
            {
                if(facingRight)
                    vel.x = 350.0f;
                else
                    vel.x = -350.0f;
            }
            else
                vel.x = 0;

            changeVelocity();
            onWeb = false;

            update();
        }

        void Player::jump()
        {
            //std::cout << "jumping\n";
            if(canJump)
            {
                vel.y = -600;
                jumping = true;
                canJump = false;
            }
        }


        void Player::move(bool right)
        {
            walking = true;
            setFacingRight(right);
        }


        void Player::moveDown()
        {
            vel.y += 4000 * Managers::GraphicsManager::getDeltaTime();
        }


        void Player::attack()
        {
            attacking = true;
        }


        void Player::stopWalking(bool side)
        {
            if(side == facingRight)
            walking = false;
        }


        void Player::stopAttacking()
        {
            attacking = false;
        }

        void Player::draw()
        {
            if(attacking)
            {
                loadTexture(ATTAKING);
                //hitBox->setSize(sf::Vector2f(60, 60));
            }
            else
            {
                loadTexture(WALKING);
                //hitBox->setSize(sf::Vector2f(50, 60));
            }
            hitBox->setTexture(texture);
            if(pGraphics->isWindowOpen())
		        pGraphics->getWindow()->draw(*hitBox);
        }

        void Player::setOnWeb( bool status )
        {
            onWeb = status;
        }

        bool Player::getOnWeb() const
        {
            return onWeb;
        }

        void Player::changeVelocity()
        {
            if(onWeb)
            {
                vel.x *= 0.3;
            }
        }


        
        void Player::addScore(const int extraScore)
        {
            score += extraScore;
        }


        const int Player::getScore() const
        {
            return score;
        }


        PlayerControl* Player::getControls() const
        {
            return controls;
        }


        void Player::affectPlayer(MovingEntities::Player* player)
        {

        }

    }// namespace MovingEntities
}// namespace Entities