// Coding 1 Week 14 Spring 2023 Wednesday
//  Michael Sullivan--reading from and writing to (text) files.

#include <iostream>
#include <fstream>   // ifstream (inputs--in from a file; reading) 
                    // ofstream (outputs--out to a file; writing)
                    // fstream = both ifstream and ofstream
using namespace std;

// global array
string favGames[100];
int index = 0;  //index keeps track of how many things are in the list
                //and where to put the next thing in the list

/*
  for your assignment:
    1) create a favgames program. (add a game, remove a game, edit the game, find diff games)
    2) use 6 functions (want all of the functionality to be inside functions)
                  no need to pass variables unless you want to
      a) add (using functions) void add
      b) show (using functions)
      c) remove (using functions)
      d) edit (using functions)
      e) load previous list from file (using functions) void load--load in array from save.txt
      f) save list to file (using functions) void save--save the array back to a file when done.
*/

void add() {
  cout << "what game would you like to add?\n";
}

void load() {
  // try to open the save file--save.txt
  // add each line from the file to the array.
  // close the file.
}

void save() {
  // open the file
  // use a for loop to write all of the array lines to the file.--save the array back to a file when done
  // file << favGames[i] << "\n";
  // close the file.
}

int main() {
  cout << "Getting Started!\n";

  cout << "Let's save text to a file!\n";

  // create the file variable
  ofstream file;
  // opening the file, specifying filename.
  file.open("data.txt");    //convert data.txt to save.txt it makes a diff text file to save data to
  // writing text to the file.
  file << "This text will be saved into the file.\n";

  // let the user decide what to save to the file.
  while(true) {
    cout << "What do you want to say?\n";
    string input;
    getline(cin, input);
    if(input == "quit") break;
    // add input to file, then start a new line.
    file << input << "\n";
   
  }
  
  // close the file, so that some other program can use it.
  file.close();

  cout << "done!\n";

  cout << "Let's read from our save.txt file.\n";
  // create a string variable to hold each line in the file.
  string line;
  // create the file variable
  ifstream save("save.txt");

  // check to see if the file is open
  if(save.is_open()) {
      while(getline(save, line))  //reading from save file, sending data from each line to string line
                                  //while goes until there are no more lines
          cout << line << "\n";
          // favGames[index++] = line;   //puts whatever is on save.txt line 1 into the array and moves
                                          //the index to point to the next thing
  }
  else{
      cout << "file could not be loaded.\n";
  }
}