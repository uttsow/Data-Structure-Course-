#include "AntHill.h"
#include <iostream>
#include <cstdlib>

#define BUFFER_MAX 100

using namespace std;

Ant::Ant(int id){
	this->id = id;
	this->x = this->y = 0;
}

int Ant::getID(){
	return this->id;
}

int Ant::getX() {
	return this->x;
}
int Ant::getY() {
	return this->y;
}

void Ant::move(){
	int random = rand() % 4;

	switch(random){
		case 0 :
			this->x = this->x +1;
			break;
		case 1 :
			this->x = this->x -1;
			break;
		case 2 :
			this->y = this->y + 1;
			break;
		case 3 :
			this->y = this->y-1;
			break;
		default :
			break;
	}
}
//Second Part: AntHill class

AntHill::AntHill(int numAnts){
	//Constructor to set up current ants and next_id;
	max_ants = numAnts;
	current_ants = 0;
	next_id = 0;

}

bool AntHill::addAnt(){
	//checlks if the id is more than max ants or id is greater than array size
	if(next_id > max_ants-1 || next_id > 100) return false;

	//Adds newAnt to Ant and updates id and ant status
	Ant newAnt = Ant(next_id);
	ants[next_id] = newAnt;
	next_id++;
	current_ants++;
	return true;
}

Ant AntHill::getAnt(int antsNum){
	 Ant copy = ants[antsNum];
	 return copy;
}

void AntHill::move(){

	int x;
	for(x = 0; x < next_id; x++){
		ants[x].move();
	}
}

bool AntHill::changeMax(int newMax){
	if(newMax > 100 || newMax<0) return false;

	max_ants = newMax;
	return true;
}

void AntHill::printHillInfo(){
	for(int x = 0; x < next_id; x++){
		cout <<"Ant #"<<ants[x].getID()<<" ["<<ants[x].getX()<<","<<ants[x].getY()<<"]"<<endl;

	}
}

int AntHill::getCurrentNumAnts(){
	return current_ants;
}

int AntHill::getMaxAnts(){
	return max_ants;
}
