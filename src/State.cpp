#include "State.hpp"
#include "StateManager.hpp"

State::State(stateID id, std::string fileName, sf::Vector2f size):
Being(fileName, size),
pStateManager(Managers::StateManager::getInstance())
{
    this->id = id;
}


State::~State()
{

}


void State::changeState(stateID id)
{
    pStateManager->changeState(id);
}


stateID State::getID() const
{
    return id;
}
