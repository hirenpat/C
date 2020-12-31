
#include <iostream>

using namespace std;


/***** TASK 1 *****/

// REQUIRES: there are at least size elements in row[]
// EFFECTS:  For each element of row (in sequence):
//             if that element is a 0, prints out "  " to cout
//             if that element is a 1, prints out "# " to cout
//             (note the extra space after each)
//           DOES NOT print any newlines
void printRowIndex(const int row[], int size){

  
  for (int i = 0; i < size; ++i) {
    
    if (row[i] == 0) {
      cout << "  ";
    }
    
    if (row[i] == 1) {
      cout << "# ";
    }
    
  }
  // TASK 1 - REPLACE WITH YOUR CODE
  // NOTE: You may use array indexing in printRowIndex
  

}

// REQUIRES: row points to an array with at least size elements
// EFFECTS:  For each element of row (in sequence):
//             if that element is a 0, prints out "  " to cout
//             if that element is a 1, prints out "# " to cout
//             (note the extra space after each)
//           DOES NOT print any newlines
void printRowPtr(const int *row, int size){

  // TASK 1 - REPLACE WITH YOUR CODE
  // NOTE: You may NOT use array indexing in printRowPtr
  //       Use pointer arithmetic instead
  
  for (const int *ptr = row; ptr < row + size; ++ptr) {
    
    if (*ptr == 0) {
      cout << "  ";
    }
    
    else {
      cout << "# ";
    }
    
  }

}


/***** TASK 2 *****/

// REQUIRES: row points to an array with at least size elements
// EFFECTS: all elements in row that are 1 are switched to 0
//          all elements in row that are 0 are switched to 1
void invertColors(int *row, int size){

  // TASK 2 - YOUR CODE HERE
  
  for (int *ptr = row; ptr < row + size; ++ptr) {
    
    if (*ptr == 0) {
      *ptr = 1;
    }
    
    else {
      *ptr = 0;
    }
    
  }

}


// REQUIRES: row points to an array with at least size elements
// EFFECTS: all elements are "shifted" right by one unit
//          for example, [0,1,1,0,1,1,1,1,0,1]
//          would become [1,0,1,1,0,1,1,1,1,0]
void slideRight(int *row, int size){

  int end = *(row + size - 1);
  
  int *ptr;
  
  for (ptr = row + size - 1 ; ptr > row ; --ptr) {
    
    *ptr = *(ptr - 1);
    
  }
  
  *ptr = end;

}


// REQUIRES: row points to an array with at least size elements
// EFFECTS: the order of elements in row is reversed
//          for example, [0,1,1,0,1,1,1,1,0,1]
//          would become [1,0,1,1,1,1,0,1,1,0]
void flipHorizontal(int *row, int size){

  //TASK 2 - YOUR CODE HERE
  
  int dup_row[size];
  
  int *ptr = row + size - 1;
  for (int i = 0; i < size; ++i) {
    dup_row[i] = *ptr;
    --ptr;
  }
  
  ptr = row;
  for (int i = 0; i < size; ++i) {
    *ptr = dup_row[i];
    ++ptr;
  }

}




/***** YOU DO NOT NEED TO MODIFY CODE BELOW THIS POINT *****/

// REQUIRES: grid is a pointer to the start of a "2D array"
//           with numRows rows of rowSize elements each
// EFFECTS:  Prints out the ASCII art picture stored in grid.
//           0s are printed as "  "
//           1s are printed as "# "
//           Followed by a newline.
void printGrid(const int *grid, int numRows, int rowSize){
  
  // Print the header
  cout << "Using printRowIndex       Using printRowPtr" << endl;
  for(int i = 0; i < rowSize; ++i){
    cout << " " << i;
  }
  cout << "   |  ";
  for(int i = 0; i < rowSize; ++i){
    cout << " " << i;
  }

  cout << endl;
  
  // We take advantage of the fact that 2D arrays declared with
  // the int grid[r][c] syntax are actually stored as a
  // contiguous segment of r*c ints.
  int currentRow = 0;
  int length = numRows*rowSize;
  for(const int *ptr = grid; ptr < grid + length; ptr += rowSize){
    cout << currentRow++;
    printRowIndex(ptr, rowSize);
    cout << "  |   ";
    printRowPtr(ptr, rowSize);
    cout << endl;
  }
}


// REQUIRES: grid is a pointer to the start of a "2D array"
//           with numRows rows of rowSize elements each
// EFFECTS:  Applies the transformation specified by trans
//           to each row in the grid
void applyTransformation(int *grid, void (*trans)(int*, int),
                         int numRows, int rowSize){
  int length = numRows * rowSize;
  for(int *ptr = grid; ptr < grid + length; ptr += rowSize){
    trans(ptr, rowSize);
  }
}


// Testing code
int main(){

  // Create the grid for the smiley face picture
  int grid[10][10] = { 
    {0,0,1,1,1,1,1,0,0,0}, 
    {0,1,0,0,0,0,0,1,0,0}, 
    {1,0,1,0,0,0,1,0,1,0}, 
    {1,0,0,0,0,0,0,0,1,0}, 
    {1,0,0,0,1,0,0,0,1,0}, 
    {1,0,0,0,0,0,0,0,1,0}, 
    {1,0,1,0,0,0,1,0,1,0}, 
    {1,0,0,1,1,1,0,0,1,0}, 
    {0,1,0,0,0,0,0,1,0,0}, 
    {0,0,1,1,1,1,1,0,0,0}
  };

  //Need this because type of grid is int(*)[10] which we don't want
  int *gridPtr = (int*)grid;

  // Print the picture
  cout << "Original:" << endl;
  printGrid(gridPtr, 10, 10);
  cout << endl;

  // Apply invertColors and print
  cout << "After inverting colors:" << endl;
  applyTransformation(gridPtr, invertColors, 10, 10);
  printGrid(gridPtr, 10, 10);
  cout << endl;
  
  // Apply slideRight
  cout << "After sliding right:" << endl;
  applyTransformation(gridPtr, slideRight, 10, 10);
  printGrid(gridPtr, 10, 10);
  cout << endl;

  // Apply horizontalFlip
  cout << "After horizontal flip:" << endl;
  applyTransformation(gridPtr, flipHorizontal, 10, 10);
  printGrid(gridPtr, 10, 10);
  cout << endl;
}
