#include <iostream>
#include <cstdlib>
#include <list>
#include "City.h"
#include <string>


using namespace std;


City::City(string cityName, int xCoor, int yCoor){
  this->cityName = cityName;
  this->xCoor = xCoor;
  this->yCoor = yCoor;
  this->adjacentCity = {};

  distance = -1;
  previous = NULL;
  visited = false;


}

string City::getName(){
  return cityName;
}

int City::getXCoor(){
  return xCoor;
}

int City::getYCoor(){
  return yCoor;
}

list<City*> City::getAdjacent(){
  list<City*> myList(adjacentCity.begin(), adjacentCity.end());
  return myList;
}


bool City::operator<(City &c){
  return cityName < c.cityName;
}
