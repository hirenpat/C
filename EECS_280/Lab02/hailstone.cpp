
#include <iostream>
#include <cassert>

using namespace std;


//--------------------------------------------------------------//
// REQUIRES: n >=1
// EFFECTS: Prints the hailstone sequence starting at n.
//      Uses iteration.
void hailstoneIterative(int n){
  
  // checking the requirements
  assert(n >= 1);
  
  while (n > 1) {

    cout << n << ", ";
    //if n is even
    if (n % 2 == 0) {
      n = n /2;
    }
  
    //if n is odd
    else {
      n = (3 * n) + 1;
    }
    
  }
  cout << n ;
}


//--------------------------------------------------------------//
// REQUIRES: n >= 1
// EFFECTS: Prints the hailstone sequence starting at n.
//      Uses recursion.
void hailstoneTail(int n) {
  
  // checking the requirements
  assert(n >= 1);
  
  // base case
  if (n == 1) {
    cout << n ;
  }
  
  //if n is even
  else if (n % 2 == 0) {
    cout << n << ", ";
    hailstoneTail(n / 2);
  }
  
  //if n is odd
  else {
    cout << n << ", ";
    hailstoneTail((3*n) + 1);
  }
}

// Helper function for testing code
void hailstoneTest(int n){
  cout << endl << "  Hailstone test for n = " << n << endl;
  cout << "    Iterative: "; hailstoneIterative(n);  cout << endl;
  cout << "    Recursive: "; hailstoneTail(n);  cout << endl;
}

// Testing code for hailstone
int main(){
  cout << "Running hailstone tests for lab 2..." << endl;
  hailstoneTest(7);
  hailstoneTest(8);
  hailstoneTest(14);
}