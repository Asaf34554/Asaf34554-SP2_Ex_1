
#include <iostream>
#include "card.hpp"
using namespace std;
using namespace ariel;


Card:: Card(){
    valueOfCard = 0;
    type = "None";
    name = "None";
}
void Card:: set_Card_Value(int value){
    this->valueOfCard = value;
}

void Card:: set_Card_Type(string type){
    this->type = type;
}

void Card:: set_Card_Name(string name){
    this->name = name;
}
