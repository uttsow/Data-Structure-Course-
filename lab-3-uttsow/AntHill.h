#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"

class AntHill{
private:
  Ant ** ants;
  int next_id;
  int current_ants;
public:
  AntHill();
  ~AntHill();
  int addAnt();
  bool removeAnt(int);
  Ant* getAnt(int);
  void move();
  //bool changeMax(int);
  void printHillInfo();

  //inline
  int getCurrentNumAnts(){
    return current_ants;
  }
};


#endif
