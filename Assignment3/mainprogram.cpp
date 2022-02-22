/*
@file mainprogram.cpp
@brief mainprogram asks user for input and output file names to translate into Tutnese
@author Lauren Szlosek
*/
#include "FileProcessor.h"
#include <iostream>
using namespace std;

// this should be everything needed in the main function
int main(){
  FileProcessor f; // using default constructor, you can overload
  // ask the user for input and output file names
  string userInput, userOutput;
  cout << "Enter file name of imput: " << std::endl;
  cin >> userInput;
  cout << "Enter file name for output: " << std::endl;
  cin >> userOutput;
  f.processFile(userInput,userOutput);
  return 0;
}
