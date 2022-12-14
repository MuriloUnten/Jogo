#pragma once

#include "Obstacle.hpp"

namespace Entities{
    namespace StaticEntities{
        class Web : public Obstacle
        {
        private:
            float slow;

        public:
            Web(const std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(80.0f,20.0f), float newSlow = 0.005f);
            Web();
            ~Web();

            void setSlow( const float newSlow);
            const float getSlow() const;

            void execute();
            void affectPlayer(MovingEntities::Player* player);
            
        };

    }//namespace StaticEntties
}//namespace Entities