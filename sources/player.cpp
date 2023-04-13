
#include <iostream>
#include <stack>

#include "card.hpp"
#include "player.hpp"

using namespace std;
using namespace ariel;


Player:: Player() : name("player"),cardstaken (0),cardsleft (0) {}

Player:: Player(string pname) : name(pname),cardstaken (0),cardsleft (0) {}

Player:: Player(const Player &player){
    this->name = player.name;
    this->cardsleft = player.cardsleft;
    this->cardstaken = player.cardsleft;
    this->cards = player.cards;
}

int Player:: stacksize()const{return cardsleft;}

int Player:: cardesTaken()const{return cardstaken;}

string Player:: getName()const{return name;}

Card Player:: get_card(){
    set_dec_stacksize();
    Card temp = this->cards.top();
    this->cards.pop();
    return temp;
}

void Player:: print_cards_won(){
    while (!(this->cards_won.empty())){
        string s = cards_won.top();
        cout << s << endl;
        cards_won.pop();
    }

}
