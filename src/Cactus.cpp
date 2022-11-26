#include "Cactus.hpp"
#include "Player.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        Cactus::Cactus(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newDamage):
        Obstacle(Ecactus, fileName, size, position)
        {
            Odamage = true;
            damage = newDamage;
    
        }

        Cactus::Cactus():
        Obstacle()
        {
            Odamage = true;
            damage = 1;
        }
        
        Cactus::~Cactus()
        {
            
        }

        void Cactus::setDamage(const int newDamage)
        {
            damage = newDamage;
        }


        const int Cactus::getDamage() const
        {
            return damage;
        }

        void Cactus::execute()
        {

        }


        void Cactus::affectPlayer(MovingEntities::Player* player)
        {
            if(player->getCollisionTimer()->getElapsedTime() >= player->getCollisionTimer()->getLimit())
            {
                player->takeDamage(damage);// mesmo método de * com a intenção de fazer coisas diferentes???
                player->getCollisionTimer()->restart();
            }
        }

    }//namespace StaticEntities
}//namespace Entities