#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include "headers/card.h"

class PokemonCard : public Card{


    protected :
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<string,int,int,int>> attacks;

    public :
        PokemonCard(string namepokemon,string pokemontype, string familyname, int evolutionlevel, int maxhp, int eattack1,string firstattack,int dommage1,int eattack2,string secondattack, int dommage2);
        
        string typeget();
        int evget();
        int HPget();
        string fget();
        int attackdommageget(int indexatt);
        string attacksnameget(int indexatt);
        int maxhpget();

        void storEset(int a);
        void hpset(int newhp);
        void displayInfo() override;

};


#endif