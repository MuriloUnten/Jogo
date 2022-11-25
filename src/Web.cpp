#include "Web.hpp"

namespace Entities
{
        namespace StaticEntities
        {
            Web::Web(const std::string fileName, sf::Vector2f size, sf::Vector2f position, float newSlow):
            Obstacle(Eweb, fileName, size, position)
            {
                slow = newSlow;
            }

            Web::Web():
            Obstacle()
            {

            }

            void Web::setSlow(const float newSlow)
            {
            slow = newSlow;
            }


            const float Web::getSlow() const
            {
                return slow;
            }

            Web::~Web()
            {

            }

            void Web::execute()
            {

            }


            void Web::affectPlayer(MovingEntities::Player* player)
            {
                player->setOnWeb(true);
            }
        }//namespace StaticEntities

}//naspace Entities