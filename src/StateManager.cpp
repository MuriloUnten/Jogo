#include "StateManager.hpp"


namespace Managers
{
    StateManager* StateManager::instance = NULL;

    StateManager::StateManager()
    {
        lastStateID = undefined;
        
    }


    StateManager::~StateManager()
    {

    }


    StateManager* StateManager::getInstance()
    {
        if(instance == NULL)
            instance = new StateManager();
        return instance;
    }


    void StateManager::deleteInstance()
    {
        if(instance)
            delete instance;
        instance = NULL;
    }


    void StateManager::addState(State* state)
    {
    
    }

}// namespace Managers