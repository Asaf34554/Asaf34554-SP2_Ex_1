
#include <iostream>

#include "card.hpp"
#include "player.hpp"

using namespace std;
using namespace ariel;


Player:: Player()
    : name("player"),cardstaken (0),cardsleft (0) {}

Player:: Player(string pname)
    : name(pname),cardstaken (0),cardsleft (0) {}

Player:: Player(Player &p){
    this->name = p.name;
    this->cardsleft = p.cardsleft;
    this->cardstaken = p.cardsleft;
    this->cards = p.cards;
}
Card Player:: get_card(){
    set_dec_stacksize();
    Card temp = this->cards.top();

    this->cards.pop();
    return temp;
}




