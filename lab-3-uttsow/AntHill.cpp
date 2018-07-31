#include "Ant.h"
#include "AntHill.h"
#include <iostream>
#include <cstring>


using namespace std;

AntHill::AntHill(){
  this->next_id = 0;
  this->current_ants = 0;
  this->ants = NULL;
}

//destructor
AntHill::~AntHill(){
  int x;
  for(x = 0; x<current_ants; x++ ){
    delete ants[x];
  }
  delete[] ants;
}
int AntHill::addAnt(){
  Ant ** new_ant_array = new Ant*[current_ants+1];

//Adds ants to the new ant array from the pointer ants;
  if(ants!=NULL){
    for(int i = 0; i<current_ants; i++){
      new_ant_array[i] = ants[i];
    }
  }

  //Create new Ant Object

  new_ant_array[current_ants] = new Ant(next_id);

  //increment id and #of ants;
  next_id++;
  current_ants++;

  //frees the old array;
  delete[] ants;

  //points ants array to new copy array
  ants = new_ant_array;

  return current_ants;
}

bool AntHill::removeAnt(int aAnt){

  //if id is less than 0, return false;
  if(aAnt< 0) return false;

  Ant ** new_ant_array = new Ant*[current_ants-1];

//delete matching id;
  for(int x = 0; x <current_ants; x++){
    if(ants[x]->getID() == aAnt){
      delete ants[x];
      //updates the ant array;
    for(int i = x; i<current_ants-1; i++){
      ants[i] = ants[i+1];
    }
  }
}

//copy all pointers
  for(int j = 0; j <current_ants-1; j++){
    new_ant_array[j]= ants[j];

  }
//updates and deletes current_ants and ants
  current_ants -= 1;
  delete[] ants;
  ants = new_ant_array;
  return true;
}

Ant* AntHill::getAnt(int iD){
  Ant * copyAnt;
  for(int i = 0; i < current_ants; i++){
    if(ants[i]->getID() == iD){
      copyAnt = ants[i];
      return copyAnt;
    }
  }
  return NULL;
}

void AntHill::move(){
  //uses pointers now ->
  for(int x = 0; x<current_ants; x++){
    ants[x]->move();
  }
}

void AntHill::printHillInfo(){
  for(int x = 0; x<current_ants; x++){
    cout <<"Ant #"<<ants[x]->getID()<<" ["<<ants[x]->getX()<<","<<ants[x]->getY()<<"]"<<endl;
  }
}
