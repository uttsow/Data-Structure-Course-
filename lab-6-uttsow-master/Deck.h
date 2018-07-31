#ifndef DECK_H
#define DECK_H
#include <deque>
#include "Card.h"



class Deck{


private:
  std::deque<Card*> aDeck;
  // std::deque<Card*> bDeck;
  Card *newCards;

public:
  Deck();
  ~Deck();
  Card draw();
  bool empty();
  std::deque<Card *> & getInternal();
  void shuffle();
};

#endif
