#include "headers/card.h"

Card::Card(string cardname) : cardName(cardname){}

string Card::nameget(){
    return cardName;
}

void Card::displayInfo() {
    cout << "Card Name: " << cardName << endl;
}