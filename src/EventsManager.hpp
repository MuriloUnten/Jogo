#pragma once

#include "GraphicsManager.hpp"
#include "InputManager.hpp"


namespace Managers
{
    class EventsManager
    {
    private:
        static EventsManager* instance;
        EventsManager();

        GraphicsManager* pGraphics;
        InputManager* pInput;

    public:
        ~EventsManager();
        static EventsManager* getInstance();
        static void deleteInstance();

        void pollEvents();

    };
}// namespace Managers