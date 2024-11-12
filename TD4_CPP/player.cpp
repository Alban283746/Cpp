#include "headers/player.h"

Player::Player(string name) : playerName(name){}

PokemonCard* Player::pokemonget(int index){
    return actionCards[index];
}

void Player::addCardToBench(Card* card){
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index_bench){
    if (index_bench >= 0 && index_bench < benchCards.size()) {
        actionCards.push_back(dynamic_cast<PokemonCard*>(benchCards[index_bench]));
        
        cout<<playerName<<" is activating a Pokemon Card: "<< benchCards[index_bench]->nameget()<<"\n";
        benchCards.erase(benchCards.begin()+index_bench);
    } else {
        std::cerr << "Index out of range: Cannot activate card.\n";
    }
}

void Player::attachEnergyCard(int index_bench,int index_action){
    cout<<playerName<<" is attaching "<< benchCards[index_bench]->nameget()<<" of type "<< dynamic_cast<EnergyCard*>(benchCards[index_bench])->typeget()<<" to the Pokemon " << actionCards[index_action]->nameget()<<"\n";
    benchCards.erase(benchCards.begin()+index_bench);
    actionCards[index_action]->storEset(1);
}

void Player::attack(int mypokemon,int otherpokemon,Player other,int attackuse){
    cout<<playerName<<" attacking "<< other.playerName<<"'s Pokemon "<< other.pokemonget(otherpokemon)->nameget()<<" with Pokemon "<<actionCards[mypokemon]->nameget()<<" with its attack: "<<actionCards[mypokemon]->attacksnameget(attackuse)<<endl;
    other.pokemonget(otherpokemon)->hpset(other.pokemonget(otherpokemon)->HPget() - actionCards[mypokemon]->attackdommageget(attackuse));
    if(other.pokemonget(otherpokemon)->HPget()<=0){
        cout<<"Pokemon "<<other.pokemonget(otherpokemon)->nameget()<<" is KO"<<endl;
        other.actionCards.erase(other.actionCards.begin() + otherpokemon);
    }else{
        cout<<"Pokemon "<<other.pokemonget(otherpokemon)->nameget()<<" is still alive"<<endl;
    }
}

void Player::useTrainer(int indexbench){
    cout<<playerName<<" is using the Trainer Card to "<<dynamic_cast<TrainerCard*>(benchCards[indexbench])->effectget()<<endl;
        for(int i=0;i<actionCards.size();i++){
        actionCards[i]->hpset(actionCards[i]->maxhpget());
    }
}

void Player::displayBench(){
    cout<<"Bench cards for Player "<<playerName<<" :"<<"\n";
    for(int i=0;i<benchCards.size();i++){
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction(){
    cout<<"Action cards for Player "<<playerName<<" :"<<"\n";
    for(int i=0;i<actionCards.size();i++){
        cout<<"Pokemon Card - Name : "<<actionCards[i]->nameget()<<", Type: "<<actionCards[i]->typeget()<<", Evolution level: "<<actionCards[i]->evget()<<" of the family "<<actionCards[i]->fget()<<", HP: "<<actionCards[i]->HPget()<<"\n";
        actionCards[i]->displayInfo();
    }
}