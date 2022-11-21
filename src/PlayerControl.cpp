#include "PlayerControl.hpp"
#include "Player.hpp"

PlayerControl::PlayerControl(Entities::MovingEntities::Player* player):
pPlayer(player),
jump("W"),
left("A"),
down("S"),
right("D"),
attack("Space")
{

}


PlayerControl::~PlayerControl()
{
    pPlayer = NULL;
}


void PlayerControl::handleKeyPressed(std::string key)
{
    std::cout << "PlayerControl::handleKeyPressed.\n";
    std::cout << jump << " " << left << "\n";
    if(key == jump)
    {
        std::cout << "Jumping.\n";
        pPlayer->jump();
    }

    else if(key == left)
    {
        std::cout << "Moving left.\n";
        pPlayer->move(false);
    }

    else if(key == down)
        pPlayer->moveDown();

    else if(key == right)
        pPlayer->move(true);

    else if(key == attack)
        pPlayer->attack();
}


void PlayerControl::handleKeyReleased(std::string key)
{
    if(key == left)
        pPlayer->stopWalking(false);

    else if(key == right)
        pPlayer->stopWalking(true);

    else if(key == attack)
        pPlayer->stopAttacking();
}


void PlayerControl::setPlayer(Entities::MovingEntities::Player* player)
{
    pPlayer = player;
}


void PlayerControl::setKeys(std::string jump, std::string left, std::string down, std::string right, std::string attack)
{
    this->jump = jump;
    this->left = left;
    this->down = down;
    this->right = right;
    this->attack = attack;
}