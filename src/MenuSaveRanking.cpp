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
        std::ifstream readFile;

        readFile.open(LEADERBOARD_TXT_PATH, std::ios::in);

        std::multimap<int, std::string> pointsAndNamesMap;

        if (readFile) {

            unsigned int points;
            std::string name;
            std::string pointsString;

            for (int i = 0; i < 10; i++) {
                std::getline(readFile, pointsString);
                std::getline(readFile, name);
                if (pointsString.length() > 0)
                    pointsAndNamesMap.insert(std::pair<int, std::string>(std::stoi(pointsString), name));
            }

            readFile.close();
        }

        /* ================================= Writing File ================================= */
        if (rankingP != 0 && imputPlayer.getString().getSize() > 1)
            pointsAndNamesMap.insert(std::pair<int, std::string>(rankingP, imputPlayer.getString()));

        std::ofstream writeFile;

        writeFile.open(LEADERBOARD_TXT_PATH, std::ios::out | std::ios::trunc);

        if (!writeFile) {
            std::cout << "ERROR writing to file on GameOverMenu" << std::endl;
            exit(1);
        }

        while (pointsAndNamesMap.size() > 10)
            pointsAndNamesMap.erase(pointsAndNamesMap.begin());

        for (auto itr = pointsAndNamesMap.rbegin(); itr != pointsAndNamesMap.rend(); ++itr) {
            writeFile << (*itr).first << std::endl;
            writeFile << (*itr).second << std::endl;
        }

        writeFile.close();
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
