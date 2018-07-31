#ifndef HEAP_H
#define HEAP_H
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>


class Heap{
private:
  std::vector<Player> players;

  void heapify();
  void siftdown(unsigned int pos);
  bool isLeaf(unsigned int);
  int left(unsigned int); //gets left child;

public:

  Heap();   //default
  Heap(std::string filename); //2nd consturctor

  Heap(const Heap &copy); //copy constructor
  void addPlayer(Player newPlayer);
  Player getPlayer();
  std::vector<Player> getArray() const;
  bool empty();
  unsigned int size() const;

};

#endif
