#include <iostream>
#include <ctime> //randomization
#include <cstdlib>
using namespace std;

string names[] = {"USS Cool Boat", " USS Does Things", "USS Doesn't Sink"};

class spaceship {
  string name;
  int fuelLevel;
  // class 1 = Carrier, 2 = destroyer, 3 = fighter
  int shipClass = 2;

public:
  spaceship(string givenName = "USS Boat", int givenFuel = -1, int givenClass = -1) {
      //randomize
      if(givenName == "USS Boat") {
        // randomize
        name = names[rand() % 3];
      }
    else {
        name = givenName;
    }

    if(givenFuel == -1) {
      // randomize
      fuelLevel = rand() % 75 + 25; //random number
    }
    else {
        fuelLevel = givenFuel;
    }

    if(givenClass == -1) {
      shipClass = rand() % 3 + 1;
    }
    else {
      shipClass = givenClass;
    }

    sitrep();
  }  // end of constructor.

  void sitrep() {
      cout << "The spaceship \"" << name << "\" has " << fuelLevel << " fuel.\n";
        // \" is a way to write " without writing ""
      cout << "This ship is a ";

      switch(shipClass) {
        case 1: cout << "Carrier.\n";
        break;
        case 2: cout << "Destroyer.\n";
        break;
        case 3: cout << "Fighter.\n";
        break;
        default: cout << "Unknown Ship.\n";
        break;
      }
  }

void travel() {
  cout << "You wish to travel to a faraway star system.\n";
  int requiredFuel = rand() % 25 + 1;
  cout << "it requires " << requiredFuel << " fuel.\n";
  cout << "You have " << fuelLevel << " units of fuel.\n";
  if(fuelLevel > requiredFuel) {
    cout << "Let's go!\n";
    fuelLevel -= requiredFuel;
    cout << "you have arrived with " << fuelLevel << " fuel.\n";
  }
  else {
      cout << "you do not have enough fuel.\n";
  }
}

// getters and setters allow access to private variables, with guidelines.
  // GetName() just returns the name of the string.
  string GetName() {
      return name;
  }
  void SetName(string givenName) {
    // check for obscenities
    if(givenName == "shit" || givenName == "Shit" || givenName == "5h1t" || givenName =="SHIT") {
        cout << "Naughty! Be nice, friend.\n";
        return;     //dont change the name.
    }
    if(givenName.size() > 10 || givenName.size() < 3) {
      cout << "No names longer than 10 characters.\n";
      cout << "Also no names shorter than 3 characters.\n";
      return;
    }

    name = givenName;
  }
  int GetFuelLevel() {
      return fuelLevel;
  }
  void SetFuelLevel(int givenLevel) {
    if(givenLevel < 0) {
        fuelLevel = 0;
    }
    else if(givenLevel > 100) {
        fuelLevel = 100;
        cout << "you have an excess of " << givenLevel - 100 << " fuel.\n";
    }
    else {
        fuelLevel = givenLevel;
    }
  }

  int GetShipClass() {
    return shipClass;
  }

  void SetShipClass(int givenClass) {
    if (givenClass >= 1 && givenClass <= 3) {
      shipClass = givenClass;
    } else {
      cout << "Invalid ship class. Please enter a number between 1 and 3." << endl;
    }
  }
};

int main() {
  srand(time(0));
  spaceship apollo;      //randomize everything
  spaceship falcon("Millenium Falcon");    //randomize all but the name
  spaceship bananaBoat("Banana Boat", 45, 3);

  cout << "Bananaboat is trying to travel...\n";
  bananaBoat.travel();
  bananaBoat.travel();
  bananaBoat.travel();
  bananaBoat.travel();

  // don't allow this:
  //bananaBoat.name = "Plantain Boat";

  cout << "My spaceship's name is " << bananaBoat.GetName() << ".\n";
  cout << "Jerk: That's a terrible name! Change it to 'coolboat3'!!\n";
  cout << "Fine.\n";
  bananaBoat.SetName("coolboat3");

  cout << "My spaceship's name is " << bananaBoat.GetName() << ".\n";

  cout << "My current fuel level is " << bananaBoat.GetFuelLevel() << ".\n";
  cout << "Time to refuel. paying for 200 gallons of fuel.\n";
  bananaBoat.SetFuelLevel(200);

  cout << "I now have " << bananaBoat.GetFuelLevel() << " fuel.\n";
  
}