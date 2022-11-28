#include "MenuSaveRanking.hpp"
#define LEADERBOARD_TXT_PATH "../assets/Saves/Leaderboard.txt"

namespace Menu
{
    MenuSaveRanking::MenuSaveRanking(float ranking, std::string filenameP , sf::Vector2f size, sf::Vector2f position):
    Menu(stateID::menuSaveRanking ,filenameP, size, position)
    {
        setInstance();
        active = true;
        rankingP = ranking;
        nameP = "";

        Button* bt = NULL;
        sf::Vector2f buttonSize = sf::Vector2f(280.0f, 40.0f);
        float xPosition = (WIDTH - buttonSize.x) / 2.0f;

        //mensagem para sinalizar oo que o player deve escrever
        message.setString("First name: ");
        message.setFont(*pGraphics->getFont());
        message.setCharacterSize(36);
        sf::FloatRect textRect = message.getLocalBounds();
        message.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        message.setPosition(sf::Vector2f(pos.x + hitBox->getSize().x/2, 90));
        message.setOutlineColor(sf::Color::Black);
        message.setOutlineThickness(4);
       
        //inicializando nome do Player
        message.setString(nameP);
        imputPlayer.setFont(*pGraphics->getFont());
        imputPlayer.setCharacterSize(24);
        imputPlayer.setPosition(sf::Vector2f((textRect.left + textRect.width ), 90));
        imputPlayer.setFillColor(sf::Color::White);

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 200));
        bt->setMessage("SAVE");
        bt->select(true);
        buttonList.pushElement(bt);
        selected = buttonList.getHead();

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 200));
        bt->setMessage("PLAY NEXT LEVEL");
        bt->select(true);
        buttonList.pushElement(bt);
        selected = buttonList.getHead();

        bt = new Button(MENU_PATH, buttonSize, sf::Vector2f(xPosition, 200));
        bt->setMessage("EXIT");
        bt->select(true);
        buttonList.pushElement(bt);
        selected = buttonList.getHead();

    }

    MenuSaveRanking::~MenuSaveRanking()
    {

    }

    void MenuSaveRanking::saveData()
    {
        
        if (nameP.size() == 0)
        {
		    return;
        }

        std::fstream leaderboardFile(LEADERBOARD_TXT_PATH, std::ios::out);
        std::string nameFile;
        std::string p;
        int pontuationFile;
        std::multimap< int, std::string, std::greater<int> > fileMap;

        if (leaderboardFile.is_open())
        {

            while (getline(leaderboardFile, nameFile) && getline(leaderboardFile, p))
            {
                //std::istringstream pStream(p);
                //pStream >> pontuationFile;
                fileMap.insert(std::pair<int, std::string>(pontuationFile, nameFile ));
            }

            leaderboardFile.close();
        }

        fileMap.insert(std::pair<int, std::string>(rankingP, nameP));

        leaderboardFile.open("../data/Leaderboard.txt", std::ios::out);

        if (leaderboardFile.is_open())
        {
            for (std::multimap<int, std::string>::iterator it = fileMap.begin(); it != fileMap.end(); it++)
            {
                leaderboardFile << (*it).second << std::endl;
                leaderboardFile << (*it).first << std::endl;
            }

            leaderboardFile.close();
        }
    }

    void MenuSaveRanking::draw()
    {
       if(pGraphics->isWindowOpen())
        {
            pGraphics->getWindow()->draw(*hitBox);
    
            //draw button 
            for(Lists::List<Button>::Element<Button>* it = buttonList.getHead(); it != NULL; it = it->getNext())
            {
                it->getData()->draw();
            }
            //draw Text
            pGraphics->getWindow()->draw(message);
        }
    }

    void MenuSaveRanking::execute()
    {
       //TODO setar nome do Player
        
        /*while (pGraphics->getWindow())
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) // se eh uma letra normal
                {
                    nameP += event.key.code + 'a';
                   imputPlayer.setString(nameP);
                }
                else if (event.key.code == sf::Keyboard::BackSpace && name.size() > 0)
                {
                    imputPlayer.setString(nameP);
                }
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    if (nameP.size() == 0)
                    {

                    }
                    else if (nameP.size() > 20)
                    {
                        errorMessage.setString("Name too long");
                        return;
                    }
                    // nao gravar se o nome nao for digitado

                    writeData();

                    message.setString(nameP);
                }
            }
        }
        */
        draw();
    }

    void MenuSaveRanking::pushButton()
    {
        switch (hoveredButton)
        {
        case -1:
            break;

        case 0:
            //changeState(stateID::mainMenu);
            saveData();
            active = false;
            break;
        case 1:
            changeState(stateID::level);
            active = false;
        case 2:
            changeState(stateID::mainMenu);
            active = false;
            break;

        }

    }

    void MenuSaveRanking::resetState()
    {
        active = true;
        selected->getData()->select(false);
        hoveredButton = 0;
        selected = buttonList.getHead();
        selected->getData()->select(true);
    }
}//namePspace Menu
