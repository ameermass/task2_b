#include "card.hpp"

namespace ariel{


    //Card::Card(Kind kind, Value value) : cardKind(kind), cardValue(value){}

    string Card::getCardName(Kind kind){
        switch(kind){
            case heart:   return "Heart";
            case tilers:  return "Tilers";
            case clovers: return "Clovers";
            case pikes:   return "Pikes";
        }
    }

    int Card::getCardValue(Value value){
        switch(value){
            case two:   return 2;
            case three: return 3;
            case four:  return 4;
            case five:  return 5;
            case six:   return 6;
            case seven: return 7;
            case eight: return 8;
            case nine:  return 9;
            case ten:   return 10;
            case jack:  return 11;
            case queen: return 12;
            case king:  return 13;
            case ace:   return 1;
        }
    }
}