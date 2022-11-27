#include "Observer.hpp"
#include <iostream>


Observer::Observer()
{
    pInput = Managers::InputManager::getInstance();
    pInput->attach(this);
}


Observer::~Observer()
{
    pInput->detach(this);
    pInput = NULL;
}