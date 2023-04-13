#include "game.hpp"
#include "player.hpp"

#include <ctime>

using namespace std;

namespace ariel{

    Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2){

        initCards();
        giveOutCards();
        this->status = "the game is started";
        this->logs = " ";
        this->lastTurn = " ";
    }

    void Game::playTurn(){

        if(this->player1.stacksize() == 0 || this->player2.stacksize() == 0){
            throw ("game over");
        }

        if(&this->player1 == &this->player2){
            throw("no 2 players");
        }

        this->logs = "playing a new turn";
        lastTurn = "player1";
        Card player1CurrCard = player1.play();
        lastTurn = "player2";
        Card player2CurrCard = player2.play();
        vector<Card> cardsToWin;

        if(player1CurrCard.getVal() == player2CurrCard.getVal()){
            this->logs = "DRAW ! you should play one more time ";
            this->status = "the value of both of cards is same";
            Card tempP1 = player1CurrCard;
            Card tempP2 = player2CurrCard;

            while(tempP1.getVal() == tempP2.getVal()){
                
                cardsToWin.push_back(tempP1);
                cardsToWin.push_back(tempP2);
                lastTurn = "player1";
                tempP1 = player1.play();
                lastTurn = "player2";
                tempP2 = player2.play();
            }

            if(tempP1.getVal() > tempP2.getVal()){
               while(cardsToWin.size() > 0){
                    Card c = cardsToWin.back();
                    cardsToWin.pop_back();
                    player1.cardsWin.push_back(c);
               }
               this->status = "player1 wins last round";
            }
            else{
                while(cardsToWin.size() > 0){
                    Card c = cardsToWin.back();
                    cardsToWin.pop_back();
                    player2.cardsWin.push_back(c);
               }
               this->status = "player2 wins last round";
            }
        }
        else{
            if(player1CurrCard.getVal() > player2CurrCard.getVal()){
                player1.cardsWin.push_back(player1CurrCard);
                player1.cardsWin.push_back(player2CurrCard);
            }
            else{
                player2.cardsWin.push_back(player2CurrCard);
                player2.cardsWin.push_back(player1CurrCard);
            }
        }

        
    }

    void Game::printLastTurn(){
        std::cout << this->lastTurn << endl;

    }

    void Game::playAll(){
        while(this->player1.stacksize() > 0 || this->player2.stacksize() > 0){
            playTurn();
        }

    }

    void Game::printWiner(){
        this->logs = "we have winner";
        if(player1.cardsWin.size() > player2.cardsWin.size()){
            std::cout << this->player1.playerName << endl;
        }
        else {
            if(player1.cardsWin.size() < player2.cardsWin.size()){
                std::cout << this->player2.playerName << endl;
            }
            else{
                std::cout << "DRAW" << endl;
        }
        }
    }

    void Game::printLog(){
        std::cout << this->logs << endl;
    }

    void Game::printStats(){
        std::cout << this->status << endl; 
    }

    void Game::initCards(){
        
        for(int i = 0; i < 52; i++){
            Card card;
            for(int k = 0; k < 4; k++){
                for(int val = 0; val < 13; val++){
                    card.setCardKind(Card::Kind(k));
                    card.setCardValue(Card::Value(val));
                    this->cards.push_back(card);
                }
            }
        }
    }

    void Game::giveOutCards(){

        // srand(time(0));
        
        int maxNumber = 52;

        unsigned long numbers[maxNumber];
        bool usedNumbers[maxNumber] ;

        for(int i = 0; i < maxNumber; i++){
            usedNumbers[i] = false;
        }

        for(int i = 0; i < maxNumber;){
            int r = rand() % maxNumber + 1;
            if(!usedNumbers[r - 1]){
                numbers[i++] = (unsigned long)r;
                usedNumbers[r - 1] = true;
            }
        }

        for(int i = 0; i < 26; i++){
            player1.cards.push_back(this->cards.at(numbers[i]));
        }

        for(int i = 26; i < 52; i++){
            player2.cards.push_back(this->cards.at(numbers[i]));
        }
        
    }
}