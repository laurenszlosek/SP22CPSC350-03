/*
@file Faculty.h
@brief header file for Faculty class
@author Lauren Szlosek
*/
#include <string>
#include <list>
using namespace std;

class Faculty{
private:
  int facID;
  string facName;
  string facLevel;
  string facDepartment;
  list<int> myList;
  //List<Object> list = new LinkedList<Object>();
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
  void addAdvisees(int i);
  int getAdviseesID(int i);
  int numOfStudents();
  void removeAdviseesID(int i);
};
