#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include "LinkedList.h"


template <class T>
class Queue{
  template <class Type2> friend class LinkedList;

private:
  LinkedList<T> *queue;

public:
  Queue();
  bool enqueue(T data);
  T dequeue();
  T peek();
  bool empty();
  void clear();
};

template <class T>
Queue<T>::Queue(){
  queue = new LinkedList<T>();
}

template <class T>
bool Queue<T>::enqueue(T data){
  if(queue->head == NULL){
    queue->insert(data);
    queue->curr = queue->head;

  }else{
    Node<T> *n = new Node<T>;
    n->data = data;
    n->next = NULL;
    queue->curr->next = n;
    queue->curr = n;
  }

  return true;

}

template <class T>
T Queue<T>::dequeue(){
  if(empty()){
    delete queue;
    queue = NULL;
  }

  Node<T> * ptr = queue->head;
  T value = ptr-> data;

  queue->remove(value);
  return value;
}

template <class T>
T Queue<T>::peek(){
  Node<T> *peeker = queue->head;

  T retVal = peeker->data;
  while(peeker->next != NULL){
    peeker = peeker->next;
  }


  return retVal;

}


template <class T>
bool Queue<T>::empty(){
  if(queue->head== NULL || queue == NULL){
    return true;
  }
  return false;
}


template <class T>
void Queue<T>::clear(){
  Node<T> *tempHead = queue->head;

  while(tempHead != NULL){
    Node<T> *tempory = tempHead->next;
    delete tempHead;
    tempHead = tempory;
  }
  queue->head = NULL;
}

#endif
