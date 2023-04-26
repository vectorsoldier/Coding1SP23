#include <iostream>
#include "enemy.h"
using namespace std;

int main() {
  std::cout << "Hello World!\n";

    enemy duke("Duke");
    duke.status();  //needed to say My name is x and my health is x

    cout << "There was a storm! Duke loses 2 health.\n";
    duke.changeHealth(-2);  //could be -=2 instead
    cout << "Duke's health is now " << duke.getHealth() << ".\n";

    cout << "what would you like to name duke?\n";
    string input;
    cin >> input;
  
    //getters and setters are used in main.
    //setting the name
    duke.setName(input);
    //getting the name
    cout << "Duke is now named " << duke.getName() << ".\n";
}