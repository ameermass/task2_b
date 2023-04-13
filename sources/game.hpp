#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "player.hpp"

using namespace std;

namespace ariel{
    
    class Game{

        private:
        Player &player1;
        Player &player2;
        string logs;
        string status;
        string lastTurn;
        
        vector<Card> cards;

        string gameWinner;
        string turnWinner;
        
        public:

        Game(Player &player1, Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void giveOutCards();
        void initCards();
    //friend ostream &operator<<(ostream &os, const Game &game);

    // ~Game(){};


    };

}
