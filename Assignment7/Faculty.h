/*
@file Faculty.h
@brief header file for Faculty class
@author Lauren Szlosek
*/
#include <string>
#include "Alist.h"
using namespace std;


class Faculty{
private:
  int facID;
  string facName;
  string facLevel;
  string facDepartment;
  //Alist<int> adviseeID; //and	a list of integers corresponding to all the faculty member’s advisees’ ids.
public:
  Faculty();
  ~Faculty();
  Faculty(int i, string n, string l, string d);
  bool operator==(const Faculty& eq) const;
  bool operator!=(const Faculty& eq) const;
  bool operator<(const Faculty& eq) const;
  bool operator>(const Faculty& eq) const;
  int getFacultyID();
  void print();
};
