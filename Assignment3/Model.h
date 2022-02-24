/*
@file Model.h
@brief header file for Model class
@author Lauren Szlosek
*/
using namespace std;
#include <string>

class Model{
public:
  /*
  Model()
  constructor
  */
  Model();
  /*
  ~Model()
  destructor
  */
  ~Model();
  /*
  translateStringCharacter()
  translate single character into Tutnese
  @param character c, letter being translated
  @return string, translated letter
  */
  string translateStringCharacter(char c);
  /*
  translateDoubleCharacter()
  translate repeated character into Tutnese
  @param character c, letter being translated
  @return string, translated letter
  */
  string translateDoubleCharacter(char c);
};
