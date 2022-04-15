/*
@file Delimiters.h
@brief header file for Delimiters class
@author Lauren Szlosek
*/
#include <string>
using namespace std;


class Student{
private:
  int waitTime;
  int arrivalTime;
  bool atWindow;
  int windowNumber;
public:
  Student();
  Student(int arrival, int wait);
  ~Student();
  void print();
  void nowAtWindow();
  bool isAtWindow();
  void addTime();
  void subtractTime();
  int getWaitTime();
  void atThisWindow(int windowNum);
  bool isOutOfTime();
//private:

  //void timeEnded();
};
