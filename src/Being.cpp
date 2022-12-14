#include "Being.hpp"


Managers::GraphicsManager* Being::pGraphics = NULL;

Being::Being(std::string fileName, sf::Vector2f size, sf::Vector2f position)
{
	hitBox = new sf::RectangleShape;
	texture = new sf::Texture;
	loadTexture(fileName);
	setPos(position);
	hitBox->setSize(size);
	hitBox->setTexture(texture);
}


Being::Being()
{
	hitBox = new sf::RectangleShape;
	texture = new sf::Texture;
	hitBox->setSize(sf::Vector2f(0, 0));
	hitBox->setPosition(sf::Vector2f(0, 0));
}


Being::~Being()
{
	delete hitBox;
	delete texture;
	hitBox = NULL;
	texture = NULL;
}


void Being::setPos(const sf::Vector2f position)
{
	pos = position;
	hitBox->setPosition(position);
}


sf::Vector2f Being::getPos() const
{
	return pos;
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


sf::Texture* Being::getTexture() const
{
	return texture;
}


sf::RectangleShape* Being::getHitBox() const
{
	return hitBox;
}


void Being::setInstance()
{
	pGraphics = Managers::GraphicsManager::getInstance();
}


void Being::draw()
{
	if(pGraphics->isWindowOpen())
		pGraphics->getWindow()->draw(*hitBox);
}