#pragma once

#include "Being.hpp"
#include "GraphicsManager.hpp"

#define BUTTONSELECTED_PATH "../assets/Menu/ButtonSelected.png"
#define BUTTONDISSELECTED_PATH "../assets/Menu/ButtonDisselected.png"

#define TEXT_SIZE 24

class Button : public Being
{
private:

    bool hover;
    sf::Text text;
    sf::Font font;

public:

    Button(std::string fileName, sf::Vector2f size=sf::Vector2f(100.0f, 20.0f), sf::Vector2f pos=sf::Vector2f(0, 0));
    Button();
    ~Button();

    void draw();
    void execute();

    void setMessage(const char* m);
    void select(const bool isSelected);

};