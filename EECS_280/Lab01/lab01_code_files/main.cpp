#include <cassert>
#include <iostream>
#include <iomanip>
#include "eecs280math.h"

using namespace std;



int main() {
  cout << "Hello, YOUR NAME HERE" << endl;

  double a = 0;
  double b = 0;
  
  cout << "Please enter a number: ";
  cin >> a;
  cout << endl;

  cout << "Please enter another number: ";
  cin >> a;
  cout << endl;
  
  cout << "The sum of the numbers is " << add(a, b) << endl;
}
