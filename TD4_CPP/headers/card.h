#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card{

    protected:
        string cardName;

    public :
        Card(string cardname = "Energy Card");
        string nameget();
        virtual void displayInfo();
};

#endif