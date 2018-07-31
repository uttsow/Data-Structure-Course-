#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <list>
#include "City.h"


class Map{
private:
  friend class City;
  std::vector<City*> city;
  std::list<City*> tempAdj;
  std::vector<City*> heapStorage;
  bool heap = false;
public:
  Map(std::string fileName);
  ~Map();
  City* findByName(std::string cityName);
  void addAdjacency(City* city);
  std::vector<City *> shortestPath(City * start, City * dest);
  unsigned int pathDistance(City * start, City * dest);
  void clear(); //to clear the distance and prev for new start and end
  Map(std::string filename, bool heap);
  void shortestPathHelper(City* c);
  void shortestPathHeapHelper(City*);
  void heapy();
  void siftDown(unsigned int pos);
  int findLeft(unsigned int position);
  /*int findRight(unsigned int position);
  int findParent(unsigned int position);
  bool isRoot(unsigned int position);*/
  bool isLeaf(unsigned int position);
  //bool isOneChild(unsigned int position);



};

#endif
