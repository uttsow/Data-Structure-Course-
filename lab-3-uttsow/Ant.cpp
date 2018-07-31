#include <iostream>
#include "Ant.h"

Ant::Ant(int id){
	this->id = id;
	this->x = 0;
	this->y = 0;
	this->xp = rand()% 10 + 1;
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

Ant* Ant::fight(Ant *ant2){
	//first and second ant
	 


	int random1 = rand()% 100;
	int random2 = rand()% 100;

//ant2 xp is greater than ant1
	if(ant2->xp > this->xp){
		//random 1 is greater than random2: ant2 loses
		if(random1 > random2){
			ant2->xp = ant2->xp+this->xp;
			this->xp = 0;
			return ant2;
		}
		else{
			this->xp = this->xp + ant2->xp;
			ant2->xp = 0;
			return this;
		}

	}
	//ant2 xp is less than ant1
	else if(ant2->xp < this->xp){
		//random1 < random 2: ant1 is loser
		if(random1 < random2){
			this->xp = this->xp + ant2->xp;
			ant2->xp = 0;
			return this;
		}
		else{
			ant2->xp = ant2->xp + this->xp;
			this->xp = 0;
			return this;
		}
	}else{
		return NULL;
	}
}
