/*
@file Program.h
@brief header file for Program class
@author Lauren Szlosek
*/
#include "BST.h"
#include "Student.h" // bye
#include "Faculty.h"
using namespace std;

class Program{
public:
  BST<Student> stuBST;
  BST<Faculty> facBST;
public:
  Program();
  ~Program();
private:
  void startProgram();
  void optionOne();
  void optionTwo();
  void optionThree();
  void optionFour();
  void optionFive();
  void optionSix();
  void optionSeven();
  void optionEight();
  void optionNine();
  void optionTen();
  void optionEleven();
  void optionTwelve();
  void optionThirteen();
  void optionFourteen();
  void readStudentFile();
  void readFacultyFile();
  void writeStudentFile(int i, string n, string y, string m, double g, int a);
  void writeFacultyFile(int i, string a, string b, string c);
};
