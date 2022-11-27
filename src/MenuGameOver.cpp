#include "MenuGameOver.hpp"

namespace Menu
{
    MenuGameOver::MenuGameOver(std::string fileName, sf::Vector2f size, sf::Vector2f position):
    Menu(stateID::gameOver, fileName, size, position)
    {
        active = false;

        gameOver.setString("GAME OVER");
        gameOver.setFont(*pGraphics->getFont());
        gameOver.setCharacterSize(50);
        sf::FloatRect textRect = gameOver.getLocalBounds();
        gameOver.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        gameOver.setPosition(sf::Vector2f(pos.x + hitBox->getSize().x/2, 150.0f));
        gameOver.setOutlineColor(sf::Color::Black);
        gameOver.setOutlineThickness(4);

        Button* bt = new Button(BUTTONDISSELECTED_PATH, sf::Vector2f(280.0f, 40.0f), sf::Vector2f((WIDTH-280.0f)/2, 340.0f));
        bt->setMessage("MAIN MENU");
        bt->select(true);
        buttonList.pushElement(bt);

        selected = buttonList.getHead();
    }


    MenuGameOver::~MenuGameOver()
    {

    }


    void MenuGameOver::draw()
    {
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
            pGraphics->getWindow()->draw(gameOver);
            drawButtons();
        }
    }


    void MenuGameOver::execute()
    {
        draw();
    }


    void MenuGameOver::pushButton()
    {
        switch (hoveredButton)
        {
        case -1:
            break;

        case 0:
            changeState(stateID::mainMenu);
            active = false;
            break;
        }
    }


    void MenuGameOver::resetState()
    {
        active = true;
        selected->getData()->select(false);
        hoveredButton = 0;
        selected = buttonList.getHead();
        selected->getData()->select(true);
    }
    
}// namespace Menu