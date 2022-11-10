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


        void MovingEntity::update()
        {
            float dt = pGraphics->getDeltaTime();
            std::cout << dt << std::endl;
            vel.y += GRAVITY * dt;

            pos.x += vel.x * dt;
            pos.y += vel.y * dt;

            hitBox->setPosition(pos);
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