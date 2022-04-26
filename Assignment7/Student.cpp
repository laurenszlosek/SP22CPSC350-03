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
Student
*/
Student::~Student(){}

bool Student::operator==(const Student& eq) const {
  return (studentAdvisorID ==  eq.studentAdvisorID);
}
bool Student::operator!=(const Student& eq) const {
  return (studentAdvisorID !=  eq.studentAdvisorID);
}
bool Student::operator>(const Student& eq) const {
  return (studentAdvisorID >  eq.studentAdvisorID);
}
bool Student::operator<(const Student& eq) const {
  return (studentAdvisorID <  eq.studentAdvisorID);
}

int Student::getNum(){
  return studentAdvisorID;
}

void Student::print(){
  cout << studentID << endl;
  cout << studentName << endl;
  cout << studentYear << endl;
  cout << studentMajor << endl;
  cout << studentGPA << endl;
  cout << studentAdvisorID << endl;
}
