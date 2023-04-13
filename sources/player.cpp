#include "player.hpp"
using namespace std;


namespace ariel{

Player::Player(const char* name) : playerName(name), cardsWin(0){}

Card Player::play(){
    Card card = this->cards.back();
    this->cards.pop_back();
    return card;
}

int Player::stacksize(){
    return this->cards.size();
}

int Player::cardesTaken(){
    return this->cardsWin.size();
}

}

