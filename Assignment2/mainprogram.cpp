/*
@file mainprogram.cpp
@brief asks user for a string and the prints the appropriate output
@author Lauren Szlosek
*/
#include <iostream>
#include <string>
#include "Parser.h"
int main(){
  std::string userString;
  Parser parser;

  std::cout << "Enter any statement: " << std::endl;
  std::getline(std::cin, userString);
  parser.sortString(userString);
  parser.saveToFile();
}
