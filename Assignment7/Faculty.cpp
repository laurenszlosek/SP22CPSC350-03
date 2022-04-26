/*
@file Faculty.cpp
@brief Faculty class
@author Lauren Szlosek
*/
#include <iostream>
#include "Faculty.h"
#include <string>

using namespace std;
/*
Faculty()
Constructor
*/
Faculty::Faculty(){
  facID = 0;
  facName = "";
  facLevel = "";
  facDepartment = "";
}
/*
~Faculty()
Faculty
*/
Faculty::~Faculty(){}

Faculty::Faculty(int id, string name, string level, string dep){
  facID = id;
  facName = name;
  facLevel = level;
  facDepartment = dep;
}

void Faculty::print(){
  cout << facID << endl;
  cout << facName << endl;
  cout << facLevel << endl;
  cout << facDepartment << endl;
}
