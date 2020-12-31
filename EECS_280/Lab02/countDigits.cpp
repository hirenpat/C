
#include <iostream>
#include <cassert>

using namespace std;

//----------------------------------------------------------------//
// REQUIRES: 0 <= digit <= 9, n >=0
// EFFECTS: Returns the number of times "digit" appears in "n".
//      Uses iteration.
int countDigitsIterative(int n, int digit){
  
  // checking the requirements
  assert((digit >= 0 && digit <= 9) && n >= 0);
  
  int count_digit = 0;
  
  if (n == 0 && digit == 0) {
    count_digit++;
  }

  while (n > 0) {
    
    // if last digit of a number = digit
    if (n % 10 == digit) {
      count_digit++;
    }
    // it removes the last digit of a number
    n = n / 10;
  }
  
  return count_digit;
}

//----------------------------------------------------------------//
// REQUIRES: 0 <= digit <= 9, n >= 0
// EFFECTS: Returns the number of times "digit" appears in "n".
//      Uses recursion.
int countDigitsRecursive(int n, int digit){
  
  // checking the requirements
  assert((digit >= 0 && digit <= 9) && n >= 0);

  // this is base case
  if (n == 0 && digit == 0) {
    return 1;
  }
  
  // if n doesn't match with digit and n < 10
  else if (n < 10 && n != digit) {
    return 0;
  }
  
  // if last digit of a number is equal digit
  else if (n % 10 == digit) {
    return 1 + countDigitsRecursive(n / 10, digit);
  }
  
  // if last digit of a number is not equal digit
  else {
    return 0 + countDigitsRecursive(n / 10, digit);
  }
}

int countDigitsTail_helper(int n, int digit, int count_digit) {
  
  // checking the requirements
  assert((digit >= 0 && digit <= 9) && n >= 0);
  
  // this is base case
  if (n == 0 && digit == 0) {
    return 1;
  }
  
  else if (n < 10 && n != digit) {
    return count_digit;
  }
  
  // if last digit of a number is equal digit
  else if (n % 10 == digit) {
    return countDigitsTail_helper(n / 10, digit, count_digit + 1);
  }
  
  // if last digit of a number is not equal digit
  else {
    return countDigitsTail_helper(n / 10, digit, count_digit + 0);
  }
}


// REQUIRES 0 <= digit <= 9, n >= 0
// EFFECTS: Returns the number of times "digit" appears int "n".
//      Uses tail recursion.
int countDigitsTail(int n, int digit){

  int count_digit = 0;

  return countDigitsTail_helper(n, digit, count_digit);
  
}

// Helper function for testing code
void countDigitsTest(int n, int digit){
  cout << endl << "  CountDigits test.  How many " << digit << "s in " << n << endl;
  cout << "    Iterative:      " << countDigitsIterative(n, digit) << endl;
  cout << "    Recursive:      " << countDigitsRecursive(n, digit) << endl;
  cout << "    Tail Recursive: " << countDigitsTail(n, digit) << endl;
}

// Testing code for countDigits
int main() {
  cout << "Running tests for countDigits..." << endl;
  countDigitsTest(2120, 2);
  countDigitsTest(2120, 0);
  countDigitsTest(123, 7);
  countDigitsTest(0, 0);
  countDigitsTest(0, 8);
  
  return 0;
}



