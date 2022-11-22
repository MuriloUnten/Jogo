#include "StateManager.hpp"


namespace Managers
{
    StateManager* StateManager::instance = NULL;

    StateManager::StateManager()
    {
        lastStateID = undefined;
        currentStateID = undefined;
    }


    StateManager::~StateManager()
    {
        std::map<stateID, State*>::iterator it;

        for (it = statesMap.begin(); it != statesMap.end(); ++it)
            delete (it->second);
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
        if(state != NULL)
            statesMap.insert(std::pair<stateID, State*>(state->getID(), state));
    }


    void StateManager::changeState(stateID newState)
    {
        lastStateID = currentStateID;
        currentStateID = newState;
        statesMap[currentStateID]->resetState();
    }


    void StateManager::executeState()
    {
        statesMap[currentStateID]->execute();
    }


    void StateManager::drawState()
    {
        statesMap[currentStateID]->draw();
    }

}// namespace Managers