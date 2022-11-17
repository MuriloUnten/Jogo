#pragma once

#include "Being.hpp"


class Menu : public Being
{
protected:



public:
    Menu(std::string fileName, sf::Vector2f position, sf::Vector2f size);
    ~Menu();

    void execute();

};