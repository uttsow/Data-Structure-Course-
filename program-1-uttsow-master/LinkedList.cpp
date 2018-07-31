#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Ant.h"


using namespace std;
//sets up the Node Constructor;
Node::Node(Ant* aAnt){
  ant = aAnt;
  next = NULL;
}

Node::~Node(){
// cout<<"this the destructor" << endl;


}

LinkedList::LinkedList(){
  head = NULL;
  temp = NULL;
  curr = NULL;
}

Node* LinkedList::getHead(){

  return head;

}
Node* LinkedList::getCurr(){
  return curr;
}
//Copy Constructor to copy the LinkedList
LinkedList::LinkedList(const LinkedList &aCopy){

  if(aCopy.head == NULL){
    head = NULL;
    temp = NULL;
    curr = NULL;
  }else{
    head = new Node(NULL);
    head->ant = aCopy.head ->ant;
    Node *holder1 = head;
    Node *mover = aCopy.head -> next;
    while(mover !=NULL){
      holder1 -> next = new Node(NULL);
      holder1 = holder1->next;
      holder1 ->ant = mover->ant;
      mover = mover -> next;
    }
    holder1 ->next = NULL;
  }


}

// Linkedlist node destructor to delete all ants first, then the node;
LinkedList::~LinkedList(){
  Node* deleter = head;
  while(deleter !=NULL){
    Node *holder = deleter->next;
    delete deleter;
    deleter = holder;
  }
  head = NULL;
  temp = NULL;
  curr = NULL;

  cout << "linked list destructor" << endl;

}

void LinkedList::addAnt(Ant *aAnt){
  //Creates new node and sets the next node to be null. means its at the end of the list;
  Node* newAnt = new Node(aAnt);
  newAnt->next = NULL;

//checks if head is not null. means a linkedlist already exists
  if(head !=NULL){
    curr = head;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = newAnt;    //after while loop, curr now points to null.
                            //so it sets the newAnt node to curr->next;

  }else{
    head = newAnt;      //this statmenent says that the head is already null and this is then
                        //first element of the list.
  }
//  cout<< "Inserted Ant: "<< newAnt->ant->getID() << endl;
}

//deltes ant node based on the id that was sent
void LinkedList::deleteAnt(int id){
  Node* delPtr = NULL;
  curr = head;
  temp = head;    //curr and temp will work together to patch the list after deletion

  while(curr != NULL && curr->ant->getID() != id){
    temp = curr;
    curr = curr->next;
  }
  if(curr == NULL){   //if curr's null, ant doesnt exist
    delete delPtr;    //deltes unused delPtr;
    return;
  }
  else{
    delPtr = curr; //since curr now points to the ant id, we can delete it
    curr = curr->next;
    temp->next = curr;    //patches the list; and leaves delPtr dangling
    if(delPtr == head){   //if the delPtr point to the head, move the head and make temp null;
      head = head->next;
      temp = NULL;
    }
  //  cout<<"deleted ANt: " << delPtr->ant->getID()<< endl;

    delete delPtr;
   }

}

Ant* LinkedList::getAnt(int id){
  if(head == NULL){
    return NULL;
  }
  curr = head;
  while(curr->ant->getID() != id){
    curr = curr->next;
  }

//  cout <<curr->ant->getID()<<endl;

  return curr->ant;
}

void LinkedList::printList(){
  curr = head;
  while(curr != NULL){
    cout << curr->ant->getID() << endl;
    curr = curr-> next;
  }
}

int LinkedList::totalNodes(){
  temp = head;
  int counter = 1;    //initalizes it to 1 for the head;
  while(temp->next != NULL){
    counter++;
    temp = temp->next;
  }
  return counter;
}
