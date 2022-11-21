#pragma omce 

#include "Level.hpp"

namespace Levels
{
    class SecondLevel: public Level
    {
        private:

        public:
            SecondLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0, 0), Entities::MovingEntities::Player* player=NULL);
            ~SecondLevel();

            void createLevel();
    };

}// namespace Levels