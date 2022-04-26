/*
@file Student.h
@brief header file for Student class
@author Lauren Szlosek
*/
#include <string>
using namespace std;


class Student{
private:
  int studentID;
  string studentName;
  string studentYear;
  string studentMajor;
  double studentGPA;
  int studentAdvisorID;

public:
  Student();
  Student(int i, string n, string y, string m, double g, int d);
  ~Student();
  bool operator==(const Student& eq) const;
  bool operator!=(const Student& eq) const;
  bool operator<(const Student& eq) const;
  bool operator>(const Student& eq) const;
  int getStudentID();
  void print();
};
