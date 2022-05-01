/*
@file Student.cpp
@brief Student class
@author Lauren Szlosek
*/
#include "Student.h"
#include <string>
#include <iostream>

using namespace std;
/*
Student()
Constructor
*/
Student::Student(){
  studentID = 0;
  studentName = "";
  studentYear = "";
  studentMajor = "";
  studentGPA = 0.0;
  studentAdvisorID = 0;
}
/*
Student()
Overloaded Constructor
@param int id, string name, string year, string major, double gpa, int adID, student parameters
*/
Student::Student(int id, string name, string year, string major, double gpa, int adID){
  studentID = id;
  studentName = name;
  studentYear = year;
  studentMajor = major;
  studentGPA = gpa;
  studentAdvisorID = adID;
}
/*
~Student()
Destructor
*/
Student::~Student(){}
/*
operator==
operation overloading for ==
*/
bool Student::operator==(const Student& eq) const {
  return (studentAdvisorID ==  eq.studentAdvisorID);
}
/*
operator!=
operation overloading for !=
*/
bool Student::operator!=(const Student& eq) const {
  return (studentAdvisorID !=  eq.studentAdvisorID);
}
/*
operator>
operation overloading for >
*/
bool Student::operator>(const Student& eq) const {
  return (studentAdvisorID >  eq.studentAdvisorID);
}
/*
operator<
operation overloading for <
*/
bool Student::operator<(const Student& eq) const {
  return (studentAdvisorID <  eq.studentAdvisorID);
}
/*
getStudentID()
@return int, student ID
*/
int Student::getStudentID(){
  return studentID;
}
/*
getAdvisorID()
@return int, advisor ID
*/
int Student::getAdvisorID(){
  return studentAdvisorID;
}
/*
setAdvisor()
changes advisor ID
@param int ad, new advisor id
*/
void Student::setAdvisor(int ad){
  studentAdvisorID = ad;
}
/*
print()
prints student object information
*/
void Student::print(){
  cout << endl;
  cout << "ID: " << studentID << endl;
  cout << "Name: " << studentName << endl;
  cout << "Grade: " << studentYear << endl;
  cout << "Major: " << studentMajor << endl;
  cout << "GPA: " << studentGPA << endl;
  cout << "Advisor's ID: " << studentAdvisorID << endl;
  cout << endl;
}
