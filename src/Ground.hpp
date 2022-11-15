#pragma once

#include "Obstacle.hpp"

namespace Entities
{
    namespace StaticEntities
    {
        class Ground : public Obstacle
        {
        private:
            

        public:
            Ground(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f,0.0f));
            Ground();
            ~Ground();

            void execute();
        };

    }// namespace StaticEntities
}// namespace Entities