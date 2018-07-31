#include <iostream>
#include "Ant.h"
#include "AntHill.h"
#include <cstdlib>




Ant::Ant(int id){
	this->id = id;
	x = 0;
	y = 0;
	xp = rand()% 10 + 1;
}

//copy constructor
Ant::Ant(Ant *copy){
	x = copy->getX();
	y = copy->getY();
	id = copy->getID();
	xp = copy->getXp();
}
int Ant::move(int gridmax){
	int random = rand() % 4+1;

	switch(random){
		case 1 :
			x = x +1;
			break;
		case 2 :
			x = x -1;
			break;
		case 3 :
			y = y + 1;
			break;
		case 4 :
			y = y-1;
			break;
		default :
			break;
	}
	//makes sure ants dont move off the grid of size 4;

	if(x>gridmax){
		x = gridmax;
	}
	if(x<(-1*gridmax)){
		x = (-1*gridmax);
	}
	if(y>gridmax){
		y = gridmax;
	}
	if(y<(-1*gridmax)){
		y = (-1*gridmax);
	}

	int chances = rand() % 100;

	if(chances < 25){		//ant fights
		return fight();
	}else if( chances >=25 && chances <50){	//doesnt fint but finds food;
		return 4;		//add food to antHill;
	}
	return 5; //doesnt fight and or find food.


}

int Ant::fight(){
	int toFight = rand() % 100+1;

	if(toFight > 50){		//ant wins the fights
		return 1;
	}
	return 2; //ant loses and removed;
}
