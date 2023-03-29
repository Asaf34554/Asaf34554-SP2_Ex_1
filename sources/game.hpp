
#pragma once

#include <iostream>
#include "player.hpp"
#include "card.hpp"




namespace ariel
{
    class Game {
        Player p1,p2;

    public:
        
        // methods
        void playTurn(); // outline method
        void printLastTurn(); // outline method
        void playAll(); // outline method
        void printWiner(); // outline method
        void printLog(); // outline method
        void printStats(); // outline method
        

        // // Constructors:
        Game(){  //inline constructor
            p1 = Player("player1");
            p2 = Player("player2");
        }
        Game(Player p_1,Player p_2){ //inline constructor
            p1 = p_1;
            p2 =p_2;
        }

    };
};
