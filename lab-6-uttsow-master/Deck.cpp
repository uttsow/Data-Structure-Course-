#include <iostream>
#include <cstdlib>
#include "Card.h"
#include "Deck.h"
#include <deque>


using namespace std;

Deck::Deck(){

  aDeck={};
  for( int i = 1; i<5; i++){
    for( int j = 2; j < 15; j++){
      newCards = new Card(i, j);
      aDeck.push_back(newCards);
    }

  }



}

Deck::~Deck(){
 //cout<< "Des" << aDeck.size()<<endl;

  while(!empty()){
  // for(auto itr = bDeck.begin(); itr != bDeck.end(); itr++){
  //   cout<<bDeck.at(i)->getValue()<<endl;
    delete aDeck.front();
    aDeck.pop_front();

  }

}

Card Deck::draw(){

  //cout <<aDeck.size() << endl;
  //cout <<getInternal().size() << endl;
  Card *temp = aDeck.front();

  Card retVal = *temp;

// bDeck.push_back(temp);

  aDeck.pop_front();
  //aDeck.erase(aDeck.begin());

  delete temp;
  //delete aCard;
  // cout <<"VALUE: " <<newCards->getValue()<< endl;



  return retVal;


}

bool Deck::empty(){
  if(aDeck.size() == 0){
    //delete newCards;
    return true;
  //  delete aDeck;
  }else{
    return false;
  }
}

std::deque<Card *> & Deck::getInternal(){
  return (aDeck);
}

void Deck::shuffle(){


  // long j = rand() % 15+1;
  auto i = 0;

  for(auto it = aDeck.begin(); it !=aDeck.end(); it++){
    auto random = rand() % 14+1;
    auto temp = aDeck[i];
    aDeck[i] = aDeck[random];
    aDeck[random] = temp;


    i++;
  }



}
