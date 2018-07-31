#ifndef CITY_H
#define CITY_H

#include <string>
#include <list>
#include <vector>


class City{
private:
  friend class Map;
  std::string cityName;
  int xCoor;
  int yCoor;
  std::vector<City*> adjacentCity;

  int distance;
  City* previous;
  bool visited;



public:
  City(std::string cityName, int xCoor, int yCoor);
  std::string getName();
  int getXCoor();
  int getYCoor();
  std::list<City*> getAdjacent();
  bool operator<(City &c);

  inline bool ascedndingOrder(City  &d){
    return this->distance < d.distance;
  }

  inline int getDistance(){
    return distance;
  }


  inline void setDistance(int d){
    distance = d;
  }
  inline void setPrevious(City* c){
    previous = c;
  }

  inline void setVisited(bool x){
    visited = x;
  }

  inline City* getPrevious(){
    return previous;
  }
  inline bool getVisited(){
    return visited;
  }



};


#endif
