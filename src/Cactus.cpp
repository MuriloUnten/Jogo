#include "Cactus.hpp"

namespace Entities{
    namespace StaticEntities{
        Cactus::Cactus(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f), int newDamage=50):
        Obstacle(fileName, size, position)
        {
            Odamage = true;
            damage = newDamage;
    
        }

        Cactus::Cactus():
        Obstacle()
        {
            Odamage = true;
            damage = 50;
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

    }//namespace StaticEntities
}//namespace Entities