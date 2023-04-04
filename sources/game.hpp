
#pragma once

#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <vector>



namespace ariel
{
    class Game {
        Player p1,p2;
        // Card* cards;
        vector<Card> cards;
        bool check ;

    public:
        
        // methods
        void playTurn(); // outline method
        void printLastTurn(); // outline method
        void playAll(); // outline method
        void printWiner(); // outline method
        void printLog(); // outline method
        void printStats(); // outline method
        // Card* make_deck(); //outline method
        vector<Card> make_deck();

        // // Constructors:
        Game();
        Game(Player p_1,Player p_2);
        // ~Game();

    };
};
