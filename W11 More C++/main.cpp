#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// global variables go at the TOP!!!
string robotNames[] = {"Artoo", "IG-11", "IG-88", "ChatGPT", "MSE-6"};   //[] brackets make it an array
  // my global robots array
  

// creating a new class
// "class" keyword, then the name of the class
class robot {
public:    //if this isnt here, the name is private and cant be seen. Public is necessary for the cpu to know the name.
// data members (variables)
  string name;
  int batteryLevel;
  int x;    //horizontal location
  int y;    //vertical location

// member functions
  // a constructor is called when a new variable is created.
  // a constructor is always named the same as the class, with no return type.
  robot(string givenName = "Robot", int givenBatteryLevel = 10) {
    cout << "A new robot has been created!\n";
    name = givenName;
    batteryLevel = givenBatteryLevel;
    // start them out at 0,0 on the map.
    x= (rand() % 5) - 2;      // TODO: Randomize from -2 to +2 (rand() %5) gives a number of 4 so -2 to get to 2 
    y= (rand() % 5) - 2;      // TODO: Randomize from -2 to +2

    // dont forget #include <ctime>, #include <cstdlib>, srand(time(0))
  }

// try calling "artoo.status()";
void status() {
  cout << "[" << name << ": " << batteryLevel << "]\n";    //brackets around robot name and battery level
  cout << "[Position is " << x << "," << y << ".]\n";
}

void move() {    //give robots the ability to move
  // north and south are on the y axis
  // east and west are on the x axis.
  // 1. pick a direction.
  // 2. try to move in that direction.
  // 3. if we're at the end of the map, dont move. 
  if(batteryLevel <= 0) {    //if battery is less than or equal to 0
    cout << "Out of battery\n";
    return;    //don't move. void move if battery is 0 or less
  }
  
  while(true) {
  
    int direction = rand() % 4;   // 0 = n, 1 = s, 2 = e, 3 = w; 0-3 are the cardinal directions NESW
  
    // pretend we are at 0,0. we decide to go north. now we are at 0, 1.
  
    // if going north...
    if(direction == 0) {
      // if not at the top of the map...
      if(y < 2) {
          // go north....
          y++;
        cout << name << " moves north.\n";
        break;
      }
    }
    else if(direction == 1 && y > -2) { y++; break; }    //2 and -2 are to ensure the movement stays within the 2 by 2 grid
    else if(direction == 2 && x < 2) { y++; break; }   //its possible during the loop that they try to move but theyre maxed out at a certain direction and cant go further
    else if(direction == 3 && x > -2) { x--; break; }

    cout << "cannot move there, trying again.\n";
  }  //end of while loop()

  batteryLevel -= 1;  // -= is a combined assignment operator; battery level= battery level - 1
  // TODO: loop until move is successful.
}  // end of move ()

void sayHey(robot robots[]) {
    // say hey to any robots near us
  for(int i = 0; i < 10; i++) {
    if(&(robots[i]) == this) continue; //this line of code stops the robots from saying hi to themselves every single time; if the robot is me, continue, skip the hey
    if(robots[i].x == x) {
      //cout << "they're on the same x-axis....\n";
      if(robots[i].y == y) {
          cout << "They're near!!\n\n";
          cout << name << " says heyy to " << robots[i].name << "!\n\n";
      }
    }
  }
}


// project goal
// give robots position on -2 to +2 grid
// give robots ability to move NESW.


};     // dont forget the semi-colon at the end of the class, end of class robot.

  // my global robots array.


int main() {
  srand(time(0));
  std::cout << "It's Week 11!\n";
  // unified modeling language (UML) for documenting complex systems.

  // create a new robot variable--artoo
  robot artoo;
  // set up artoo
  artoo.name = "R2-D2";    //string name of robot 
  artoo.batteryLevel = 4; //string of robot battery Level 

  cout << "Welcome " << artoo.name << "!\n";
  cout << artoo.name << "'s battery level is " << artoo.batteryLevel << ".\n";

  robot threepio("C-3PO", 5);    // constructor is called here.
  threepio.status();
  
  robot fourlom("4LOM");
  fourlom.status();


  // create a list of names (make an array)
  // create a list of robots with random names and batteryLevels (make an array)
  robot robots[10];    //10 robots moving around
  // randomize the robots
  for(int i = 0; i < 10; i++) {
    robots[i] = robot(robotNames[rand() % 5], rand() % 6 + 5);
  }
  
  // let's get the status of all of these robots...
  for(int i = 0; i < 10; i++) {
      robots[i].status();
  }

  // move the robots
  cout << "Moving the bots...\n";
  for(int i = 0; i < 10; i++) {
    robots[i].move();
  }

  // let's get the status of all of these robots...
  for(int i = 0; i < 10; i++) {
      robots[i].status();
  }

  for(int i = 0; i < 15; i++) {
    cout << "Moving the bots...\n";
    for(int j = 0; j < 10; j++) {
      robots[j].move();
      robots[j].status();
      if(robots[j].batteryLevel > 0) robots[j].sayHey(robots);  //only say hey if the robots battery is greater than 0
    }
  }

  // and then we'll have them move around.
  // TODO: Move requires one battery level, until battery is depleted.
  
}