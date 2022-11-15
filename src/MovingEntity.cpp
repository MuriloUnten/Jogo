#include "MovingEntity.hpp"

#define MAX_VELOCITY 500

namespace Entities
{
    namespace MovingEntities
    {
        MovingEntity::MovingEntity(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int newdamage=1):
        Entity(fileName, size, position)
        {
            vel = sf::Vector2f(0, 0);
            acc = sf::Vector2f(0, GRAVITY);
        }


        MovingEntity::MovingEntity()
        {
            vel = sf::Vector2f(0, 0);
            acc = sf::Vector2f(0, GRAVITY);
        }


        MovingEntity::~MovingEntity()
        {

        }


        void MovingEntity::update()
        {
            float dt = pGraphics->getDeltaTime();

            pos.x += (vel.x * dt);
            pos.y += (vel.y * dt) + (acc.y * dt * dt) / 2;

            //vel.x += acc.x * dt;
            if(vel.x > MAX_VELOCITY)
                vel.x = MAX_VELOCITY;
            else if(vel.x < -MAX_VELOCITY)
                vel.x = -MAX_VELOCITY;
            
            vel.y += acc.y * dt;
            if(vel.y > 2 * MAX_VELOCITY)
            {
                vel.y = 2 * MAX_VELOCITY;
            }

            hitBox->setPosition(pos);
            //std::cout << "VEL: " << vel.y << std::endl;
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