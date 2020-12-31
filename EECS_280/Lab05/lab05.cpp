
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;


/***** TASK 1 *****/

// REQUIRES: str1 and str2 point to C-strings
// EFFECTS:  If st1 and str2 are identical (contain exactly
//           the same characters), returns 0.
//           If the first differing character has a greater
//           value in st1 than in str2, return a positive number.
//           Otherwise, return a negative number.
int strcmp_eecs280(const char *str1, const char *str2){

  if (strlen(str1) > strlen(str2)) {
    return 1;
  }
  
  else if (strlen(str1) < strlen(str2)) {
    return -1;
  }
  
  else {
    return 0;
  }

}



/***** TASK 2 *****/


// EFFECTS:  Prompts the user to end a word, returns that word
//           as a string.
string getUserWord(){
  // TYPE CODE HERE AS DIRECTED IN LAB DOCUMENT

  cout << "Please enter a word: ";
  
  string get_word;
  
  getline(cin, get_word);
  
  cout << endl;
  
  return get_word;
  
}



// EFFECTS:  Searches words.txt for the word passed as a
//           parameter.  If found, return true.  Otherwise false.
//           If words.txt cannot be opened, prints an error
//           message to cout and returns false.
bool findWord(string word){
  
  ifstream fin;
  
  fin.open("words.txt");
  
  string word_in_txt;

  if (!fin.is_open()) {
  
    cout << "file cannot be opened"<< endl;
    return false;
  
  }

  while (fin >> word_in_txt) {

    if (strcmp_eecs280((word_in_txt).c_str(), word.c_str()) == 0) {
      return true;
    }

  }

  fin.close();
  
  return false;
}


void test() {
  
  cout <<strcmp_eecs280("turtle", "frog") << endl; //should be positive
  cout <<strcmp_eecs280("turtle", "turtles")<< endl; //should be negative
  cout <<strcmp_eecs280("", "frog")<< endl;//  should be negative
  cout <<strcmp_eecs280("lizard", "lizard")<< endl;//  0
}

/***** YOU DO NOT NEED TO MODIFY CODE BELOW THIS POINT *****/


// Testing code
int main(){

  test();
  cout << "Welcome to eecs280 spell checker!" << endl;
  cout << "You may quit at any time by typing \"quit\"." << endl;

  for(string userWord; strcmp((userWord = getUserWord()).c_str(), "quit") != 0; ){
    
    if (findWord(userWord)){
      cout << "It appears " << userWord << " is spelled correctly!";
    }
    else{
      cout << "Oops. " << userWord << " is not a correctly spelled word!";
    }

    cout << endl << endl;
  }
  
  cout << "See you again soon.  Happy spelling!" << endl;

  return 0;
}
