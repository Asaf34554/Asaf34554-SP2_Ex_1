
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
        string last_turn;
        int draw_rate,p1_win_rate,p2_win_rate,turn_num;

    public:
        
        // methods
        void playTurn(); // outline method
        void printLastTurn(); // outline method
        void playAll(); // outline method
        void printWiner(); // outline method
        void printLog(); // outline method
        void printStats(); // outline method
        void make_deck(); //outline method
        void set_draw(){draw_rate++;} //inline method
        void p1_set_won(){p1_win_rate++;} //inline method
        void p2_set_won(){p2_win_rate++;} //inline method
        void count_turn(){turn_num++;} //inline method
        int get_draw_num()const{return draw_rate;} //inline method
        int get_p1_stats()const{return p1_win_rate;} //inline method
        int get_p2_stats()const{return p2_win_rate;} //inline method
        int get_turn_num()const{return turn_num;} //inline method
        
        
        // // Constructors:
        Game(); //outline constructor
        Game(Player &p_1,Player &p_2); //outlineconstructor

    };
};
