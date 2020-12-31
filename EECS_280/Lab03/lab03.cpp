
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

typedef int (*intModifier)(int);
typedef int (*intCombiner)(int, int);



//***** intModifier functions *****//

//EFFECTS: returns 3*x
int triple(int x){
  return 3*x;
}

//EFFECTS: returns x+1
int addOne(int x){
  return x+1;
}

//EFFECTS: returns -1 if x < 7
//         returns 0 if x == 7
//         returns 1 if x > 7
int compareToSeven(int x){
  if (x < 7) {return -1;}
  else if (x == 7) {return 0;}
  else {return 1;}
}




//***** intCombiner functions *****//

//EFFECTS: returns the sum of a and b
int add(int a, int b){
  return a + b;
}

//EFFECTS: returns the product of a and b
int mult(int a, int b){
  return a * b;
}

//EFFECTS: returns the number constructed by appending
//         the digits of b to those of a.  if either
//         a or b is negative, their absolute value is used instead
int concat(int a, int b){
  //determine number of digits in b
  if (a < 0) {a = -a;}
  if (b < 0) {b = -b;}
  int result = b;
  while ((b /= 10) > 0){ a*=10;}
  return result + a*10;
}

//REQUIRES: a and b are positive (nonzero) integers
//EFFECTS: returns the greatest common divisor of a and b
int gcd(int a, int b){
  if (b == 0){
    return a;
  }
  else{
    return gcd(b, a % b);
  }
}




// REQUIRES: src points to an array of size >= length
//           dst points to an array of size >= length
// MODIFIES: dst
// EFFECTS:  dst now contains the results of applying func to
//           each element of src
void map(intModifier func, int src[], int dst[], int length){
  
  // TASK 1 - WRITE YOUR FUNCTION IMPLEMENTATION HERE
  
  for (int i = 0; i < length; i++) {
   
    dst[i] = func(src[i]);
  
  }

}




// REQUIRES: src points to an array of size >= length and length is >= 2
// EFFECTS:  returns the result of folding together the elements
//           of src using func.  In other words, returns
//           func( func( func(src[0], src[1]), src[2]), src[3] ...)
int fold(intCombiner func, int src[], int length){
  
  //TASK 2 - WRITE YOUR FUNCTION IMPLEMENTATION HERE
 
  int result = func(src[0], src[1]);;
  
  for (int i = 2; i < length; i++) {
  
    result = func(result, src[i]);
  
  }

  return result;

}


void printIntArray(int arr[], int length){
  cout << "{";
  if (length > 0){
    cout << arr[0];
  }
  for(int i = 1; i < length; ++i){
    cout << ", " << arr[i];
  }
  cout << "}";
}

// Testing code
int main(){

  int arr1[4] = {1, 2, 3, 4};
  int arr2[4] = {0, 0, 0, 0};
  int arr3[4] = {0, 0, 0, 0};
  int arr4[4] = {0, 0, 0, 0};

  cout << "Testing map." << endl;
  cout << "  setting arr1 = {1,2,3,4}" << endl << endl;

  cout << "  mapping from arr1 to arr2 using triple" << endl;
  map(triple, arr1, arr2, 4);
  cout << "  arr2 = ";
  printIntArray(arr2, 4);  cout << endl << endl;

  cout << "  mapping from arr2 to arr3 using addOne" << endl;
  map(addOne, arr2, arr3, 4);
  cout << "  arr3 = ";
  printIntArray(arr3, 4);  cout << endl << endl;

  cout << "  mapping from arr3 to arr4 using compareToSeven" << endl;
  map(compareToSeven, arr3, arr4, 4);
  cout << "  arr4 = ";
  printIntArray(arr4, 4);  cout << endl << endl;


  
  cout << "Testing fold." << endl;
  cout << "  fold(add, arr1, 4) = " << fold(add, arr1, 4) << endl;
  cout << "  fold(add, arr2, 4) = " << fold(add, arr2, 4) << endl;
  cout << "  fold(add, arr3, 4) = " << fold(add, arr3, 4) << endl;
  cout << "  fold(add, arr4, 4) = " << fold(add, arr4, 4) << endl;
  cout << endl;

  cout << "  fold(mult, arr1, 4) = " << fold(mult, arr1, 4) << endl;
  cout << "  fold(mult, arr2, 4) = " << fold(mult, arr2, 4) << endl;
  cout << "  fold(mult, arr3, 4) = " << fold(mult, arr3, 4) << endl;
  cout << "  fold(mult, arr4, 4) = " << fold(mult, arr4, 4) << endl;
  cout << endl;

  cout << "  fold(concat, arr1, 4) = " << fold(concat, arr1, 4) << endl;
  cout << "  fold(concat, arr2, 4) = " << fold(concat, arr2, 4) << endl;
  cout << "  fold(concat, arr3, 4) = " << fold(concat, arr3, 4) << endl;
  cout << "  fold(concat, arr4, 4) = " << fold(concat, arr4, 4) << endl;
  cout << endl;

  cout << "  fold(gcd, arr1, 4) = " << fold(gcd, arr1, 4) << endl;
  cout << "  fold(gcd, arr2, 4) = " << fold(gcd, arr2, 4) << endl;
  cout << "  fold(gcd, arr3, 4) = " << fold(gcd, arr3, 4) << endl;
  cout << "  fold(gcd, arr4, 4) = " << fold(gcd, arr4, 4) << endl;
  cout << endl;
  

  return 0;
}
