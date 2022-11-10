#include "Player.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {

        }


        Player::Player()
        {
            hp = 3;
        }


        Player::~Player()
        {

        }


        void Player::execute()
        { 
            if(vel.x != 0){run=true;}
            else{run=false;}

            if(vel.y != 0){jump=true;}
            else{jump=false;}

            if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space )){
                atack=true;
                std::cout<<"apertou:"<<atack<<std::endl;
                }
            else{atack=false;}

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                hitBox->move(sf::Vector2f(0, -1));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                hitBox->move(sf::Vector2f(-1, 0));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                hitBox->move(sf::Vector2f(0, 1));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                hitBox->move(sf::Vector2f(1, 0));
            }

            draw();
        }
        
        bool Player::isAtack(){
            return atack;
        }

        void Player::takeDamage(Enemy *Enemy){
            hp-=Enemy->getDamage();
        }

    }// namespace MovingEntities
}// namespace Entities

