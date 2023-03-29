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




TEST_CASE("Test for printWiner") {
    Player p1("Alice");
    Player p2 ("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printWiner()); //check there is an error when we call this method before we end the game
    game.playAll();
    CHECK_NOTHROW(game.printWiner()); // check there is no error

    stringstream printcheck;
    streambuf* printbuf = cout.rdbuf(); // save cout buffer
    cout.rdbuf(printcheck.rdbuf()); // redirect cout to print

    game.printWiner(); // call the function 
    
    string printwin = printcheck.str();
    bool check = (printwin.compare("Alice") && printwin.compare("Bob"));

    cout.rdbuf(printbuf); // restore cout buffer
    CHECK(check);//check that the name of the winner is one of the playeres that initialize    

}
TEST_CASE("Test for stacksize"){
    Player p1("Alice");
    Player p2 ("Bob");
    Game game(p1,p2);
    CHECK((p1.stacksize() == START_NUM_OF_CARDS && p2.stacksize() == START_NUM_OF_CARDS)); //check that after the start of the game they have 26 cards
    for(int i=0;i<5;i++){
        game.playTurn();
        
        CHECK((p1.stacksize() >= 0 && p2.stacksize() >= 0)); //check that after every turn the players play,they dont have less then 0 cards 
        CHECK((p1.stacksize() == p2.stacksize())); // check that the number of every play the num of players cards are the same
    }
    game.printLastTurn();
    CHECK_NOTHROW(game.printLastTurn()); // check there is no error in the printLastTurn func;

    game.playAll();
    CHECK((p1.stacksize() == 0 && p2.stacksize() == 0)); // check that after the last turn the stak size of the players is 0
    CHECK_NOTHROW(game.printWiner()); // check there is no error and if the play 
}
TEST_CASE("Test for cardesTaken"){
    Player p1("Alice");
    Player p2 ("Bob");
    Game game(p1,p2);
    CHECK((p1.cardesTaken() == 0 && p2.cardesTaken()  == 0)); // check if the cardsTaken is 0
    for(int i=0;i<5;i++){
        game.playTurn();
        CHECK((p1.cardesTaken() > 0 ||  p2.cardesTaken() > 0 ));//check after every turn if the amount of the cards that has been taken is more then 0
    }
    game.printLastTurn();

    game.playAll();
    CHECK(( p1.cardesTaken() <=52 && p2.cardesTaken() <= 52)); // check that is no more then 52 card in the winner hand
    CHECK((p1.cardesTaken() > START_NUM_OF_CARDS || p2.cardesTaken() > START_NUM_OF_CARDS)); // check that is more then 26 cards in the winner side
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 50); //check that is 52 cardes after the game end
    

}

TEST_CASE("Test constructors") {
    bool check;
    Player p1("Alice");
    CHECK((p1.getName() == "Alice" && p1.cardesTaken() == 0 && p1.stacksize() == 0)); // check that he is initialize the player well
    Player p2 ("Bob");
    CHECK((p2.getName() == "Bob" && p2.cardesTaken() == 0 && p2.stacksize() == 0)); // check that he is initialize the player well
    Game game(p1,p2);
    CHECK((p1.cardesTaken() == 0 && p2.cardesTaken() == 0 && p1.stacksize() == 26 && p2.stacksize() == 26)); //check the the cnstructor initiallize well the players
   
}
TEST_CASE("Test platALL"){
    Player p1("Alice");
    Player p2 ("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playAll()); // check that the playAll func dont throw an error

}

TEST_CASE("Test printLog"){
    Player p1("Alice");
    Player p2 ("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printLog()); //check that is no errors in the printLog func

}
TEST_CASE("Test printstats"){
    Player p1("Alice");
    Player p2 ("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_NOTHROW(game.printStats()); //check that is no errors in the printsStats func
}
TEST_CASE("Test printLastTurn"){
    Player p1("Alice");
    Player p2 ("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn()); // check that the printLastTurn is throw null
    game.playTurn();
    CHECK_NOTHROW(game.printLastTurn()); //check that is no errors in the printLastTurn func
    game.playAll();
    CHECK_NOTHROW(game.printLastTurn()); //check that is no errors in after the last turn was played printLastTurn func
}
