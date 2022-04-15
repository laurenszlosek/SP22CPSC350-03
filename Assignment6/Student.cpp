/*
@file Delimiters.cpp
@brief Delimiters class
@author Lauren Szlosek
*/
#include "Student.h"
#include <string>
#include <iostream>

using namespace std;
/*
Delimiters()
Constructor
*/
Student::Student(){
  cout << "student" << endl;
  waitTime = 0;
  arrivalTime = 0;
  atWindow = false;
  windowNumber = -1;
}
//over loaded
Student::Student(int arrival, int wait){
  waitTime = wait;
  arrivalTime = arrival;
}
/*
~Delimiters()
Destructor
*/
Student::~Student(){}

void Student::print(){
  cout << "waitTime " << waitTime << endl;
  cout << "arrivalTime " << arrivalTime << endl;
}

void Student::nowAtWindow(){
  cout << "n o w" << endl;
  atWindow = true;
}

bool Student::isAtWindow(){
  cout << "is at window" << endl;
  return atWindow;
}

void Student::addTime(){
  cout << "add time" << endl;
  waitTime++;
}

void Student::subtractTime(){
  cout << "subtract time" << endl;
  if (waitTime == 0){
    return;
  } else {
    waitTime--;
  }
}

int Student::getWaitTime(){
  cout << "get wait time" << endl;
  return waitTime;
}

void Student::atThisWindow(int i){
  cout << "at this window" << endl;
  windowNumber = i;
}

bool Student::isOutOfTime(){
  cout << "is out of time" << endl;
  return (waitTime == 0);
}
