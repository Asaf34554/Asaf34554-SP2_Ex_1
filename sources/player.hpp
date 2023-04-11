#pragma once

#include <iostream>
#include <stack>
#include "card.hpp"


namespace ariel
{
    class Player {

        std::string name;
        int cardsleft;
        int cardstaken;
        stack<Card> cards;        


    public:
              
        //methods
        int stacksize(){return cardsleft; } //inline method
        int cardesTaken(){return cardstaken; } // inline method
        std::string getName(){return name; } //inline method
        void set_card_stack(Card card){
            cards.push(card);
            ++cardsleft;} //inline method
        Card get_card(); //outline method
        // void set_stacksize(){} //inline method
        void set_cardsTaken(int i){cardstaken +=i;} //inline method
        void set_dec_stacksize(){--cardsleft;} //inline method
        
        
        
        // Constructors:
        Player(); //outline constructor
        Player(std::string pname);  // outline constructor
        Player(Player &p); // outline constructor
    };
};