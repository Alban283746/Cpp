#include "headers/energy_card.h"

EnergyCard::EnergyCard(string energytype) : energyType(energytype){};

string EnergyCard::typeget(){
    return energyType;
}

void EnergyCard::displayInfo() {
    cout << cardName << " of type " << energyType <<endl;
}