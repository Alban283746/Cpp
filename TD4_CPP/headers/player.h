#ifndef PLAYER_H
#define PLAYER_H


#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include "headers/pokemon_card.h"
#include "headers/energy_card.h"
#include "headers/trainer_card.h"

class Player{

    protected :
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
    
    public : 
        Player(string name);
        void addCardToBench(Card* card);
        void activatePokemonCard(int index_bench);
        void attachEnergyCard(int index_bench,int index_action);
        void attack(int mypokemon,int otherpokemon,Player other,int attackuse);
        void displayBench();
        void displayAction();
        void useTrainer(int indexbench);

        PokemonCard* pokemonget(int index);
};

#endif