#include "headers/trainer_card.h"

TrainerCard::TrainerCard(string trainername, string trainereffect) : trainerEffect(trainereffect) { cardName = trainername;};

string TrainerCard::effectget(){
    return trainerEffect;
}

void TrainerCard::displayInfo() {
    cout<< "Trainer Card - Name :" << cardName << "," << " Effect : " << trainerEffect <<endl;
}