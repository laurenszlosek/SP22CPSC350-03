/*
@file Delimiters.cpp
@brief Delimiters class
@author Lauren Szlosek
*/
#include "Delimiters.h"
#include "AStack.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
/*
Delimiters()
Constructor
*/
Delimiters::Delimiters(){
  isCorrect(readFile());
}
/*
~Delimiters()
Destructor
*/
Delimiters::~Delimiters(){}
/*
readFile()
reads content of file from the user
@return string: contents from file
*/
string Delimiters::readFile(){
  ifstream fileName;
  string userImput;
  string line;
  string fileContents;

  cout << "Enter file name: " << endl;
  cin >> userImput;
  fileName.open(userImput);
  if (!fileName.is_open()){
    cout << "Error with Input File Name." << endl;
  }
  while (getline(fileName,line)){
    fileContents += line + '\n';
  }
  //cout << fileContents << endl;
  return fileContents;
}
/*
isCorrect()
checks for Delimiters errors
@return bool: true or false
*/
bool Delimiters::isCorrect(string s){
  AStack<char> arr(s.length());
  int lineCounter = 1;
  for (int i = 0; i < s.length(); i++){
    char currChar = s[i];

    switch (currChar){ // https://www.programiz.com/cpp-programming/switch-case
      case '\n':
        lineCounter++;
        break;
      case '{':
      case '(':
      case '[':
        arr.push(currChar);
        break;
      case '}':
      case ')':
      case ']':
        if(!arr.isEmpty()){
          char topChar = arr.pop();
          if ((currChar == '}' && topChar != '{') || (currChar == ')' && topChar != '(') || (currChar == ']' && topChar != '[')){
            cout << "Dilimeter missing at line: " << lineCounter << endl;
            return false;
          }
        } else {
          cout << "Dilimeter missing at line: " << lineCounter << endl;
          return false;
        }
        break;
      default: break;
    }
  }
  cout << "Reached end of file: no Dilimeter issues" << endl;
  return true;

}
