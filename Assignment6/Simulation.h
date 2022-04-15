/*
@file Delimiters.h
@brief header file for Delimiters class
@author Lauren Szlosek
*/
using namespace std;
#include <fstream>
#include <queue>
#include "Window.h"
//#include "Student.h"

class Simulation{
private:
  // queue<Student> studentQueue;
  // //ifstream imputFile;
  // int windowSize;
  // int timeInterval;
  // int studentTime;
  // int numberOfStudents;
  int currentTime;
  ifstream imputFile;
  Window windowList[0];
  queue<Student> studentQueue;
  int windowSize;
public:
  Simulation();
  ~Simulation();
private:
  void startSimulation();
  void calculations();
  void atTick();
  void updateWindows();
};
