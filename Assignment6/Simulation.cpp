/*
@file Delimiters.cpp
@brief Delimiters class
@author Lauren Szlosek
*/
#include "Simulation.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
//#include "Alist.h"

using namespace std;
/*
Delimiters()
Constructor
*/
Simulation::Simulation(){
  //cout << "sim called" << endl;
  startSimulation();

}
/*
~Delimiters()
Destructor
*/
Simulation::~Simulation(){}


void Simulation::startSimulation(){
  cout << "sim called" << endl;
  //queue<Student> studentQueue;
  string fileName;
  string line;
  //ifstream imputFile;
  //int windowSize;
  int timeInterval;
  int studentTime;
  int numberOfStudents;
  currentTime = 1;

  cout << "Enter File Name: " << endl;
  cin >> fileName;

  imputFile.open(fileName);
  if(!imputFile.is_open()){
    cout << "Error with file name" << endl;
  }
  imputFile >> windowSize;
  windowList[windowSize];
  for (int i = 0; i < windowSize; i++){
    Window tempWindow = windowList[i];
    tempWindow.NotOccupiedWithStudent();
  }



  // BEGIN

   while (imputFile) { // all in one tick
     imputFile >> timeInterval;
     while ((timeInterval != currentTime)){
       atTick();
       currentTime++;
       if (currentTime == 10){
         break;
       }
     }
     imputFile >> numberOfStudents;
     for (int i = 0; i < numberOfStudents; i++){
        imputFile >> studentTime;
        Student student(timeInterval, studentTime);
        studentQueue.push(student);
      }
      updateWindows();
      atTick();
      currentTime++;
   }
  imputFile.close();
}

void Simulation::atTick(){
  cout << "at tick" << endl;
    // add time to empty window
    for (int i = 0; i < windowSize; i++){
      Window tempWindow = windowList[i];
      if (!tempWindow.isOccupied()){
        cout << "a" << endl;
        tempWindow.addTime();
        cout << "b" << endl;
      }
    }
    // add time to student wait time if in queue
    for (int i = 0; i < studentQueue.size(); i++){
      cout << "g" << endl;
      if (studentQueue.empty()){
        break;
      }
      cout << "h" << endl;
      Student temp = studentQueue.front();
      cout << "f" << endl;
      studentQueue.pop();
      cout << "c" << endl;
      temp.addTime();
      cout << "d" << endl;
      studentQueue.push(temp);
      cout << "e" << endl;
    }
    // subract time if student at window (check if time is up - delete[])
    for (int i = 0; i < windowSize; i++){
      Window tempWindow = windowList[i];
      if (tempWindow.isOccupied()){
        Student tempStudent = tempWindow.getStudent();
        tempStudent.subtractTime();
        if (tempStudent.isOutOfTime()){
          tempWindow.NotOccupiedWithStudent();
        }
      }
    }
}

void Simulation::updateWindows(){
  cout << "update windows" << endl;
  // if window is empty then add pop student and add to window
  for (int i = 0; i < windowSize; i++){
    Window tempWindow = windowList[i];
    if (!tempWindow.isOccupied()){
      Student tempStudent = studentQueue.front();
      studentQueue.pop();
      tempStudent.nowAtWindow();
      tempWindow.OccupiedWithStudent(tempStudent);
    }
  }
}

void Simulation::calculations(){
// 1- The	mean	student	wait	time
double meanWait;

// 2- The	median	student	wait	time
double median;

// 3- The	longest	student	wait	time
double longestWait;

// 4- The	number	of	students	waiting	over	10	minutes
int overTen;

// 5- The	mean	window	idle	time
double meanIdle;

// 6- The	longest	window	idle	time
double longestIdle;

// 7- Number	of	windows	idle	for	over	5	minutes.
int overFive;


}
