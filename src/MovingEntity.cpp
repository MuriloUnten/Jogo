#include "MovingEntity.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        MovingEntity::MovingEntity(const std::string fileName, sf::Vector2f size, sf::Vector2f position):
        Entity(fileName, size, position)
        {
            vel = sf::Vector2f(0, 0);
            acc = sf::Vector2f(0, 0);
        }


        MovingEntity::MovingEntity()
        {
            vel = sf::Vector2f(0, 0);
            acc = sf::Vector2f(0, 0);     
        }


        MovingEntity::~MovingEntity()
        {

        }


        void MovingEntity::update(const double dt, sf::Vector2f newVel)
        {
            vel.x = newVel.x;
            vel.y = newVel.y + GRAVITY * dt;

            pos.x += vel.x * dt;
            pos.y += vel.y * dt;
        }

        void MovingEntity::setVel(sf::Vector2f velocity){

            vel.x = velocity.x;
            vel.y = velocity.y;
        }
        sf::Vector2f MovingEntity::getVel(){
            return vel;
        }

    }// namespace MovingEntities
}// namespace Entities