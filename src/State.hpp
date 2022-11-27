#pragma once

#include "Being.hpp"

enum stateID
{
    undefined = -1,
    mainMenu = 0,
    level,
    leaderboard,
    gameOver,
    pause,
    menuChoosePlayers = 5, 
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
    bool active;

public:
    State(stateID id=stateID::undefined, std::string fileName="", sf::Vector2f size=sf::Vector2f(WIDTH, HEIGHT));
    virtual ~State();

    virtual void execute() = 0;
    virtual void draw() = 0;
    virtual void resetState() = 0;

    void changeState(stateID id);
    stateID getID() const;

    const bool getActive() const;
    void setActive(const bool isActive);

};