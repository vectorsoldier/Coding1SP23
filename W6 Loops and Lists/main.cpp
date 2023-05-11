#include <iostream>
using namespace std;


int main() {
  cout << "Hello World!\n";

  
  // what is the i for?

  // for(setup; test; action) { code }
  for(int loopCount = 0; true; loopCount += 1) {
    cout << loopCount << "\n";

    if(loopCount > 5) {
        break;
    }     //end of if statement
    
  }   //end of for loop

  if(true) {
    // an array can only hold one type of variable (int, character, string, float)
    // var type, var name [size of array]
    string pizzaToppings[5];
    
    int scores[10];

    pizzaToppings[0] = "Pepperoni";
    pizzaToppings[1] = "Ham";
    pizzaToppings[2] = "Pineapple";

    cout << pizzaToppings[0] << "\n";
    cout << pizzaToppings[1] << "\n";
    cout << pizzaToppings[2] << "\n";

    cout << "\nSame thing but with a for loop:\n\n";

    for(int i=0; i < 3; i += 1) {
      cout <<pizzaToppings[i] << "\n";
      }


    string name = "Brian foster";
    // .size() = 12

    cout << name << " has a size of " << name.size() << ".\n";

    string favGames[100];

    int index = 0;  //index points to the number you want to edit, next spot on array. 
                    //keeps track of where you are in the list

    while(true) {
      cout << "What would you like to do?\n";
      cout << "Type 'quit' to quit the program.\n";
      cout << "Type 'add' to add a game.\n";
      cout << "Type 'show' to show your favourite games.\n";
      cout << "Type 'edit' to edit a game in the list.\n";
      cout << "Type 'editlast' to edit the last game you wrote.\n";
      cout << "Type 'find' to find a game in the list.\n";

      // get input
      string input;
      cin >> input;

      // test the input
      if(input == "quit") {    //first if should be normal if not else if
        cout << "Shutting down...\n";
        break;    // or return 0 to quit the function or program; break stops the code
      }

      else if(input == "add") {
        cout << "What game would you like to add?\n";
        cin >> input;
        favGames[index] = input;  //can also say index++. ex: favGames[0]= "Mario";
        index += 1;    // index is now pointing at the next spot. can also say index ++
      }

      else if(input == "show") {
        cout << "Here are your favorite games:\n";
        for(int i = 0; i < index; i += 1) {
          cout << i + 1 << ". " << favGames[i] << "\n";
        }
      }

      // what if we mess up?
      else if(input == "edit") {
        cout << "What is the number of the name you want to change?\n";
        int numInput;
        cin >> numInput;

        cout << "What would you like to change " << favGames[numInput - 1] << " to?\n";
        cin >> input;
        favGames[numInput - 1] = input; //-1 because arrays read 0 as number 1
      }

      else if(input == "editlast") {  //editing the last thing that was entered
        cout << "last entry was " << favGames[index - 1] << ", change to what?\n";
        cin >> input;    //inputs use >> ; outputs use <<
        favGames[index - 1] = input;
      }

      else if(input == "find") {
        cout << "what game do you want to find?\n";
        cin >> input;

        //look through the games to see if you can find input
        for(int i=0; i < index; i += 1) {    //for loop looks through entire list

            if(input == favGames[i]) {
              cout << "Found it!\n";
              cout << "what'dya wanna change it to?\n";
              cin >> input;

              favGames[i] = input;
              break;  //to make it stop looking through list
            }

            if (i + 1 == index) {  //this statement MUST go at the end of the for loop nowhere else
              cout << "I looked through the entire list and couldn't find " << input << ".\n";
            }
        }  //end of for loop 
      }

      else if(input == "bulkadd") {
        while (true) {
            cout << "Add game or 'quit'.\n";
            cin >> input;

            if(input == "quit"){
                break;
              }

              favGames[index] = input;    // ex: favGames[0] = "Ma..."
              index++;  //index is now pointing at the next spot.
            }
        }
        
      else {
        cout << "[command not recognized]\n";     //if you type in anything not of the commands listed
      }
      
    } // end of while (true)





    
  }  // end of if(true)
  
} // end of program