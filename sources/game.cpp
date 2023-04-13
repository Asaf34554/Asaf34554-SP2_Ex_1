#include <iostream>
#include <algorithm>
#include <random>
// #include <thread>
#include <vector>

#include "player.hpp"
#include "card.hpp"
#include "game.hpp"


using namespace ariel;

Game::Game()
{
    this->draw_rate = 0;
    this->p1_win_rate = 0;
    this->p2_win_rate =0;
    this->turn_num = 0;
    p1 = (new Player("player1"));
    p2 = (new Player("player2"));
    make_deck();
}

Game::Game(Player &p_1, Player &p_2)
{
    this->draw_rate = 0;
    this->p1_win_rate = 0;
    this->p2_win_rate =0;
    this->turn_num = 0;
    this->p1 = &p_1;
    this->p2 = &p_2;
    make_deck();
}

void Game::playTurn(){   
    if(&p1 == &p2){
        throw invalid_argument("cant start a game if the names of the players is the same.");
    }
    if(p1->getName() == p2->getName()){
        throw invalid_argument("cant start a game if the names of the players is the same.");
    }
    if (p1->stacksize() == 0){
        throw runtime_error("the players deck is empty!");
    }
    Card p1card = p1->get_card();
    Card p2card = p2->get_card();

    vector<Card> p1draw;
    vector<Card> p2draw;
    p1draw.push_back(p1card);
    p2draw.push_back(p2card);

    string s = "";
    int count = 2;
    while (true){
        count_turn();
        if (p1card.get_Card_Value() > p2card.get_Card_Value()){ // player 1 win
            s += p1->getName() + " played " + p1card.get_Card_Name() + " of " + p1card.get_Card_Type() + " " + p2->getName() + " played " + p2card.get_Card_Name() + " of " + p2card.get_Card_Type() + ". " + p1->getName() + " wins.";
            p1->set_cardsTaken(count);
            p1_set_won();
            p1->set_cards_won(s);
            break;
        }
        else if (p1card.get_Card_Value() < p2card.get_Card_Value()){ // player 2 win
            s += p1->getName() + " played " + p1card.get_Card_Name() + " of " + p1card.get_Card_Type() + " " + p2->getName() + " played " + p2card.get_Card_Name() + " of " + p2card.get_Card_Type() + ". " + p2->getName() + " wins.";
            p2->set_cardsTaken(count);
            p2_set_won();
            p2->set_cards_won(s);
            break;
        }
        else{ // draw

            //when the deck of the players is not empty
            set_draw();
            if (p1card.get_Card_Value() == p2card.get_Card_Value() && (p1->stacksize() != 0 || p2->stacksize() != 0)){
                if (p1->stacksize() >= 2 && p2->stacksize() >= 2){ 
                    // Draw and the have more then 1 card in the deck
                    count += 4;
                    Card p1setcard = p1->get_card();
                    Card p2setcard = p2->get_card();
                    p1draw.push_back(p1setcard);
                    p2draw.push_back(p2setcard);
                    p1card = p1->get_card();
                    p2card = p2->get_card();
                    p1draw.push_back(p1card);
                    p2draw.push_back(p2card);
                    s += p1->getName() + " played " + p1card.get_Card_Name() + " of " + p1card.get_Card_Type() + " " + p2->getName() + " played " + p2card.get_Card_Name() + " of " + p2card.get_Card_Type() + ". " + "Draw. ";
                }
                else{
                    count+=2;
                    p1card = p1->get_card();
                    p2card = p2->get_card();
                    p1draw.push_back(p1card);
                    p2draw.push_back(p2card);
                }

            }  
            // when the deck of the players is empty
            else{ 
                //when the last card of the players has the same value
                if(p1card.get_Card_Value() == p2card.get_Card_Value() && p1->stacksize() == 0 && p2->stacksize() == 0){
                    p1->set_cardsTaken(1);
                    p2->set_cardsTaken(1);
                    return;
                }
                else{
                    shuffle(p1draw.begin(), p1draw.end(), mt19937(random_device()()));
                    shuffle(p2draw.begin(), p2draw.end(), mt19937(random_device()()));
                    for(const auto &card : p1draw){
                        p1->set_card_stack(card);
                    }
                    for(const auto &card : p2draw){
                        p2->set_card_stack(card);
                    }
                    p1card = p1->get_card();
                    p2card = p2->get_card();
                }
            }
        }
    }
    this->last_turn = s;
    this->string_turns.push(s);
}

void Game::printLastTurn(){
    cout << this->last_turn << endl;
}

void Game::playAll(){   
    while (p1->stacksize() > 0 && p2->stacksize() > 0)
    {
        playTurn();
    }
}

void Game::printWiner(){
    if (p1->cardesTaken() > p2->cardesTaken()){
        cout << "And the winner is ...." << p1->getName() << "!!! (:"<<endl;  
    }
    else if (p1->cardesTaken() < p2->cardesTaken()){
        cout << "And the winner is ...." << p2->getName() << "!!! (:" << endl;
    }
    else{
        cout << "We Have a draw." << endl;
    }
}

void Game::printLog(){
    while (!(this->string_turns.empty())){
        string s = string_turns.front();
        cout << s << endl;
        string_turns.pop();
    }
}

void Game::printStats(){
    cout<<"\n\n Players Stats:  "<< endl;
    cout<<"The number of TURNS is: " << get_turn_num()<<endl;
    //p1 stats
    cout<<"\n **********Player 1********** \nName: "<< p1->getName() << "."<<endl;
    cout << "Number of cards he won: "<< p1->cardesTaken() << "."<<endl; 
    cout<< "Number of turns he won: " << get_p1_stats() << ".\nWin rate: " << (get_p1_stats()*100)/get_turn_num() << "%."<<endl;
    cout<< "Cards won: " <<endl;
    p1->print_cards_won();
    cout<< "Number of Draw Turn: " << get_draw_num() << "\n Draw rate: " << (get_draw_num()*100)/get_turn_num() <<"%."<<endl; 
    //p2 stats
    cout<<"\n **********Player 2********** \nName: "<< p2->getName() << "."<<endl;
    cout<<"Number of cards he won: " << p2->cardesTaken()<<"."<<endl;
    cout<< "Number of turns he won: " << get_p2_stats() <<".\nWin rate: " << (get_p2_stats() *100)/get_turn_num() << "%."<<endl;
    cout<< "Cards won: " <<endl;
    p2->print_cards_won();
    cout<< "Number of Draw Turn: " << get_draw_num() << "\nDraw rate: " << (get_draw_num()*100)/get_turn_num() <<"%."<<endl; 
}
  
void Game::make_deck(){
    vector<Card> deck;
    // Making a Deck
    for (int i = 0; i < 4; i++){
        for (int j = 1; j < 14; j++){
            
            
            Card card;
            switch (i)
            {
                case 0:
                card.set_Card_Type("Hearts");
                break;
                case 1:
                card.set_Card_Type("Diamonds");
                break;
                case 2:
                card.set_Card_Type("Clubs");
                break;
                case 3:
                card.set_Card_Type("Spades");
                break;
            }
            switch (j)
            {
                case 1:
                card.set_Card_Name("Ace");
                card.set_Card_Value(j);
                break;
                case 2:
                card.set_Card_Name("2");
                card.set_Card_Value(j);
                break;
                case 3:
                card.set_Card_Name("3");
                card.set_Card_Value(j);
                break;
                case 4:
                card.set_Card_Name("4");
                card.set_Card_Value(j);
                break;
                case 5:
                card.set_Card_Name("5");
                card.set_Card_Value(j);
                break;
                case 6:
                card.set_Card_Name("6");
                card.set_Card_Value(j);
                break;
                case 7:
                card.set_Card_Name("7");
                card.set_Card_Value(j);
                break;
                case 8:
                card.set_Card_Name("8");
                card.set_Card_Value(j);
                break;
                case 9:
                card.set_Card_Name("9");
                card.set_Card_Value(j);
                break;
                case 10:
                card.set_Card_Name("10");
                card.set_Card_Value(j);
                break;
                case 11:
                card.set_Card_Name("Jack");
                card.set_Card_Value(j);
                break;
                case 12:
                card.set_Card_Name("Queen");
                card.set_Card_Value(j);
                break;
                case 13:
                card.set_Card_Name("King");
                card.set_Card_Value(j);
                break;
            }
            deck.push_back(card);
        }
    }

    // Shuffle the deck
    shuffle(deck.begin(), deck.end(), mt19937(random_device()()));
    // Sending the Cards To the Players
    bool check = false;
    for (const auto &card : deck){
        if (check == false){
            check = true;
            p1->set_card_stack(card);
        }
        else{
            check = false;
            p2->set_card_stack(card);
        }
    }
}
