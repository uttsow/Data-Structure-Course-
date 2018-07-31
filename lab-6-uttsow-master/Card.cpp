#include <iostream>
#include <cstdlib>
#include "Deck.h"
#include "Card.h"
#include <deque>

using namespace std;

Card::Card(int aSuit, int aValue){

  if(aSuit < 1 || aSuit > 4 || aValue < 2 || aValue >14 ){
    suit = 1;
    value = 2;
  }else{
    suit = aSuit;
    value = aValue;
  }
}


int Card::getValue(){
  return value;
}

int Card::getSuit(){
  return suit;
}

bool Card::operator==(const Card &other){
  if(other.value == this->value){
    return true;
  }
  return false;
}
