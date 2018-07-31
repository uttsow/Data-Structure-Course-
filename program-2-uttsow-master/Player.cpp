#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Card.h"

using namespace std;

Player::Player(){
  
}

Player::Player(string name, int budget){
  this->name = name;
  this->budget = budget;


}

string Player::getName(){
  return name;
}

int Player::getBudget(){
  return budget;
}

bool Player::bet(int amount){
  if(this->budget < amount){
    return false;
  }
  else{
    this->budget = this->budget - amount;
    return true;
  }
}

void Player::collectWinning(int amount){
  this->budget = this->budget + amount;
}
