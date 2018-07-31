#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"
#include <fstream>

using namespace std;

class AntHill{
private:
  int food;
  int numTurn;
  int winner, loser;
  int maxX, maxY;
  ofstream file;
  LinkedList *list;

  Ant ** ants;
  int next_id;
  int current_ants;
  // int antHolder;
public:
  AntHill();
  ~AntHill();
  int addAnt();
  bool removeAnt(int);
  Ant* getAnt(int);
  void move();
  //bool changeMax(int);
  void printHillInfo();
  void printLog();    //prints info to log file
  // void foodPrinter(int);
  // void printLog2();
  void turn();        //each turn method


  //inline
  int getCurrentNumAnts(){
    return current_ants;
  }
};


#endif
