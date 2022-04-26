/*
@file Faculty.h
@brief header file for Faculty class
@author Lauren Szlosek
*/
#include <string>
using namespace std;


class Faculty{
private:
  int facID;
  string facName;
  string facLevel;
  string facDepartment;
  //and	a list of integers corresponding to all the faculty member’s advisees’ ids.
public:
  Faculty();
  ~Faculty();
  Faculty(int i, string n, string l, string d);
  void print();
};
