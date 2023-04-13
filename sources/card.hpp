#pragma once
#include <iostream>

using namespace std;



namespace ariel
{   
    class Card {
        int valueOfCard;
        string type,name;
        
    public:
    //constructor and destructor
        Card(); //outlind constructor
    // methods
        string get_Card_Type()const{return type;} // inline method
        int get_Card_Value()const{return valueOfCard;} // inline method
        string get_Card_Name()const{return name;} // inline method
        void set_Card_Value(int value); // outline method
        void set_Card_Type(string type); //outline method
        void set_Card_Name(string name); //outline method
};  
};
