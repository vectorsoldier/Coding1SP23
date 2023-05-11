#include <iostream>
#include <fstream> //fstream is both ifstream and ofstream
#include <string>  //necessary for getline
using namespace std;
// saving and loading
// no extra spaces in the text file.
// no global ofstream variable
// how to remove a game
// maybe, using a header file.

// what we are doing
  // 1-save an array of strings to a file
  // 2-load the file into an array of strings.
  // 3-remove strings from the array

// global array of strings
string favGames[100];
  // this keeps track of how long the list is
  // and where to put the next favGame in the list.
int index = 0; //this is important that the initial value of an array is always defined as 0 

void load() {
  //open the file
  ifstream file("data.txt");
  string line;

  if(file.is_open()) {
    while(getline(file, line)) {
        favGames[index++] = line;  //favGames of 0 = halo, at the end of line of code add 1 to index until youre done
    }
  }

  file.close();
}

void save() {
  // create the ofstream file
  // dont forget to #include <fstream>
  ofstream file("data.txt");

  // for each array element, write a line to the file.
  if(file.is_open()) {
    for(int i =0; i < index; i++) {
        file << favGames[i] << "\n";
    }
  }

  file.close();
}

void add() {
  // initialize the list; this is the  add function; when you press add it adds all 3 of these at once.
  favGames[index++] = "halo";
  favGames[index++] = "half-life 2";
  favGames[index++] = "breath of the wild";  
}

void clear() {
  cout << "did you mean to clear? (yes/no)\n";
  string input;
  getline(cin, input);

  if(input == "yes") {
    index = 0;
  }
  else {
    cout << "Cool, not clearing...\n";
  }
}

void remove() {
  cout << "what do you want to remove?\n";
  string input;
  getline(cin, input);

  for(int i = 0; i < index; i++) {
    if(input == favGames[i]) {
        cout << "Removing...\n";
        favGames[i] = "";
        break;     // break out of the for loop.
    }
  }
}

void show() {
  cout << "Your favgames:\n";
  for(int i = 0; i < index; i++) {
      if(favGames[i] == "") {
        // skip empty lines
        continue;
      }
      cout << favGames[i] << ".\n";
  }
}

int main() {
  // at the beginning, load the code from the file.
  load();
  
  while(true) {
      string input;
      cout << "do what?\n";
      // cin >> input; 
      getline(cin, input); //getline is where do you want to get the text from and where do you want to put it
        // from the file to the array
        // getline (from, to);
        // getline(cin, input); is replaceable with cin >> input;

      if(input == "add") add();
      else if(input == "show") show();
      else if(input == "remove") remove();
      else if(input == "clear") clear();
      else if(input == "quit") break;
      
  }
  save();  //this creates a data.txt file with fav games 
  
}