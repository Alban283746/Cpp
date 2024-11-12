#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include <string>
#include <iostream>
#include <vector>
#include <tuple> 

#include "card.h"

class TrainerCard : public Card{
    protected :
        string trainerEffect;

    public :
        TrainerCard(string trainername, string trainerEffect = "None");
        string effectget();
        void displayInfo() override;
};

#endif