#include "Level.hpp"
#include "Game.hpp"

#define PLAYER_PATH "../assets/personagem/kakashi1.png"
#define ENEMY1_PATH "../assets/inimigos/enemy1.png"
#define ARCHER_PATH "../assets/inimigos/arqueiro.png"
#define CACTUS_PATH "../assets/mundo/Cactus4.png"
#define GROUND2_PATH "../assets/mundo/ground_tile.png" 
#define GROUND3_PATH "../assets/mundo/ground2_tile.png"
#define WEB_PATH "../assets/mundo/SpiderWeb.png"
#define BOSS_RUN_PATH "../assets/inimigos/Boss_Run.png"

#include <string.h>


namespace Levels
{
    Level::Level(const char* nameLevel, std::string fileName, sf::Vector2f size, sf::Vector2f position):
    State(stateID::level, fileName, size),
    controls(this),
    entityList(new Lists::EntityList()),
    collisions(new Managers::CollisionManager())
    {        
        Being::setInstance();

        timePlayed = 0.0f;

        pPlayer1 = new Entities::MovingEntities::Player;
        Entities::Entity* pAux = static_cast<Entities::Entity*>(pPlayer1);
        entityList->pushEntity(pAux);
        collisions->pushPlayer(pPlayer1);
            
        pPlayer2 = new Entities::MovingEntities::Player;
        pAux = static_cast<Entities::Entity*>(pPlayer2);
        entityList->pushEntity(pAux);
        collisions->pushPlayer(pPlayer2);

        setCurrentLevel(nameLevel);
        lvlEnded = true;

        infoHp.setString("Hp: 10");
        infoHp.setFont(*pGraphics->getFont());
        infoHp.setCharacterSize(14);
        infoHp.setPosition(sf::Vector2f(40.0f, 40.0f));
        infoHp.setOutlineColor(sf::Color::Black);
        infoHp.setOutlineThickness(4);

        infoRanking.setString("Ranking: 0.0");
        infoRanking.setFont(*pGraphics->getFont());
        infoRanking.setCharacterSize(14);
        infoRanking.setPosition(sf::Vector2f(200.0f, 40.0f));
        infoRanking.setOutlineColor(sf::Color::Black);
        infoRanking.setOutlineThickness(4);


    }


    Level::Level():
    State(stateID::level),
    controls(this),
    entityList(new Lists::EntityList())
    {
        pPlayer1 = NULL;
        pPlayer2 = NULL;
    }


    Level::~Level()
    {
        delete pPlayer1;
        delete pPlayer2;

        delete entityList;
        entityList = NULL;
        
        delete collisions;
        collisions = NULL;
    }

    void Level::SetTwoPlayers(bool Bplayers)
    {
        twoPlayers = Bplayers;
    }
    
    void Level::execute()
    {
        active = true;

        std::string info ;
        int hp = pPlayer1->getHp();
        info = "hp: " + std::to_string(hp);
        infoHp.setString(info);

        timePlayed += pGraphics->getDeltaTime();
        info = "Time: " + std::to_string(timePlayed);
        infoRanking.setString(info);

        draw();

        entityList->execute();
        collisions->Collision();
        entityList->draw();

        if(!pPlayer1->getExecutable())
        {
            if(twoPlayers)
            {
                if(!pPlayer2->getExecutable())
                    endLevel(false);
            }
            else
                endLevel(false);
        }
        else
        {
            countEnemies();
            if(numberOfEnemies == 0)
                endLevel(true);
        }
    }

    void Level::draw()
    {
        /* TODO implementar mais coisas talvez?*/
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
            drawInfo();
        }
    }


    void Level::drawInfo()
    {
        /* TODO implementar mais coisas talvez?*/
        pGraphics->getWindow()->draw(infoHp);
        pGraphics->getWindow()->draw(infoRanking);
    }


    void Level::createPlayers(Entities::MovingEntities::Player* player, sf::Vector2f pos)
    {
        player->loadTexture(PLAYER_PATH);
        player->setSize(sf::Vector2f(50, 60));
        player->getHitBox()->setTexture(player->getTexture());
        player->setPos(pos);
        player->setExecutable(true);
    }

    void Level::createEnemy1(sf::Vector2f pos)
    {
        Entities::MovingEntities::Enemy1* enemy = new Entities::MovingEntities::Enemy1(ENEMY1_PATH, sf::Vector2f(50, 50), pos);
        Entities::Entity* pEntity = static_cast<Entities::Entity*>(enemy);
        Entities::MovingEntities::Enemy* pEnemy = static_cast<Entities::MovingEntities::Enemy*>(enemy);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);
    }

    void Level::createArcher(sf::Vector2f pos)
    {
        Entities::MovingEntities::Archer* archer = new Entities::MovingEntities::Archer(ARCHER_PATH, sf::Vector2f(50, 70), pos);
        archer->setPlayer(pPlayer1);
        Entities::Entity* pEntity = static_cast<Entities::Entity*>(archer);
        Entities::MovingEntities::Enemy* pEnemy = static_cast<Entities::MovingEntities::Enemy*>(archer);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);

        pEntity = static_cast<Entities::Entity*>(archer->getArrow());
        entityList->pushEntity(pEntity);
        Entities::MovingEntities::Projectile* pProjectile = static_cast<Entities::MovingEntities::Arrow*>(pEntity);
        collisions->pushProjectile(pProjectile);
    }
    
    void Level::createBoss(sf::Vector2f pos)
    {
        Entities::MovingEntities::Boss* boss = new Entities::MovingEntities::Boss(BOSS_RUN_PATH, sf::Vector2f(70, 70), pos);
        boss->setPlayer1(pPlayer1);
        Entities::Entity* pEntity = static_cast<Entities::Entity*>(boss);
        Entities::MovingEntities::Enemy* pEnemy = static_cast<Entities::MovingEntities::Enemy*>(boss);
        entityList->pushEntity(pEntity);
        collisions->pushEnemy(pEnemy);
    }

    void Level::createGround(std::string fileName, sf::Vector2f pos)
    {
        Entities::StaticEntities::Ground *pAuxObstacle = new Entities::StaticEntities::Ground(fileName, sf::Vector2f(20, 20), pos);
                
        Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
        collisions->pushObstacle(pCastObsAux);

        Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
        entityList->pushEntity(pCastAux);

    }

    void Level::createCactus(sf::Vector2f pos)
    {
        Entities::StaticEntities::Cactus *pAuxObstacle = new Entities::StaticEntities::Cactus( CACTUS_PATH, sf::Vector2f(80, 18), pos);

        Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
        collisions->pushObstacle(pCastObsAux);

        Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
        entityList->pushEntity(pCastAux);
    }

    void Level::createWeb(sf::Vector2f pos)
    {
        Entities::StaticEntities::Web *pAuxObstacle = new Entities::StaticEntities::Web( WEB_PATH, sf::Vector2f(80, 20), pos, 0.5f);

        Entities::StaticEntities::Obstacle* pCastObsAux = static_cast<Entities::StaticEntities::Obstacle*>(pAuxObstacle);
        collisions->pushObstacle(pCastObsAux);

        Entities::Entity* pCastAux = static_cast<Entities::Entity*>(pAuxObstacle);
        entityList->pushEntity(pCastAux);
    }

    void Level::createLevel()
    {
        srand(time(NULL));
        FILE *file;
        char ch;
        int aux;
        float obstacleSize = 20.0;
        float width = 0.0, height = 0.0;

        file = fopen(currentLevel, "r");

        if(file == NULL)
        {
            std::cout << "Error opening File.\n";
            exit(1);
        }

        bool player1Created = false;
        while((ch = fgetc(file)) != EOF)
        {

            aux = rand()%2;
            switch (ch)
            {
            case '1':
                switch (aux)
                {
                case 0 :
                    createWeb(sf::Vector2f( width, height));
                    break;
                case 1:
                    createCactus(sf::Vector2f( width, height));       
                    break;
                }
                break;
            case '2':
                createGround(GROUND2_PATH, sf::Vector2f( width, height));
                break;
            case '3': 
                createGround(GROUND3_PATH, sf::Vector2f( width, height));
                break;
            case '4':
                createArcher( sf::Vector2f( width, height));                
                break;
            case '5':
                createBoss(sf::Vector2f( width, height));
                break;
            case '6':
                createEnemy1(sf::Vector2f( width, height));
                break;
            case '7':
                if(!player1Created)
                {
                    createPlayers(pPlayer1, sf::Vector2f(width, height));
                    pPlayer1->getControls()->setKeys("W", "A", "S", "D", "Space");
                    player1Created = true;
                }
                else if(twoPlayers)
                {
                    std::cout << "creating second player\n";
                    createPlayers(pPlayer2, sf::Vector2f(width, height));
                    pPlayer2->getControls()->setKeys("Up", "Left", "Down", "Right", "Enter");
                }
                    
                break;
            case '8':
                switch (aux)
                {
                case 0 :
                    createArcher(sf::Vector2f( width, height));
                    break;
                case 1:
                    createEnemy1(sf::Vector2f( width, height));       
                    break;
                }
                break;
            }

            width+=20.0f;

            if(width == 1300.0f)
            {
                width = 0.0f;
                height+=20.0f;
            }
        }
        fclose(file);
        
        // TODO checar como criar os 2 players devidamente.
        // if(TwoPlayers)
        // {
        //     pPlayer1 = pGame->getPlayer1();
        //     createPlayers(pPlayer1, sf::Vector2f(40.0f, 600.0f));
        //     pPlayer2 = pGame->getPlayer1();
        //     createPlayers(pPlayer2, sf::Vector2f(100.0f, 600.0f));
        // }
        // else
        // {
        //     pPlayer1 = pGame->getPlayer1();
        //     createPlayers(pPlayer1, sf::Vector2f(40.0f, 600.0f));
        // }
    }


    void Level::setCurrentLevel(const char* newLevel)
    {
        strcpy(currentLevel, newLevel);
    }


    void Level::endLevel(const bool win)
    {
        lvlEnded = true;
        active = false;
        if(win)
        {
            /* Pegar pontuação dos players, fazer algo com isso
               talvez mudar para fase 2 ou outro menu
               talvez desbloquear fase 2 apenas após ganhar fase 1
            */
            changeState(stateID::mainMenu);
        }
        else
        {
            changeState(stateID::gameOver);
        }
        entityList->clear();
        // delete collisions;
    }


    void Level::setLvlEnded(const bool option)
    {
        lvlEnded = option;
    }


    void Level::countEnemies()
    {
        numberOfEnemies = 0;
        Lists::List<Entities::Entity>::Element<Entities::Entity>* iterator = entityList->getList().getHead();
        while(iterator != NULL)
        {
            ID entityID = iterator->getData()->getId();
            if(entityID == ID::Earcher || entityID == ID::Eenemy1 || entityID == ID::Eboss)
                if(iterator->getData()->getExecutable())
                    numberOfEnemies++;

            iterator = iterator->getNext();
        }
    }


    void Level::resetState()
    {
        if(lvlEnded)
        {
            entityList->clear();
            timePlayed = 0;
            lvlEnded = false;
            collisions = new Managers::CollisionManager();

            pPlayer1 = new Entities::MovingEntities::Player;
            entityList->pushEntity(static_cast<Entities::Entity*>(pPlayer1));
            collisions->pushPlayer(pPlayer1);

            pPlayer2 = new Entities::MovingEntities::Player;
            entityList->pushEntity(static_cast<Entities::Entity*>(pPlayer2));
            collisions->pushPlayer(pPlayer2);

            createLevel();
        }
    }

}// namespace Levels