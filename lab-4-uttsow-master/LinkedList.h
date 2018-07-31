#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>


template <class T>
class Node{
public:

  Node * next;  //next element of the node;
  T data;
};

template <class T>
class LinkedList{
  template<class type> friend class Queue;  //allows queue to use this class
private:
  Node<T>* head;   //keeps track of head
  Node<T>* temp;   //temporary node to keep track and patch up deletions
  Node<T>* curr;   //current node tracker


public:

  Node<T>* getHead();
  Node<T>* getCurr();


  LinkedList(); //default constructor
  LinkedList(const LinkedList<T> &); //copy LinkedList
  ~LinkedList();    //LinkedList destructor
  void insert(T data);
  T read();
  bool empty();
  bool remove(T data);

  void operator<<(T data){
    insert(data);
  }
  void operator == (T data){
    remove(data);
  }


};



//LinkedList construtor
template <class T>
LinkedList<T>::LinkedList(){
  head = NULL;
  temp = NULL;
  curr = NULL;
}


//LinkedList copy constructor
template <class T>
LinkedList<T>::LinkedList( const LinkedList<T> &copy){
  head = new Node<T>;
  head -> data = copy.head ->data;
  Node<T> *p1 = head;
  Node<T> *p2 = copy.head -> next;
  while(p2->next != NULL){
    p1 -> next = new Node<T>;
    p1 = p1 -> next;
    p1 ->data = p2->data;
    p2=p2 -> next;
  }
  p1 -> next = NULL;
}


//destructor
template <class T>
LinkedList<T>::~LinkedList(){
  Node<T>* deleter = head;
  while(deleter !=NULL){
    Node<T> *holder = deleter->next;
    delete deleter;
    deleter = holder;
  }
  head = NULL;
  temp = NULL;
  curr = NULL;

  // cout << "linked list destructor" << endl;

}





template <class T>
void LinkedList<T>::insert(T addData){
  Node<T>* n = new Node<T>;
  n->next = NULL;   //sets next node pointer to null. end of list.
  n->data = addData;  //adds data
  if(head != NULL){ //checks if head is not else, then it sets current pointer to head;
    curr = head;
    while(curr->next != NULL){ //checks if it is at the end of the list. exits the while if it is
      curr = curr->next;
    }
    curr->next = n;
  }else{
    head = n;
  }
}


template <class T>
T LinkedList<T>::read(){
  if(temp == NULL){
    temp = head;
  }
  T retVal = temp->data;
  if(temp->next != NULL){ //moves it to the next reference;
    temp = temp->next;
  }else{
    temp = head;
  }

  return retVal;
}


template <class T>
bool LinkedList<T>::empty(){
  if(head == NULL){
    return true;
  }
  return false;
}

template <class T>
bool LinkedList<T>::remove(T data){
  Node<T>* delPtr = NULL; //delete pointer is NULL
  temp = head; //allways pointing to the beginning of the list.
  curr = head;

  while(curr != NULL && curr->data != data){
    temp = curr;
    curr = curr->next;  //temp stays behind and curr goes to the next node
  }
  if(curr == NULL){
    // cout << del << " was not in the list" << endl;
    delete delPtr;
    return false;
  }
  else{
    delPtr = curr;

      //if curr is on the data, del pointer will pointer to the current
    curr = curr->next;
    temp-> next = curr;
    if(delPtr == head){
      head = head-> next;
      temp = NULL;
    }
    
    delete delPtr;    //deletes node
    // cout << "The value " << del << " was deleted" << endl;

  }
  return true;
}




#endif
