#include "Being.hpp"

Being::Being(std::string fileName, sf::Vector2f size, sf::Vector2f position)
{
	pGraphics = Managers::GraphicsManager::getInstance();
	hitBox = new sf::RectangleShape;
	texture = new sf::Texture;
	loadTexture(fileName);
	hitBox->setSize(size);
	hitBox->setPosition(position);
	hitBox->setTexture(texture);


	id = -1;
}


Being::Being()
{
	pGraphics = Managers::GraphicsManager::getInstance();
	id = -1;
	hitBox = new sf::RectangleShape;
	texture = new sf::Texture;
	hitBox->setSize(sf::Vector2f(0, 0));
	hitBox->setPosition(sf::Vector2f(0, 0));
}


Being::~Being()
{
	id = -1;
	delete hitBox;
	delete texture;
	hitBox = NULL;
	texture = NULL;
}

void Being::setId(const int ID)
{
	id = ID;
}


const int Being::getId() const
{
	return id;
}


void Being::setPos(const sf::Vector2f position)
{
	hitBox->setPosition(position);
}


sf::Vector2f Being::getPos() const
{
	return hitBox->getPosition();
}


void Being::setSize(const sf::Vector2f size)
{
	hitBox->setSize(size);
}


sf::Vector2f Being::getSize() const
{
	return hitBox->getSize();
}


void Being::loadTexture(const std::string fileName)
{
	if(!texture->loadFromFile(fileName))
	{
		std::cout << "ERROR. Unable to load texture from path: " << fileName << std::endl;
		exit(1);
	}
}


sf::RectangleShape* Being::getHitBox() const
{
	return hitBox;
}


void Being::draw()
{
	if(pGraphics->isWindowOpen())
		pGraphics->getWindow()->draw(*hitBox);
}