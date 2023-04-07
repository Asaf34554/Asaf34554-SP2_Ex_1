
#pragma once

#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <queue>



namespace ariel
{
    class Game {
        Player *p1,*p2;
        queue<string> string_turns;
        bool check ;

    public:
        
        // methods
        void playTurn(); // outline method
        void printLastTurn(); // outline method
        void playAll(); // outline method
        void printWiner(); // outline method
        void printLog(); // outline method
        void printStats(); // outline method
        void make_deck(); //outline method

        // // Constructors:
        Game();
        Game(Player &p_1,Player &p_2);
        // ~Game();

    };
};
