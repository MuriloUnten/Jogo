#include "MenuSaveRanking.hpp"

namespace Menu
{
    MenuSaveRanking::MenuSaveRanking(std::string fileName, sf::Vector2f size, sf::Vector2f position)
    {
        textControl = NULL;

        // playerInput.setFont(*pGraphics->getFont());
        // playerInput.setCharacterSize(24);
        // playerInput.setPosition(sf::Vector2f((textRect.left + textRect.width), 90));
        // playerInput.setFillColor(sf::Color::White);
    }


    MenuSaveRanking::~MenuSaveRanking()
    {
        delete textControl;
    }


    void MenuSaveRanking::saveData()
    {
        // textControl = new TextControl();

        // std::ifstream readFile;

        // readFile.open(LEADERBOARD_TXT_PATH, std::ios::in);

        // std::multimap<int, std::string> pointsAndNamesMap;

        // if (!readFile)
        // {
        //     std::cout << "ERROR. Unable to open file.\n";
        //     exit(1);
        // }

        // unsigned int points;
        // std::string name;
        // std::string pointsString;

        // for (int i = 0; i < 10; i++)
        // {
        //     std::getline(readFile, name);
        //     std::getline(readFile, pointsString);
        //     if (pointsString.length() > 0)
        //         pointsAndNamesMap.insert(std::pair<int, std::string>(std::stoi(pointsString), name));
        // }

        // readFile.close();

        // /* ================================= Writing File ================================= */
        // if (rankingP != 0 && imputPlayer.getString().getSize() > 1)
        //     pointsAndNamesMap.insert(std::pair<int, std::string>(rankingP, imputPlayer.getString()));

        // std::ofstream writeFile;

        // writeFile.open(LEADERBOARD_TXT_PATH, std::ios::out | std::ios::trunc);

        // if (!writeFile) {
        //     std::cout << "ERROR writing to file on GameOverMenu" << std::endl;
        //     exit(1);
        // }

        // while (pointsAndNamesMap.size() > 10)
        //     pointsAndNamesMap.erase(pointsAndNamesMap.begin());

        // for (auto itr = pointsAndNamesMap.rbegin(); itr != pointsAndNamesMap.rend(); ++itr) {
        //     writeFile << (*itr).first << std::endl;
        //     writeFile << (*itr).second << std::endl;
        // }

        // writeFile.close();
    }


    void MenuSaveRanking::draw()
    {
        if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
            // TODO desenhar texto;
        }
    }
    
    
    void MenuSaveRanking::execute()
    {
        active = true;
        draw();
    }
    
    
    void MenuSaveRanking::pushButton()
    {

    }

    
    void MenuSaveRanking::resetState()
    {
        textControl = new TextControl();
    }

}// namespace Menu
