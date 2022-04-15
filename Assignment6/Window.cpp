/*
@file Delimiters.cpp
@brief Delimiters class
@author Lauren Szlosek
*/
#include "Window.h"
#include <string>
#include <iostream>

using namespace std;
/*
Delimiters()
Constructor
*/
Window::Window(){
  cout << "window" << endl;
  idleTime = 0;
  isOpen = false;
}
/*
~Delimiters()
Destructor
*/
Window::~Window(){}

void Window::OccupiedWithStudent(Student s){
  cout << "o w c" << endl;
  studentAtWindow = s;
  isOpen = false;
}

void Window::NotOccupiedWithStudent(){
  cout << "n o w c" << endl;
  isOpen = true;
}

bool Window::isOccupied(){
  cout << "occ" << endl;
  return isOpen;
}

void Window::addTime(){
  cout << "add time" << endl;
  idleTime++;
}

int Window::getTime(){
  cout << "get time" << endl;
  return idleTime;
}

Student Window::getStudent(){
  cout << "get student" << endl;
  return studentAtWindow;
}
