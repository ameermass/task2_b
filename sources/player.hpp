
#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include<vector>

#include "card.hpp"
using namespace std;

namespace ariel{
    class Player
    {
    public:
    string playerName;
    vector<Card> cardsWin;

    Card play();

    vector<Card> cards; 

    Player(){}
    Player(const char* name);

    int stacksize();
    int cardesTaken();

    };

}

