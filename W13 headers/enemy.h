#include <string>
// instead of using namespace std;
using std::string;

//getters and setters declared in header
class enemy{
private:
  string name;
  int health;

public:
  enemy(string givenName = "Bad Guy McGee");  
//default name in header but not in source file
  void status();

  // like a set function, not quite the same. (Setter?)
  void changeHealth(int by);
  int getHealth();

  void setName(string to); 
//string to? Set name to--this. can also be givenName or n
  string getName();

};