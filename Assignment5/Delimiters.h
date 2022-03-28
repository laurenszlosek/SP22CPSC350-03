/*
@file Delimiters.h
@brief header file for Delimiters class
@author Lauren Szlosek
*/
#include <string>
using namespace std;


class Delimiters{
public:
  Delimiters();
  ~Delimiters();
private:
  string readFile();
  bool isCorrect(string s);
};
