
#include <iostream>

#include "card.hpp"
#include "player.hpp"

using namespace std;
using namespace ariel;

Player:: Player()
    :name("player") {}


Player:: Player(string pname)
    : name(pname),cardstaken (0),cardsleft (26) {}

Card Player:: get_card(){
    Card temp = this->cards.top();

    this->cards.pop();
    return temp;
}



