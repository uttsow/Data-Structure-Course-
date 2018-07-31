#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Map.h"
#include "City.h"

using namespace std;

Map::Map(string filename, bool heaping){
    this->heap = heaping;
    heapStorage = {};

    string line;
    ifstream file (filename);

  if(file.is_open()){
    while(getline(file, line)){
      string name = line.substr(0, line.find(" "));
      line.replace(0, line.find(" ")+1, ""); //replaces first element with next empty space with no space
      string xCor = line.substr(0,line.find(" "));  //copies first element (xCor now)
      line.replace(0, line.find(" ")+1, "");
      string yCor = line.substr(0, line.find(" "));
      line.replace(0, line.find(" ")+1, "");
      City * temp = new City(name, stoi(xCor), stoi(yCor));
      city.push_back(temp);  //adds new city to the city vector
    }
      for(unsigned int i = 0; i < city.size(); i++){
			     addAdjacency(city.at(i));
	   }

    file.close();
  }

}

Map::Map(string fileName){
  string line;
  ifstream file (fileName);
  if(file.is_open()){
    while(getline(file, line)){
      string name = line.substr(0, line.find(" "));
      line.replace(0, line.find(" ")+1, ""); //replaces first element with next empty space with no space
      string xCor = line.substr(0,line.find(" "));  //copies first element (xCor now)
      line.replace(0, line.find(" ")+1, "");
      string yCor = line.substr(0, line.find(" "));
      line.replace(0, line.find(" ")+1, "");
      City * temp = new City(name, stoi(xCor), stoi(yCor));
      city.push_back(temp); //adds new city to the city vector
    }
      for(unsigned int i = 0; i < city.size(); i++){
			     addAdjacency(city.at(i));
	   }

    file.close();
  }

}

void Map::heapy(){

    int cities = heapStorage.size();
    for (int i=(cities-2)/2; i>=0; i--){
        siftDown(i);
    }

}

//Min siftdown heap since we are getting priority based on minimum distance
void Map::siftDown(unsigned int pos) {
	if (((signed)pos < 0) || (pos >= heapStorage.size())) return; // Illegal position
	while (!isLeaf(pos)){ //Keep swapping until you get to a leaf
		unsigned int j = findLeft(pos); //Get left child
		if (j+1 < heapStorage.size() && (heapStorage.at(j)->getDistance() > heapStorage.at(j+1)->getDistance()))
			j++; // j is now index of child with greater priority
		if (heapStorage.at(pos)->getDistance() <  heapStorage.at(j)->getDistance())return; //pos is in correct position
            swap(heapStorage.at(pos), heapStorage.at(j));
		pos = j;  // Move down
	}
}


int Map::findLeft(unsigned int position){

    if((position*2)+ 1 > heapStorage.size()){
        return -1;
    }
    int num = (2*position) + 1;
    return num;
}

/*int Map::findRight(unsigned int position){
    if((position*2)+ 2 >= heapStorage.size()){
        return -1;
    }
    int num = (2*position) + 2;
    return num;
}

int Map::findParent(unsigned int position){
    if((position-1)/2 >= city.size() ||(position-1)/2 <= city.size()){
        return NULL;
    }
    int num = (position-1)/2;
    return num;
}

bool Map::isRoot(unsigned int position){
    if(position == 0){
        return true;
    }
    return false;
}*/

bool Map::isLeaf(unsigned int position){
    unsigned int leftChild = 2*position + 1;
    unsigned int rightChild = 2*position + 2;
    if(leftChild >= heapStorage.size() && rightChild >= heapStorage.size()){
        return true;
    }
    return false;
}


/*bool Map::isOneChild(unsigned int position){
    return(findRight(position) == city.size());
}*/

Map::~Map(){
  for(auto i:city){
    delete i;
  }
}

City* Map::findByName(string cityName){
  if(cityName == "") return NULL; //no cityName passed
  for(unsigned int i = 0; i < city.size(); i++){
    if(city.at(i)->getName() == cityName){
      return city.at(i);
    }
  }
  return NULL;  //if no city is found
}

void Map::addAdjacency(City* cityz){

	City* tempCity = cityz;
	int Xdiff = 100;
	int Ydiff = 100;
	int Xneg = 1000;
	int Yneg = 1000;
	int XnegWest = 1000;
	int YnegNorth = 1000;
	int smallestX = 1000;
	int smallestY = 1000;

	for(unsigned int i = 0; i < city.size(); i++){
		if(city.at(i)->getXCoor() == tempCity->getXCoor() && city.at(i)->getYCoor() != tempCity->getYCoor()){
			// This if finds the south adjacency
			if(tempCity->getYCoor() > city.at(i)->getYCoor()){
				Ydiff = tempCity->getYCoor() - city[i]->getYCoor();
			}
			// This if finds the north adjacency
			if(tempCity->getYCoor() < city.at(i)->getYCoor()){
				Yneg = city.at(i)->getYCoor() - tempCity->getYCoor();
			}
			// This if finds the closest south adjancey value (in other words the south adjacency)
			if(smallestY > Ydiff){
				smallestY = Ydiff;
			}
			// This if finds the closest north adjancey value (in other words the north adjacency)
			if(YnegNorth > Yneg){
				YnegNorth = Yneg;
			}
		}
		//Y-axis
		if(city.at(i)->getYCoor() == tempCity->getYCoor() && city.at(i)->getXCoor() != tempCity->getXCoor()){
			// This if finds the west adjacency
			if(tempCity->getXCoor() > city.at(i)->getXCoor()){
				Xdiff = tempCity->getXCoor() - city.at(i)->getXCoor();
			}
			// This if finds the east adjacency
			if(tempCity->getXCoor() < city.at(i)->getXCoor()){
				Xneg = city.at(i)->getXCoor() - tempCity->getXCoor();
			}
			// This if finds the closest west adjancey value (in other words the west adjacency)
			if(smallestX > Xdiff){
				smallestX = Xdiff;
			}
			// This if finds the closest east adjancey value (in other words the east adjacency)
			if(XnegWest > Xneg){
				XnegWest = Xneg;
			}
		}

	}
	int northAdjacencyVal = YnegNorth;
	int southAdjacencyVal = smallestY;
	int westAdjacencyVal = smallestX;
	int eastAdjacencyVal = XnegWest;
	for(unsigned int j = 0; j < city.size(); j++) {
		//Add southAdjacency
		if(tempCity->getYCoor() - city.at(j)->getYCoor() == southAdjacencyVal && tempCity->getXCoor() == city.at(j)->getXCoor()){
			tempCity->adjacentCity.push_back(city.at(j));
			//break;
		}
		//Add northAdjacency
		else if(city.at(j)->getYCoor() - tempCity->getYCoor()  == northAdjacencyVal  && tempCity->getXCoor() == city.at(j)->getXCoor()){
			tempCity->adjacentCity.push_back(city.at(j));
			//break;
		}
		//Add westAdjacency
		else if(tempCity->getXCoor() - city.at(j)->getXCoor() == westAdjacencyVal  && tempCity->getYCoor() == city.at(j)->getYCoor()){
			tempCity->adjacentCity.push_back(city.at(j));
			//break;
		}
		//Add eastAdjacency
		else if(city.at(j)->getXCoor() - tempCity->getXCoor()  == eastAdjacencyVal  && tempCity->getYCoor() == city.at(j)->getYCoor()){
			tempCity->adjacentCity.push_back(city.at(j));
			//break;
		}

	}
}



//resets the map;
void Map::clear(){
  for(auto i: city){
    i->setDistance(-1);
    i->setPrevious(NULL);
    i->setVisited(false);
  }

}

void Map::shortestPathHeapHelper(City* start){
    tempAdj = start->getAdjacent(); //only start adj is needed for Dijkstra

    int adjSize = tempAdj.size(); //using manaul size in order to pop_front from tempAdj later

  for(int i = 0; i<adjSize; i++){
    if(tempAdj.front()->getVisited() == false){
         heapStorage.push_back(tempAdj.front()); //vector contatains all the adajcent cities now
    }
    tempAdj.pop_front();  //removes all elements from tempAdj so it can add more for the next vertices
  }

  //will compare the start city to its adjacents
  for(unsigned int i = 0; i <heapStorage.size(); i++){

    int tempX = start->getXCoor();
    int tempY = start->getYCoor();
    int xAdj = heapStorage.at(i)->getXCoor();
    int yAdj = heapStorage.at(i)->getYCoor();


    if(tempX == xAdj){
      int adder;  //to get coordinate difference

      //compare the Y coordinate since x is the same;
      if(yAdj > tempY){
        adder = yAdj - tempY ;
      }else{
        adder = tempY - yAdj;
      }

      if(heapStorage.at(i)->getDistance() == -1){  //hasnt been updated/unvisited
        heapStorage.at(i)->setDistance(start->getDistance()+adder);  //updates distance
        heapStorage.at(i)->setPrevious(start); //updates previous
      }else{
        if(heapStorage.at(i)->getDistance() > start->getDistance()+adder){
          heapStorage.at(i)->setDistance(start->getDistance()+adder);
          heapStorage.at(i)->setPrevious(start);
        }
      }
    }

    //Same as top, except Y coordinate is same, so you look at X diff.
    if(tempY == yAdj){
      int adder;  //to get coordinate difference

      //compare the X coordinate since y is the same;
      if(xAdj > tempX){
        adder = xAdj - tempX ;    //coordinate difference that will be added
      }else{
        adder = tempX - xAdj;
      }

      if(heapStorage.at(i)->getDistance() == -1){  //hasnt been updated/unvisited
        heapStorage.at(i)->setDistance(start->getDistance()+adder);  //updates distacne
        heapStorage.at(i)->setPrevious(start); //updates previous
      }else{
        if(heapStorage.at(i)->getDistance() > start->getDistance()+adder){
          heapStorage.at(i)->setDistance(start->getDistance()+adder);
          heapStorage.at(i)->setPrevious(start);
        }
      }
    }

  }

  start->setVisited(true);  //sets this vertices as visited to prevent infinite cycle;


//sort the vector so the vector appears with the shortest to longest distance;
//this is important in order to pick the next shortest distance to run through the algorithim again
//This sorting method was found on stackoverflow:
//https://stackoverflow.com/questions/2758080/how-to-sort-an-stl-vector?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

    /*sort(adjacents.begin(), adjacents.end(), [] (City  *s, City  *e){
    return s->getDistance() < e->getDistance() ;});*/

    heapy();
    vector<City*> temp = heapStorage; //Gets min value
    heapStorage.erase(heapStorage.begin(), heapStorage.end());

  //keeps calling the function untill all vertices are visited;
  for(unsigned int i = 0; i < temp.size(); i++){
    if(temp.at(i)->getVisited()==false){
        shortestPathHeapHelper(temp.at(i));
    }
  }


}

vector<City*> Map::shortestPath(City* start, City* end){
  clear();  //sets everything to default;
  start->setDistance(0); //initalizes start;
  //start->setPrevious(NULL); //no previous for this;

    if(heap){
        shortestPathHeapHelper(start);
    }
    else{
        shortestPathHelper(start);
    }

  vector<City*> pathLoader;

  if(end->getDistance() == -1) return pathLoader; //no paths found
  City* temp = end;
  while(temp!= NULL){
    pathLoader.push_back(temp);
    temp = temp->getPrevious(); //assigns it previous value; puts order in reverse order
  }

  //puts it in order from start path to end
  vector<City*> pathRet;


  for(int i = pathLoader.size()-1; i >= 0; i--){
    pathRet.push_back(pathLoader[i]);
  }

//  cout<< "TEMPADJ SIZE: " << tempAdj.size() << endl;

  return pathRet;
}


void Map::shortestPathHelper(City* start){
  vector<City*> adjacents;
  tempAdj = start->getAdjacent(); //only start adj is needed for Dijkstra

  int adjSize = tempAdj.size(); //using manaul size in order to pop_front from tempAdj later

  for(int i = 0; i<adjSize; i++){
    if(tempAdj.front()->getVisited() == false){
         adjacents.push_back(tempAdj.front()); //vector contatains all the adajcent cities now
    }

    //adjacents.push_back(tempAdj.front()); //vector contatains all the adajcent cities now

    tempAdj.pop_front();  //removes all elements from tempAdj so it can add more for the next vertices
  }

  //will compare the start city to its adjacents
  for(unsigned int i = 0; i <adjacents.size(); i++){

    int tempX = start->getXCoor();
    int tempY = start->getYCoor();
    int xAdj = adjacents.at(i)->getXCoor();
    int yAdj = adjacents.at(i)->getYCoor();


    if(tempX == xAdj){
      int adder;  //to get coordinate difference

      //compare the Y coordinate since x is the same;
      if(yAdj > tempY){
        adder = yAdj - tempY ;
      }else{
        adder = tempY - yAdj;
      }

      if(adjacents.at(i)->getDistance() == -1){  //hasnt been updated/unvisited
        adjacents.at(i)->setDistance(start->getDistance()+adder);  //updates distance
        adjacents.at(i)->setPrevious(start); //updates previous
      }else{
        if(adjacents.at(i)->getDistance() > start->getDistance()+adder){
          adjacents.at(i)->setDistance(start->getDistance()+adder);
          adjacents.at(i)->setPrevious(start);
        }
      }
    }

    //Same as top, except Y coordinate is same, so you look at X diff.
    if(tempY == yAdj){
      int adder;  //to get coordinate difference

      //compare the X coordinate since y is the same;
      if(xAdj > tempX){
        adder = xAdj - tempX ;    //coordinate difference that will be added
      }else{
        adder = tempX - xAdj;
      }

      if(adjacents.at(i)->getDistance() == -1){  //hasnt been updated/unvisited
        adjacents.at(i)->setDistance(start->getDistance()+adder);  //updates distacne
        adjacents.at(i)->setPrevious(start); //updates previous
      }else{
        if(adjacents.at(i)->getDistance() > start->getDistance()+adder){
          adjacents.at(i)->setDistance(start->getDistance()+adder);
          adjacents.at(i)->setPrevious(start);
        }
      }
    }

  }

  start->setVisited(true);  //sets this vertices as visited to prevent infinite cycle;


//sort the vector so the vector appears with the shortest to longest distance;
//this is important in order to pick the next shortest distance to run through the algorithim again
//This sorting method was found on stackoverflow:
//https://stackoverflow.com/questions/2758080/how-to-sort-an-stl-vector?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
    sort(adjacents.begin(), adjacents.end(), [] (City  *s, City  *e){
    return s->getDistance() < e->getDistance() ;});

  //keeps calling the function untill all vertices are visited;
  for(unsigned int i = 0; i < adjacents.size(); i++){
    if(adjacents.at(i)->getVisited()==false){
      shortestPathHelper(adjacents.at(i));
    }
  }


}


unsigned int Map::pathDistance(City * start, City * dest){
  //Clears the map;
  //sets a starting distance of zero, runs through the alogritim and returns the end distance of the Destination
  //returns -1 if it's never reached
  clear();
  start->setDistance(0);
  shortestPathHelper(start);
  if(dest->getDistance() == -1 ){
    return -1;
  }
  return dest->getDistance();
}
