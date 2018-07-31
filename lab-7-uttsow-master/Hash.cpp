#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>
#include "Hash.h"

using namespace std;

Hash::Hash(unsigned int size){

  for(unsigned int i = 0; i <size; i++){
    hashStorage.emplace_back("","");
  }
}

//Hash function
int Hash::hasher(string key){
  return key.length() % hashStorage.size();

}

bool Hash::insert(string key, string value){
  int index = hasher(key);

  //handles buckets from index to end of vector;
  for(unsigned int i = index; i < hashStorage.size(); i++){
    if(hashStorage.at(i).first == ""){
      hashStorage.at(i) = make_pair(key, value);
      return true;
    }
  }


  //handles buckets from beginning to index if the other fails
  for(unsigned int i = 0; i <(unsigned)index; i++){
    if(hashStorage.at(i).first == ""){
      hashStorage.at(i) = make_pair(key,value);
      return true;
    }
  }
  return false; //returns false if full
}

bool Hash::remove(string key){
  unsigned int index = hasher(key);

  //if element is post index
  for(unsigned int i = index; i<hashStorage.size(); i++){
    if(hashStorage.at(i).first == key){
      hashStorage.at(i) = make_pair("", "");
      return true;
    }
  }

  //if key is not found, checking pre index
  for(unsigned int i = 0; i <(unsigned)index; i++){
    if(hashStorage.at(i).first == key){
      hashStorage.at(i) = make_pair("", ""); //so vector doesnt change size
      return true;
    }
  }
  return false; //item wasnt found
}

string Hash::find(string key){
  int index = hasher(key);
  for(unsigned int i = index; i<hashStorage.size(); i++){
    if(hashStorage.at(i).first == key){
      return hashStorage.at(i).second;
    }
  }

  for(unsigned int i = 0; i <(unsigned)index; i++){
    if(hashStorage.at(i).first == key){
      return hashStorage.at(i).second;
    }
  }

  return ""; //returns empty string if nothings found
}


bool Hash::empty(){
  for(unsigned int i = 0; i < hashStorage.size(); i++){
    if(hashStorage.at(i).first != ""){
      return false;
    }
  }
  return true;
}

int Hash::size(){
  return hashStorage.size();
}

void Hash::printHash(){
  for(unsigned int i = 0; i < hashStorage.size(); i++){
    cout << "Index: " << i << ", Key: " << hashStorage[i].first << ", Value: " << hashStorage[i].second << endl;
  }
}
