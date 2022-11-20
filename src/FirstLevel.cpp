#include "FirstLevel.hpp"
#include <cstdlib>

#define GROUND2_PATH "../assets/mundo/ground_tile.png" 
#define GROUND3_PATH "../assets/mundo/ground2_tile.png"


namespace Levels
{
    FirstLevel::FirstLevel(std::string fileName, sf::Vector2f size, sf::Vector2f position, Entities::MovingEntities::Player* player):
    Level(fileName, size, position, player)
    {
        createLevel();
    }


    FirstLevel::~FirstLevel()
    {

    }

    void FirstLevel::createLevel()
    {
        FILE *file;
        int ch;
        float obstacleSize = 20.0;
        float width = 0.0, height = 0.0;
        file = fopen("FirstLevel.txt", "r");
        if(file == NULL)
        {
            std::cout << "Error opening File.\n";
            exit(1);
        }

        while((ch = fgetc(file)) != EOF)
        {
            //cactus or web
            if(ch == '1')
            {
                //srand((unsigned) time(NULL));

                int aux = rand()%2;
                if ( aux == 1)
                {
                    createWeb(sf::Vector2f( width, height));
                }
                else
                {
                    createCactus(sf::Vector2f( width, height));       
                }
                
            }

            //ground
            else if(ch == '2')
            {
                createGround(GROUND2_PATH, sf::Vector2f( width, height));
            }

            else if(ch == '3')
            {
                createGround(GROUND3_PATH, sf::Vector2f( width, height));
            }
            else if(ch == '4')
            {
                createArcher(sf::Vector2f( width, height));
            }
            else if(ch == '6')
            {
                createEnemy1(sf::Vector2f( width, height));
            }

            width+=20.0f;

            if(width == 1300.0f)
            {
                width = 0.0f;
                height+=20.0f;
            }
        }
        fclose(file);

        createPlayers(sf::Vector2f(400, 380));
    }

}// namespace Levels