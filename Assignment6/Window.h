/*
@file Delimiters.h
@brief header file for Delimiters class
@author Lauren Szlosek
*/
#include "Student.h"
#include <string>
using namespace std;

class Window{
private:
  int idleTime;
  bool isOpen;
  Student studentAtWindow;
public:
  Window();
  ~Window();
  void OccupiedWithStudent(Student s);
  void NotOccupiedWithStudent();
  bool isOccupied();
  void addTime();
  int getTime();
  Student getStudent();
  void removeStudent();
  // reutrn student
};
