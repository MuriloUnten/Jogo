#include "Button.hpp"

#include <math.h>
#include <string.h>

Button::Button(std::string fileName, sf::Vector2f size, sf::Vector2f pos) :
Being( BUTTONDISSELECTED_PATH, size, pos),
hover(false) {
    setInstance();
}


Button::~Button()
{

}


void Button::setMessage(const char* m) {
    text.setString(m);

    text.setFont(*pGraphics->getFont());
    text.setCharacterSize(TEXT_SIZE);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(pos.x + hitBox->getSize().x/2, pos.y + hitBox->getSize().y/2));
    text.setFillColor(sf::Color::White);
}


void Button::draw() {

    if (hover)
        loadTexture(BUTTONSELECTED_PATH);
    else
        loadTexture(BUTTONDISSELECTED_PATH);
    hitBox->setTexture(texture);
    
    if(pGraphics->isWindowOpen())
    {
        pGraphics->getWindow()->draw(*hitBox);
        pGraphics->getWindow()->draw(text);
    }
}


void Button::execute()
{

}


void Button::select(const bool isSelected) 
{ 
    hover = isSelected;
}