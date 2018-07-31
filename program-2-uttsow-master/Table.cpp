#include <iostream>
#include <cstdlib>
#include "Table.h"
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Heap.h"
#include "Player.h"

using namespace std;

Table::Table(int num_seats, int ante){
  this->num_seats = num_seats;
  this->ante = ante;
  winningAmount = 0;
  playing = {};
  numRound = 0;
}

bool Table::emptySeat(){
  if((unsigned)num_seats > playing.size()) return true;
  return false;
}

vector<Player> Table::playRound(){
  numRound++;
  Deck aDeck;
  vector<Player> losers = {};
  for(int i = 0; i < 4; i++){
    aDeck.shuffle();    //shuffle a new Deck 4 times
  }

  int i = 0;
  for(auto it = playing.begin(); it != playing.end(); it++){
    if(playing.at(i).bet(ante)){
      playing.at(i).hand = aDeck.draw();  //gives the players a card from shuffled decl
      winningAmount +=ante;
    }
    i++;
  }

  // winner = playing.at(0);  //choose the first player as a potential winner.
  int y = 0;
  winner = playing.at(0);
  for(auto it = playing.begin(); it != playing.end(); it++){
    if(playing.at(y).hand > winner.hand){
      losers.push_back(winner); //picked winner was not a Winner
      winner = playing.at(y); //set a new winner.
    }
    // if equal;
    if(playing.at(y).hand == winner.hand){
      playing.at(y).hand = aDeck.draw();
      if(playing.at(y).hand > winner.hand){
        losers.push_back(winner);
        winner = playing.at(y);
      }
    }
    y++;
  }

  winner.collectWinning(winningAmount);


  playing.clear(); //clears board;
  playing.push_back(winner); //keeps the winner in the game;

  //losers who still have money
  // for(unsigned int i = 0; i <losers.size(); i++){
  //   if(losers[i].getBudget() >= ante){
  //     playing.push_back(losers[i]);
  //   }
  // }

  // if(playing.size() == 1){
  //   printWinner();
  // }

  return losers;
}

void Table::addPlayer(Player p){
  playing.push_back(p);
}

int Table::getRound(){
  return numRound;
}

void Table::printWinner(){
  cout << "====" << playing[0].getName() << "'s Hand====" << endl;
  cout << "Suit: " << playing[0].hand.getSuit() << endl;
  cout << "=========================" << endl;
  cout << playing[0].getName() << " has won in round " << getRound() << endl;
}
