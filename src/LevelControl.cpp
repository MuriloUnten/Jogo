#include "LevelControl.hpp" 
#include "Level.hpp"


LevelControl::LevelControl(Levels::Level* level):
Observer(),
pause("Escape")
{
    pLevel = level;
}


LevelControl::~LevelControl()
{

}


void LevelControl::handleKeyPressed(std::string key)
{
    if(pLevel->getActive())
    {
        if(key == pause)
        {
            pLevel->changeState(stateID::pause);
            pLevel->setActive(false);
        }
    }
}


void LevelControl::handleKeyReleased(std::string key)
{

}


void LevelControl::setLevel(Levels::Level* newLevel)
{
    pLevel = newLevel;
}



void LevelControl::setKeys(std::string newPause)
{
    pause = newPause;
}