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
  //Alist facStudents = new facStudents;
}
/*
~Faculty()
Destructor
*/
Faculty::~Faculty(){}
/*
~Faculty()
Overloaded Constructor
@param int id, string name, string level, string dep, faculty parameters
*/
Faculty::Faculty(int id, string name, string level, string dep){
  facID = id;
  facName = name;
  facLevel = level;
  facDepartment = dep;
}
/*
operator==
operation overloading for ==
*/
bool Faculty::operator==(const Faculty& eq) const {
  return (facID ==  eq.facID);
}
/*
operator!=
operation overloading for !=
*/
bool Faculty::operator!=(const Faculty& eq) const {
  return (facID !=  eq.facID);
}
/*
operator>
operation overloading for >
*/
bool Faculty::operator>(const Faculty& eq) const {
  return (facID >  eq.facID);
}
/*
operator<
operation overloading for <
*/
bool Faculty::operator<(const Faculty& eq) const {
  return (facID <  eq.facID);
}
/*
getFacultyID()
Overloaded Constructor
@return int, returns faculty id
*/
int Faculty::getFacultyID(){
  return facID;
}
/*
print()
prints faculty information
*/
void Faculty::print(){
  cout << endl;
  cout << "ID: " << facID << endl;
  cout << "Name: " << facName << endl;
  cout << "Level: " << facLevel << endl;
  cout << "Department: " << facDepartment << endl;
  cout << endl;
}
/*
addAdvisees()
adds student to advisee list
@param int i, student id
*/
void Faculty::addAdvisees(int i){
  myList.push_back(i);
}
/*
getAdviseesID()
adds student to advisee list
@param int i, student id
@return int, returns student's id
*/
int Faculty::getAdviseesID(int i){
  list<int>::iterator it = myList.begin();
  advance(it, i);
  return *it;
}
/*
numOfStudents()
adds student to advisee list
@param int i, student id
@return int, returns student's id
*/
int Faculty::numOfStudents(){
  return myList.size();
}
/*
removeAdviseesID()
remove student with given id
@param int i, student id
*/
void Faculty::removeAdviseesID(int i){
  myList.remove(i);
}
