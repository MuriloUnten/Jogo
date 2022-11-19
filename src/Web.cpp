#include "Web.hpp"

namespace Entities
{
        namespace StaticEntities
        {
            Web::Web(const std::string fileName, sf::Vector2f size, sf::Vector2f position, float newSlow):
            Obstacle(Eweb, fileName, size, position, newSlow)
            {

            }

            Web::Web():
            Obstacle()
            {

            }

            Web::~Web()
            {

            }

            void Web::execute()
            {

            }

        }//namespace StaticEntities

}//naspace Entities