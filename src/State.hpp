#pragma once

#include "Being.hpp"

enum stateID
{
    undefined = -1,
    mainMenu = 0,
    playing,
    leaderboard

};

namespace Managers
{
    class StateManager;
}

class State : public Being
{
protected:
    Managers::StateManager* pStateManager;
    stateID id;

public:
    State(stateID id=stateID::undefined, std::string fileName="", sf::Vector2f size=sf::Vector2f(WIDTH, HEIGHT));
    ~State();

    virtual void execute() = 0;
    virtual void draw() = 0;

    void changeState(stateID id);
    stateID getID() const;

};