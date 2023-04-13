#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


namespace ariel{

    using namespace std;
    class Card{

        public:
        enum Kind {heart, tilers, clovers, pikes};
        enum Value {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

        Card(Kind kind = heart, Value value = seven): cardKind(kind), cardValue(value) {}

        string getCardName(Kind);
        Value getVal(){
            return cardValue;
        }

        int getCardValue(Value);

        void setCardKind(Kind cardKind){
            this->cardKind = cardKind;
        }

        void setCardValue(Value val){
            this->cardValue = val;
        }

        bool operator==(const Card& other) {
            return this->cardValue == other.cardValue;
        }

        bool operator>(const Card& other) {
            return this->cardValue > other.cardValue;
        }

        bool operator<(const Card& other) {
            return this->cardValue < other.cardValue;
        }

        private:
        Kind cardKind;
        Value cardValue;

    };
}