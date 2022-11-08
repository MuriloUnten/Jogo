#include "Player.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {
            attack=false;
            run=false;
            jump=false;
            hp = 3;
        }


        Player::Player()
        {
            hp = 3;
            attack=false;
            run=false;
            jump=false;
        }


        Player::~Player()
        {

        }


        void Player::execute()
        {
            
        }
        void Player::Collide(Entity* otherEntity, Math::CoordF intersect)
        {
            /*
        //collison whith plataform
        else if (pEntidade->getID() == Ids::Ids::plataforma ) {
            colisaoPlataforma(intersected, pEntidade);
                
            }
        }
        //collision whith Enemy
        else if (pEntidade->getID() == Ids::Ids::Enemy) {
            
        }
        //collision whith obstacle damage
        else if (pEntidade->getID() == Ids::Ids::obstacle) {

            }
        }*/

        }

    }// namespace MovingEntities
}// namespace Entities