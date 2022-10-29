#include "Entity.hpp"


Entity::Entity(const std::string fileName, sf::Vector2f size, sf::Vector2f position)
{
	hitBox = new sf::RectangleShape;
	texture = new sf::Texture;
	loadTexture(fileName);
	std::cout << "teste";
	hitBox->setSize(size);
	std::cout << "teste2";
	hitBox->setPosition(position);
	hitBox->setTexture(texture);
}


Entity::Entity()
{

}


Entity::~Entity()
{
	delete hitBox;
	hitBox = NULL;
	delete texture;
	texture = NULL;
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
	hitBox->setSize(sf::Vector2f(size.x, size.y));
}


sf::Vector2f Entity::getSize()
{
	return hitBox->getSize();
}


void Entity::loadTexture(const std::string fileName)
{
	if(!texture->loadFromFile(fileName))
	{
		std::cout << "ERROR. Unable to load texture from path: " << fileName << std::endl;
		exit(1);
	}
}


sf::RectangleShape* Entity::getHitBox()
{
	return hitBox;
}