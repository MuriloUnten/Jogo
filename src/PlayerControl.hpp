#pragma once

#include "Observer.hpp"

namespace Entities::MovingEntities
{
    class Player;
}

class PlayerControl : public Observer
{
private:
    Entities::MovingEntities::Player* pPlayer;

    std::string jump;
    std::string left;
    std::string down;
    std::string right;
    std::string attack;

public:
    PlayerControl(Entities::MovingEntities::Player* player);
    ~PlayerControl();

    void handleKeyPressed(std::string key);
    void handleKeyReleased(std::string key);

    void setPlayer(Entities::MovingEntities::Player* player);

    void setKeys(std::string jump, std::string left, std::string down, std::string right, std::string attack);
};