#include "Entity.hpp"
#include "GraphicsManager.hpp"

namespace Entities
{
	Entity::Entity(const std::string fileName, sf::Vector2f size, sf::Vector2f position)
	{
		hitBox = new sf::RectangleShape;
		texture = new sf::Texture;
		loadTexture(fileName);
		hitBox->setSize(size);
		hitBox->setPosition(position);
		hitBox->setTexture(texture);
	}


	Entity::Entity()
	{
		hitBox = new sf::RectangleShape;
		texture = new sf::Texture;
		hitBox->setSize(sf::Vector2f(0, 0));
		hitBox->setPosition(sf::Vector2f(0, 0));
	}


	Entity::~Entity()
	{
		delete hitBox;
		delete texture;
		hitBox = NULL;
		texture = NULL;
	}


	void Entity::setPos(const sf::Vector2f position)
	{
		hitBox->setPosition(position);
	}


	sf::Vector2f Entity::getPos() const
	{
		return hitBox->getPosition();
	}


	void Entity::setSize(const sf::Vector2f size)
	{
		hitBox->setSize(size);
	}


	sf::Vector2f Entity::getSize() const
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


	sf::RectangleShape* Entity::getHitBox() const
	{
		return hitBox;
	}

	
	void Entity::draw()
	{
		Managers::GraphicsManager* gManager = Managers::GraphicsManager::getInstance();
		sf::RenderWindow* window = gManager->getWindow();

		if(window)
			window->draw(*hitBox);
	}

}// namespace Entities