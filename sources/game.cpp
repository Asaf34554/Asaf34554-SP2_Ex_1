#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

#include "player.hpp"
#include "card.hpp"
#include "game.hpp"


// methods
using namespace ariel;
Game::Game(){  //inline constructor
    this->p1 = Player("player1");
    this->p2 = Player("player2");
    this->cards = make_deck();
    int t = sizeof(cards);
    for (const auto& card : cards) {
        std::cout << "Card: " << card.get_Card_Name() << " of " << card.get_Card_Type() << ", value: " << card.get_Card_Value() << std::endl;
    }
}
Game::Game(Player p_1,Player p_2){ //inline constructor
    this->p1 = p_1;
    this->p2 =p_2;
    this->cards = make_deck();
    int t = sizeof(this->cards);
    for (const auto& card : cards) {
        std::cout << "Card: " << card.get_Card_Name() << " of " << card.get_Card_Type() << ", value: " << card.get_Card_Value() << std::endl;
    }

}

void Game:: playTurn(){

} 
void Game:: printLastTurn(){

} 
void Game:: playAll(){

} 
void Game:: printWiner(){

} 
void Game:: printLog(){

} 
void Game:: printStats(){

} 
// Card* Game:: make_deck(){
//     Card* tcards = new Card[52];
//     int index = 0;
//     for(int i=0; i<4; i++) {
//             for(int j=1; j<14; j++) {
//                 Card tcard;
//                 if(i==0)tcard.set_Type("HEARTS");
//                 if(i==1)tcard.set_Type("DIAMONDS");
//                 if(i==2)tcard.set_Type("CLUBS");
//                 if(i==3)tcard.set_Type("SPADES");
//                 if(j==1) {
//                     tcard.set_Name("ACE");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==2) {
//                     tcard.set_Name("TWO");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==3) {
//                     tcard.set_Name("THREE");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==4) {
//                     tcard.set_Name("FOUR");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==5) {
//                     tcard.set_Name("FIVE");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==6) {
//                     tcard.set_Name("SIX");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==7) {
//                     tcard.set_Name("SEVEN");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==8) {
//                     tcard.set_Name("EIGHT");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==9) {
//                     tcard.set_Name("NINE");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==10) {
//                     tcard.set_Name("TEN");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==11) {
//                     tcard.set_Name("JACK");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==12) {
//                     tcard.set_Name("QUEEN");
//                     tcard.set_Value(j);
//                 }
//                 else if(j==13) {
//                     tcard.set_Name("KING");
//                     tcard.set_Value(j);
//                 }
//                 tcards[index]=tcard;
//                 index++;
//             }
            
//     }
//     std::random_device rd;
//     std::mt19937 g(rd());
//     std::shuffle(tcards, tcards + 52, g);
//     for(int i =0;i<52;i++){
//         cout << "Card: " << tcards[i].get_Name()<<endl;
//     }
//     cout<< "value: " << sizeof(tcards)<<endl;
//     return tcards;

// }
vector<Card> Game::make_deck() {
    vector<Card> deck;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 14; j++) {
            Card card;
            switch (i) {
                case 0:
                    card.set_Card_Type("HEARTS");
                    break;
                case 1:
                    card.set_Card_Type("DIAMONDS");
                    break;
                case 2:
                    card.set_Card_Type("CLUBS");
                    break;
                case 3:
                    card.set_Card_Type("SPADES");
                    break;
            }
            switch (j) {
                case 1:
                    card.set_Card_Name("ACE");
                    card.set_Card_Value(j);
                    break;
                case 2:
                    card.set_Card_Name("TWO");
                    card.set_Card_Value(j);
                    break;
                case 3:
                    card.set_Card_Name("THREE");
                    card.set_Card_Value(j);
                    break;
                case 4:
                    card.set_Card_Name("FOUR");
                    card.set_Card_Value(j);
                    break;
                case 5:
                    card.set_Card_Name("FIVE");
                    card.set_Card_Value(j);
                    break;
                case 6:
                    card.set_Card_Name("SIX");
                    card.set_Card_Value(j);
                    break;
                case 7:
                    card.set_Card_Name("SEVEN");
                    card.set_Card_Value(j);
                    break;
                case 8:
                    card.set_Card_Name("EIGHT");
                    card.set_Card_Value(j);
                    break;
                case 9:
                    card.set_Card_Name("NINE");
                    card.set_Card_Value(j);
                    break;
                case 10:
                    card.set_Card_Name("TEN");
                    card.set_Card_Value(j);
                    break;
                case 11:
                    card.set_Card_Name("JACK");
                    card.set_Card_Value(j);
                    break;
                case 12:
                    card.set_Card_Name("QUEEN");
                    card.set_Card_Value(j);
                    break;
                case 13:
                    card.set_Card_Name("KING");
                    card.set_Card_Value(j);
                    break;
            }
            deck.push_back(card);
        }
    }
    shuffle(deck.begin(), deck.end(), mt19937(random_device()()));
    for (const auto& card : deck) {
        std::cout << "Card: " << card.get_Card_Name() << " of " << card.get_Card_Type() << ", value: " << card.get_Card_Value() << std::endl;
    }
    cout<<"size: "<< deck.size() <<endl;
    return deck;
}
