#include "Entity.hpp"


Entity::Entity(const std::string fileName, sf::Vector2f size,
	sf::Vector2f position)
{
	loadTexture(fileName);
	hitBox->setSize(size);
	hitBox->setPosition(position);
	hitBox->setTexture(texture);
}


Entity::Entity()
{

}


Entity::~Entity()
{

}


void Entity::execute()
{

}


void Entity::setPos(sf::Vector2f position)
{
	hitBox->setPosition(position);
}


sf::Vector2f Entity::getPos()
{
	return hitBox->getPosition();
}


void Entity::setSize(sf::Vector2f size)
{
	hitBox->setSize(size);
}


sf::Vector2f Entity::getSize()
{
	return hitBox->getSize();
}


bool Entity::loadTexture(const std::string fileName)
{
	return (texture->loadFromFile(fileName));
}


sf::RectangleShape* Entity::getHitBox()
{
	return hitBox;
}