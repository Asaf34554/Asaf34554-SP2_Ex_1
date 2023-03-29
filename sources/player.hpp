#pragma once

#include <iostream>
#include "card.hpp"


namespace ariel
{
    class Player {

        std::string name;
        int cardsleft;
        int cardstaken;


    public:
        //methods
        int stacksize(){return cardsleft; } //inline method
        int cardesTaken(){return cardstaken; } // inline method
        std::string getName(){return name; } //inline method
        
        // // Constructors:
        Player(){}//inline constructor
        Player(std::string pname){name = pname;}     // inline constructor
            


    };
};