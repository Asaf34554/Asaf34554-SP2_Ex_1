#include <iostream>
#include <algorithm>
#include <random>
#include <thread>
#include <vector>

#include "player.hpp"
#include "card.hpp"
#include "game.hpp"

// methods
using namespace ariel;
Game::Game()
{
    p1 = (new Player("player1"));
    p2 = (new Player("player2"));
    make_deck();
}
Game::Game(Player &p_1, Player &p_2)
{
    // if(&p_1 == &p_2)
    // {
    //     throw invalid_argument("cant start a game if the names of the players is the same.");
    // }
    
    this->p1 = &p_1;
    this->p2 = &p_2;
    // if( &p1 == &p2)
    // {
    //     throw invalid_argument("cant start a game with the same player");
    // }
    make_deck();
}

void Game::playTurn()
{   
    if(&p1 == &p2)
    {
        throw invalid_argument("cant start a game if the names of the players is the same.");
    }
    if(p1->getName() == p2->getName())
    {
        throw invalid_argument("cant start a game if the names of the players is the same.");
    }
    if (p1->stacksize() == 0)
    {
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
    while (true)
    {
        if (p1card.get_Card_Value() > p2card.get_Card_Value())
        { // player 1 win
            s += p1->getName() + " played " + p1card.get_Card_Name() + " of " + p1card.get_Card_Type() + " " + p2->getName() + " played " + p2card.get_Card_Name() + " of " + p2card.get_Card_Type() + ". " + p1->getName() + " wins.";
            p1->set_cardsTaken(count);
            break;
        }
        else if (p1card.get_Card_Value() < p2card.get_Card_Value())
        { // player 2 win
            s += p1->getName() + " played " + p1card.get_Card_Name() + " of " + p1card.get_Card_Type() + " " + p2->getName() + " played " + p2card.get_Card_Name() + " of " + p2card.get_Card_Type() + ". " + p2->getName() + " wins.";
            p2->set_cardsTaken(count);
            break;
        }
        else  // draw
        { 
                //when the deck of the players is not empty
            if (p1card.get_Card_Value() == p2card.get_Card_Value() && (p1->stacksize() != 0 || p2->stacksize() != 0))
            {
                if (p1->stacksize() >= 2 && p2->stacksize() >= 2)
                { // Draw and the have more then 1 card in the deck
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
            else{   // when the deck of the players is empty
                

                    //when the last card of the players has the same value
                if(p1card.get_Card_Value() == p2card.get_Card_Value() && p1->stacksize() == 0 && p2->stacksize() == 0){
                    p1->set_cardsTaken(1);
                    p2->set_cardsTaken(1);
                    return;
                }
                else{
                        cout<<"shuffle the garbege"<<endl;
                        cout<<"p1 card: "<< p1card.get_Card_Name()<<" ,and the deck size is: " << p1->stacksize()<<endl;
                        cout<<"p2 card: "<< p1card.get_Card_Name()<<" ,and the deck size is: " << p2->stacksize() <<endl;

                        shuffle(p1draw.begin(), p1draw.end(), mt19937(random_device()()));
                        shuffle(p2draw.begin(), p2draw.end(), mt19937(random_device()()));
                        for(const auto &card : p1draw){
                            cout<<"the p1 for"<<endl;
                            p1->set_card_stack(card);
                        }
                        for(const auto &card : p2draw){
                            cout<<"the p2 for"<<endl;
                            p2->set_card_stack(card);

                        }
                        cout<<"after suufle back"<<endl;
                        p1card = p1->get_card();
                        p2card = p2->get_card();
                    
                }
            }
        }
    }


    this->last_turn = s;
    this->string_turns.push(s);
}
void Game::printLastTurn()
{
    cout << this->last_turn << endl;
}
void Game::playAll()
{   
    while (p1->stacksize() > 0 && p2->stacksize() > 0)
    {
        playTurn();
    }
}
void Game::printWiner()
{
    if (p1->cardesTaken() > p2->cardesTaken())
    {
        cout << "And the winner is ...." << p1->getName() << "!!! (:"
             << " he/she won " << p1->cardesTaken() << ". the loser is : " << p2->getName() << ". and he won : " << p2->cardesTaken() << endl;
    }
    else if (p1->cardesTaken() < p2->cardesTaken())
    {
        cout << "And the winner is ...." << p2->getName() << "!!! (:"
             << " he/she won " << p2->cardesTaken() << ". the loser is : " << p1->getName() << ". and he won : " << p1->cardesTaken() << endl;
    }
    else
    {
        cout << "We Have a draw." << endl;
    }
}
void Game::printLog()
{
    int i = 0;
    while (!(this->string_turns.empty()))
    {
        string s = string_turns.front();
        cout << s << endl;
        string_turns.pop();
    }
}
void Game::printStats()
{
}
void Game::make_deck()
{
    vector<Card> deck;
    // Making a Deck
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 14; j++)
        {
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

    // Print the deck
    //  for (const auto& card : deck) {
    //      std::cout << "Card: " << card.get_Card_Name() << " of " << card.get_Card_Type() << ", value: " << card.get_Card_Value() << std::endl;
    //  }
    //  cout<<"size: "<< deck.size() <<endl;

    // Sending the Cards To the Players
    bool check = false;
    for (const auto &card : deck)
    {
        if (check == false)
        {
            check = true;
            p1->set_card_stack(card);
            // p1->set_stacksize();
        }
        else
        {
            check = false;
            p2->set_card_stack(card);
            // p2->set_stacksize();
        }
    }
    cout << "p1 stacksize = " << p1->stacksize() << "  p2 stacksize = " << p2->stacksize() << endl;
}
