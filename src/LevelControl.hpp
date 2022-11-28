#pragma once

#include "Observer.hpp"

namespace Levels
{
    class Level;
}

class LevelControl : public Observer
{
private:
    Levels::Level* pLevel;

    std::string pause;
public:
    LevelControl(Levels::Level* level = NULL);
    ~LevelControl();

    void handleKeyPressed(std::string key);
    void handleKeyReleased(std::string key);

    void setLevel(Levels::Level* newLevel);

    void setKeys(std::string newPause);
};