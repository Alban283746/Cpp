#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include "headers/card.h"

class EnergyCard : public Card{

    protected :
        string energyType;

    public :
        EnergyCard(string energytype = "None");
        string typeget();
        void displayInfo() override;

};

#endif