#include "Ant.h"
#include "AntHill.h"
#include "LinkedList.h"
#include <iostream>
#include <cstring>
#include <fstream>

#define GRIDMAX 2

using namespace std;

AntHill::AntHill(){
  next_id = 0;
  current_ants = 0;
  ants = NULL;
  // this->antHolder = current_ants;
  // antHolder = 0;

  this->food = 0;
  numTurn = 0;
  winner = 0;
  loser = 0;
  maxX = maxY = 0;
  file.open("antlog.log");

  list = new LinkedList();
  list->addAnt(new Ant(0));
  list->addAnt(new Ant(1));
  list->addAnt(new Ant(2));

  addAnt();
  addAnt();
  addAnt();


}

//destructor
AntHill::~AntHill(){
  int x;
  for(x = 0; x<current_ants; x++ ){
    delete ants[x];
  }
  delete[] ants;

  cout << " destructor & antCount: " << current_ants << endl;
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
  for(int i = 0; i < current_ants; i++){
    int movement = ants[i]->move(GRIDMAX);
    if(movement == 1){    // ant wins the fight
    //  cout << "won Movement" << endl;
      file << " Ant #" << ants[i] -> getID() << " has ran into a rival ant" << endl;
      file << " Ant #" << ants[i] -> getID() << " fought an won" << endl;
    }
    else if(movement == 2){      //ant loses based on fight
    //  cout << "loss movement" << endl;
      file << " Ant #" << ants[i] -> getID() << " has ran into a rival ant" << endl;
      file << " Ant #" << ants[i] -> getID() << " loses the fight and dies" << endl;
      list->deleteAnt(ants[i]->getID());   //deletes ant from both list and array;
      removeAnt(ants[i]->getID());
    }
    else if(movement == 4){ //ant finds food but doesnt fight;
      food++;
    }
    else if(movement == 5){   //ant doesnt find food or fight;
      file << "       ....time passes" << endl;
    }
  }

}

void AntHill::printHillInfo(){
  for(int x = 0; x<current_ants; x++){
    cout <<"Ant #"<<ants[x]->getID()<<" ["<<ants[x]->getX()<<","<<ants[x]->getY()<<"]"<<endl;
  }
}

void AntHill::turn(){
  if(current_ants!=0 || current_ants !=100){
    printLog();

  // printLog();
  move();

  // *food = 0;
  //AntHill attacking
  int attackChance = rand() % 100;


  if(attackChance < 25){
    int attackers = rand() % current_ants + 1;
    //cout << "AntHill attack" << endl;
    //cout << "attackers: " << attackers << endl;
    int defendPoint = 0;
    for(int i = 0; i <current_ants ; i++){
      if(ants[i]->getX() <= (GRIDMAX/2) && ants[i]->getX() >= (-1*(GRIDMAX/2))
      && ants[i]->getY() <= (GRIDMAX/2) && ants[i]->getY() >= (-1*(GRIDMAX/2))){
        defendPoint++;
      }
    }
    //cout <<"To defend or not" << endl;
    if(defendPoint > attackers){
      winner++;
    }
    else if(defendPoint < attackers){
      //cout << "TOok an L for ANTHILL" << endl;
      loser++;
      food = 0;
      for(int z = 0; z < current_ants; z++){
        if(ants[z]->getX() <= (GRIDMAX/2) && ants[z]->getX() >= (-1*(GRIDMAX/2))
        && ants[z]->getY() <= (GRIDMAX/2) && ants[z] ->getY()>= (-1*(GRIDMAX/2))){
          list->deleteAnt(ants[z]->getID()); //removes ant from ANTHILL;
          removeAnt(ants[z]->getID());
        }
      }


    }
  }

  for(int i = 0; i < food; i++){
    if(current_ants < 100){
    list->addAnt(new Ant(next_id));
    addAnt();
    food--;
  }
  }

  // while(food && current_ants <100){
  //   list->addAnt(new Ant(next_id));
  //   addAnt();
  //   food--;
  // }
  numTurn++;




  }
  //prints summary of the final outcome
  if(current_ants == 0|| current_ants == 100){
    printLog();
  }
  //deletes linked list;
  if(current_ants==0 || current_ants ==100){
    delete list;
  }
}



void AntHill::printLog(){
  file << "     =============== Turn #"<< numTurn << "  ===============" << endl;
  file << "The hill currently has:" << endl;
  file << "    Food:" << food << endl;
  file << "	   Ants:" << current_ants << endl;
  file << "The hill has been attacked "<< loser + winner << " times." << endl;
  file << "	   Successfully defended: " << winner << endl;
  file << "	   Failed to Defend: " << loser << endl;
}

// void AntHill::printLog2(){
//   file << "========== Turn #"<< numTurn << "==========" << endl;
//   file << "The hill currently has:" << endl;
//   file << "	Food:" << food << endl;
//   file << "	Ants:" << antHolder << endl;
//   file << "The hill has been attacked "<< loser + winner << " times." << endl;
//   file << "	Successfully defended: " << winner << endl;
//   file << "	Failed to Defend: " << loser << endl;
// }
