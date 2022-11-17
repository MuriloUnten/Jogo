#include "Entity.hpp"
#include "GraphicsManager.hpp"

#define MAX_VELOCITY 500

namespace Entities
{

	Entity::Entity(const std::string fileName, sf::Vector2f size, sf::Vector2f position):
	Being(fileName, size, position)
	{
		vel = sf::Vector2f(0, 0);
		acc = sf::Vector2f(0, GRAVITY);
		timeCollision = TIMECOLLISON;
	}


	Entity::Entity():
	Being()
	{
		vel = sf::Vector2f(0, 0);
		acc = sf::Vector2f(0, GRAVITY);
	}


	Entity::~Entity()
	{

	}


	void Entity::update()
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


	void Entity::setVel(sf::Vector2f velocity)
	{
		vel = velocity;
	}


	sf::Vector2f Entity::getVel() const
	{
		return vel;
	}


	void Entity::setAcc(sf::Vector2f newAcc)
	{
		acc = newAcc;
	}


	sf::Vector2f Entity::getAcc()
	{
		return acc;
	}

	void Entity::setTimeCollision(float time)
	{
		timeCollision -= time;
		if(timeCollision < 0.0)
		{
			timeCollision = TIMECOLLISON;
		}
	}


	float Entity::getTimeCollision() const 
	{
		return timeCollision;
	}

	float Entity::getDT() const
	{
		float dt = pGraphics->getDeltaTime();
		return dt;
	}

}// namespace Entities