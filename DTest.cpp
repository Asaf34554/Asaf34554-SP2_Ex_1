#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

#include "doctest.h"

#define START_NUM_OF_CARDS   26 


TEST_CASE("Test 1") {
    Player p1("Alice");
    Player p2 ("Bob");
    CHECK((p1.getName() == "Alice" && p2.getName() == "Bob")); //check that he initialize the names correctly
    Game game(p1,p2);
    CHECK((p1.stacksize() == START_NUM_OF_CARDS && p2.stacksize() == START_NUM_OF_CARDS)); //check that after the start of the game they have 26 cards
    CHECK((p1.cardesTaken() == 0 && p2.cardesTaken()  == 0)); // check if the cardsTaken is 0
    for(int i=0;i<5;i++){
        game.playTurn();
        
        CHECK((p1.stacksize() >= 0 && p2.stacksize() >= 0)); //check that after every turn the players play,they dont have less then 0 cards 
        CHECK((p1.stacksize() == p2.stacksize())); // check that the number of every play the num of players cards are the same
    }
    game.printLastTurn();
    CHECK_THROWS(game.printLastTurn()); // check there is no error in the printLastTurn func;

    game.playAll();
    CHECK((p1.stacksize() == 0 && p2.stacksize() == 0)); // check that after the last turn the stak size of the players is 0
    CHECK_THROWS(game.printWiner()); // check there is no error and if the play 


    stringstream printcheck;
    streambuf* printbuf = cout.rdbuf(); // save cout buffer
    cout.rdbuf(printcheck.rdbuf()); // redirect cout to print

    game.printWiner(); // call the function 
    
    string printwin = printcheck.str();
    bool check = (printwin.compare("Alice") && printwin.compare("Bob"));

    cout.rdbuf(printbuf); // restore cout buffer
    CHECK(check);//check that the name of the winner is one of the playeres that initialize
}
