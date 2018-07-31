#include <cstdlib>
#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "Heap.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

//creates empty vector
Heap::Heap(){
  players = {};
}

Heap::Heap(string filename){
  ifstream afile(filename);
  string name;
  string budgetNum;
  if(afile.is_open()){
    while(getline(afile, name)){  //gets the name;

      getline(afile, budgetNum); //gets the budget
      Player tempo(name, stoi(budgetNum));
      addPlayer(tempo);
    }
  }
}

Heap::Heap(const Heap &copy){ //copy constructor
  for(unsigned int i = 0; i< copy.size(); i++){
    players.push_back((copy.getArray())[i]);
  }
}




//Heapify process;
void Heap::heapify(){
  int numPlayers = players.size();
  for (int i=(numPlayers-2)/2; i>=0; i--)
		siftdown(i);
}


//return left child;
int Heap::left(unsigned int pos){
  if(2*pos + 1 >= players.size()){
    return -1;
  }
  int value = (2*pos) + 1;
  return value;
}


//sifting down to maintain heap
void Heap::siftdown(unsigned int pos){
	if (((signed)pos < 0) || (pos >= players.size())) return; // Illegal position
	while (!isLeaf(pos)){ //Keep swapping until you get to a leaf
		int j = left(pos); //Get left child
    if(j == -1) return;
    unsigned leftChild = j;
		if (leftChild+1 <= players.size() -1 && (players[leftChild].getBudget() < players[leftChild+1].getBudget())){
      leftChild++; // leftchild is now index of child with greater priority
    }
		if (players[pos].getBudget() < players[leftChild].getBudget()){
        swap(players[pos], players[leftChild]);
      }
      else return;
		pos = leftChild;  // Move down
	}
}

//return true only when pos is out of bound from vector;
bool Heap::isLeaf(unsigned int pos){
  unsigned int child = 2*pos + 1;
  unsigned int rightChild = 2*pos + 2;
  if(child >= players.size() && rightChild >= players.size()){
    return true;
  }
  return false;
}

void Heap::addPlayer(Player newPlayer){
  players.push_back(newPlayer);
  heapify();  //have to heapify when you add new players
}


//remove the players with the highest budget and returns player;
Player Heap::getPlayer(){
  heapify();
  swap(players[0], players[players.size()-1]);
  Player baller = players.back();
  players.pop_back();
  heapify();
  return baller;
}

vector<Player> Heap::getArray() const{
  return players;
}

bool Heap::empty(){
  if(players.size() == 0) return true;
  return false;
}

unsigned int Heap::size() const {
  return players.size();
}
