#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(0));
  cout << "Hello player! Welcome to the thunderdome.\n";

  //game setup
  int health = 10;
  int attack = 0;
  int block = 0;
  int turns = 0;

  do{
    turns +=1;
    cout << "An enemy attacks!\n";
    attack =rand() % 5;
    block = rand() % 5;

    if(block >= attack) {
      cout << "Succesful block!\n";
      health -= attack;
      cout << "your health is now " << health << ".\n";
    }
  } while (turns < 4 && health > 0);

  if(health > 0) {
    cout << "you survived! You have " << health << " health.\n";
  } else{
    cout << "You have died.\n";
  }
}