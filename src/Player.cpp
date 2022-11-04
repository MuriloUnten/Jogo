#include "Player.hpp"


namespace Entities
{
    namespace MovingEntities
    {
        Player::Player(const std::string fileName, sf::Vector2f size, sf::Vector2f position, int hp):
        Character(fileName, size, position, hp)
        {
            attack=false;
            run=false;
            jump=false;
            hp = 3;
        }


        Player::Player()
        {
            hp = 3;
            attack=false;
            run=false;
            jump=false;
        }


        Player::~Player()
        {

        }


        void Player::execute()
        {
            
        }
        void Player::Collide(Entity* otherEntity, Math::CoordI intersect)
        {
            /*
        //Colisão com plaforma
        else if (pEntidade->getID() == Ids::Ids::plataforma || pEntidade->getID() == Ids::Ids::pedra || pEntidade->getID() == Ids::Ids::ponte || pEntidade->getID() == Ids::Ids::andaime) {
            colisaoPlataforma(intersecao, pEntidade);
            if (velocidade.y == 0.0f) {
                noChao = true;
                caindo = false;
            }
        }
        //Colisao com inimigos
        else if (pEntidade->getID() == Ids::Ids::goblin_bate ||
            pEntidade->getID() == Ids::Ids::esqueleto_bate ||
            pEntidade->getID() == Ids::Ids::animagus ||
            pEntidade->getID() == Ids::Ids::noturno) {
            Personagem* pPerson = static_cast<Personagem*>(pEntidade);
            pPerson->ativarAtacar();
            if (pPerson->podeAtacar()) {
                pPerson->desligarAtacar();
                podeTomarDano(pPerson->valorDano());
            }
        }
        //colisão com obstáculos
        else if (pEntidade->getID() == Ids::Ids::espinhos) {
            Obstaculo::Espinhos* pEsp = dynamic_cast<Obstaculo::Espinhos*>(pEntidade);
            if (pEsp->podeTomarDano()) {
                podeTomarDano(pEsp->getDano());
            }
        }*/
        }

    }// namespace MovingEntities
}// namespace Entities