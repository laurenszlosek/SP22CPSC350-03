/*
@file Model.h
@brief header file for Model class
@author Lauren Szlosek
*/
using namespace std;
#include <string>

class Model{
public:
  // implement constructor and desctructor
  Model();
  ~Model();
  string translateStringCharacter(char c);
  string translateDoubleCharacter(char c);
};
