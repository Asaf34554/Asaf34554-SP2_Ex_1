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
        
        // // Constructors:
        Player();
        Player(std::string pname);    // inline constructor
        void set_card_stack(Card card){cards.push(card);} //inline method
        Card get_card();
        
        

    };
};