#pragma once

#include "State.hpp"
#include <map>


namespace Managers
{
    class StateManager
    {
    private:
        StateManager();
        static StateManager* instance;

        std::map<stateID, State*> statesMap;
        stateID currentStateID;
        stateID lastStateID;


    public:
        ~StateManager();
        static StateManager* getInstance();
        static void deleteInstance();

        void addState(State* state);
        void setState(stateID newStateID);
        void changeState(stateID newState);
        void overwriteState(State* newState);
        void executeState();
        void drawState();

    };
}// namespace Managers