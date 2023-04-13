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
        stack<string> cards_won;     


    public:
              
        //methods
        int stacksize()const; //inline method
        int cardesTaken()const;// inline method
        std::string getName()const;//inline method
        
        void set_card_stack(Card const &card){ //inline method
            cards.push(card);
            ++cardsleft;
        } 

        Card get_card(); //outline method
        void set_cardsTaken(int value){cardstaken +=value;} //inline method
        void set_dec_stacksize(){--cardsleft;} //inline method
        void set_cards_won(const string &win_card){cards_won.push(win_card);}
        void print_cards_won();
        void set_name(string pname); //outline method

        // Constructors:
        Player();
        Player(std::string pname);
        Player(const Player& player); // copy constructor

        // Destructor:
        ~Player(){} 
        Player& operator=(const Player& other);
        Player(Player&& other) noexcept;
        Player& operator=(Player&& other) noexcept;
    };
};
