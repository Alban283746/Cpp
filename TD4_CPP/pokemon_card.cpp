#include "headers/pokemon_card.h"

PokemonCard::PokemonCard(string namepokemon,string pokemontype, string familyname, int evolutionlevel, int maxhp, int eattack1,string firstattack,int dommage1,int eattack2,string secondattack, int dommage2){
    cardName = namepokemon;
    pokemonType = pokemontype;
    familyName = familyname;
    evolutionLevel = evolutionlevel;
    maxHP = maxhp;
    hp = maxhp;
    attacks = {tuple<string,int,int,int>(firstattack,eattack1,dommage1,0),tuple<string,int,int,int>(secondattack,eattack2,dommage2,0)};

};

string PokemonCard::typeget(){
    return pokemonType;
}

int PokemonCard::evget(){
    return evolutionLevel;
}

int PokemonCard::HPget(){
    return hp;
}

string PokemonCard::fget(){
    return familyName;
}

void PokemonCard::storEset(int a){
    for(int i=0;i<attacks.size();i++){
        get<3>(attacks[i]) += a;
    }
}

void PokemonCard::hpset(int newhp){
    hp=newhp;
}

int PokemonCard::attackdommageget(int indexatt){
    return get<2>(attacks[indexatt]);
}

string PokemonCard::attacksnameget(int indexatt){
    return get<0>(attacks[indexatt]);
}

int PokemonCard::maxhpget(){
    return maxHP;
}

void PokemonCard::displayInfo(){
    
    cout<< "Attacks : " << "\n";
    cout<< "Attack#0 " << "\n";
    cout<< "Attack cost : " << get<1>(attacks[0]) << "\n";
    cout<< "Attack current energy storage : " << get<3>(attacks[0]) << "\n";
    cout<< "Attack description : " << get<0>(attacks[0]) << "\n";
    cout<< "Attack damage : " << get<2>(attacks[0]) << "\n";
    cout<< "Attack#1 " << "\n";
    cout<< "Attack cost : " << get<1>(attacks[1]) << "\n";
    cout<< "Attack current energy storage : " << get<3>(attacks[1]) << "\n";
    cout<< "Attack description : " << get<0>(attacks[1]) << "\n";
    cout<< "Attack damage : " << get<2>(attacks[1]) << "\n";
};