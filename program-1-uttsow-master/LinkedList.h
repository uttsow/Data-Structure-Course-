#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Ant.h"

class Node{
public:

  Ant *ant;   //ant object to add to the Node
  Node(Ant *ant); //node constructor to make each new nodes with ant object
  Node * next;  //next element of the node;
  ~Node(); //node destructor to delete ant object to prevent memory leaks
};

class LinkedList{
private:
  Node* head;   //keeps track of head
  Node* temp;   //temporary node to keep track and patch up deletions
  Node* curr;   //current node tracker


public:

  Node* getHead();
  Node* getCurr();


  LinkedList(); //default constructor
  LinkedList(const LinkedList &); //copy LinkedList
  ~LinkedList();    //LinkedList destructor
  Ant* getAnt(int id);  //gets the ant object itself
  void addAnt(Ant *aAnt);  //adds ant object to the Node
  void deleteAnt(int id); //deltes the ant node

  void operator<<(Ant *aAnt){  //overloads left bit shift operator
    addAnt(aAnt);
  }
  void printList();

//returns number of nodes;
  int totalNodes();


};

#endif
