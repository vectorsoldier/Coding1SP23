#include "enemy.h"
#include <iostream>
using std::cout;

//define the constructor
//has a default value for givenName in header (Bad guy mcgee)
//getters and setters defined in source
enemy::enemy(string givenName) {
  name = givenName;
  health = 10;
  cout << name << " has appeared!\n"; 
}

void enemy::status() {
  cout << "My name is " << name << " and my health is ";
  cout << health << ".\n";
}

void enemy::changeHealth(int by) {  //can replace by with amount
  health += by;    //can replace by with amount

  if(health < 0) {
      health = 0;
  }
  else if(health > 10) {
    health = 10;
  }
}

int enemy::getHealth() {
  return health;
}

//parameter names dont have to define the header file.
void enemy::setName(string to) {  //string to? could also be givenName.
  if(to == "Poop") {  //to? could also be givenName.
    cout << "Uh oh, stinky!\n";
    return;
  }
  
  name = to;  //to? could also be givenName.
}

string enemy::getName() {
  return name;
}