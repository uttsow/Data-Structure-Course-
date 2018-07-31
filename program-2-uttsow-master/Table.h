#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Card.h"
#include "Heap.h"
#include "Deck.h"
#include <vector>


class Table{
private:
  int num_seats;
  int ante;

  std::vector<Player> playing; //vector for all playing players tracker
  int winningAmount;
  int numRound;
public:
  Player winner; //winning player
  Table(int num_seats, int ante); //consturctor
  bool emptySeat();
  std::vector<Player> playRound();
  void addPlayer(Player p);
  void printWinner();

  int getRound();

};

#endif
