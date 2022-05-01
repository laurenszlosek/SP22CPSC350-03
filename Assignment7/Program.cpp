/*
@file Program.cpp
@brief Program class
@author Lauren Szlosek
*/
#include "Program.h"
#include <iostream>
#include <fstream>

using namespace std;
/*
Program()
Constructor
*/
Program::Program(){
  readStudentFile();
  readFacultyFile();
  startProgram();
}
/*
~Program()
Destructor
*/
Program::~Program(){}
/*
startProgram()
prompts the user and starts the program
*/
void Program::startProgram(){
  //set up Tables
  // Student student1(2365971,"lauren1","sophmore","SE",4.5,2346524);
  // Student student2(3365232,"harry2","junior","singer",4.0,5642455);
  // Student student3(1734233,"taylor3","senior","songwriter",4.6,2345636);
  // stuBST.insert(new TreeNode<Student>(student1.getStudentID(),student1));
  // stuBST.insert(new TreeNode<Student>(student2.getStudentID(),student2));
  // stuBST.insert(new TreeNode<Student>(student3.getStudentID(),student3));
  // stuBST.printTree();
  //
  // Faculty fact1(2346524,"rao4","phd", "CS");
  // Faculty fact2(5642455,"ashley5","prof", "VP");
  // Faculty fact3(2345636,"cp6","cool prof", "E");
  // fact3.addAdvisees(2365971);
  // fact3.addAdvisees(3365232);
  // facBST.insert(new TreeNode<Faculty>(fact1.getFacultyID(),fact1));
  // facBST.insert(new TreeNode<Faculty>(fact2.getFacultyID(),fact2));
  // facBST.insert(new TreeNode<Faculty>(fact3.getFacultyID(),fact3));
  // facBST.printTree();

   while (true) {
    int userChoice;
    cout << endl;
    cout << "Enter An Option" << endl;
    cout << endl;
    cout << "1 - Print List of Students" << endl;
    cout << "2 - Print List of Faculty" << endl;
    cout << "3 - Find Student" << endl;
    cout << "4 - Find Faculty" << endl;
    cout << "5 - Find Advisor" << endl;
    cout << "6 - Find Factulty's Advisees" << endl;
    cout << "7 - Add a New Student" << endl; // has to have an advisor or something
    cout << "8 - Delete a Student" << endl;
    cout << "9 - Add a New Faculty Member" << endl;
    cout << "10 - Delete A Faculty Member" << endl;
    cout << "11 - Change Student Advisor" << endl;
    cout << "12 - Remove Advisee" << endl;
    cout << "13 - Rollback" << endl;
    cout << "14 - Exit" << endl;
    cin >> userChoice;
    cout << endl;

    if (userChoice == 1){
      optionOne();
    } if (userChoice == 2){
      optionTwo();
    } if (userChoice == 3){
      optionThree();
    } if (userChoice == 4){
      optionFour();
    } if (userChoice == 5){
      optionFive();
    } if (userChoice == 6){
      optionSix();
    } if (userChoice == 7){
      optionSeven();
    } if (userChoice == 8){
      optionEight();
    } if (userChoice == 9){
      optionNine();
    } if (userChoice == 10){
      optionTen();
    } if (userChoice == 11){
      optionEleven();
    } if (userChoice == 12){
      optionTwelve();
    } if (userChoice == 13){
      // Rollback
    } if (userChoice == 14){
      optionFourteen();
      return;
    }
  }
}
/*
optionOne()
Print	all	students	and	their	information	(sorted	by	ascending	id	#)
*/
void Program::optionOne(){
  // Print	all	students	and	their	information	(sorted	by	ascending	id	#)
  cout << endl;
  cout << "List of Students: " << endl;
  stuBST.printTree();

}
/*
optionTwo()
Print	all	faculty	and	their	information	(sorted	by	ascending	id	#)
*/
void Program::optionTwo(){
  // Print	all	faculty	and	their	information	(sorted	by	ascending	id	#)
  cout << endl;
  cout << "List of Faculty: " << endl;
  facBST.printTree();
}
/*
optionThree()
Find	and	display	student	information	given	the	students	id
*/
void Program::optionThree(){
  // Find	and	display	student	information	given	the	students	id
  int userStudID;
  cout << "Enter Student ID: " << endl;
  cin >> userStudID;
  if (!stuBST.contains(userStudID)){
    cout << "Student with given ID does not exist." << endl;
  } else {
    Student temp = stuBST.find(userStudID);
    temp.print();
  }
  return;
}
/*
optionFour()
Find	and	display	faculty	information	given	the	faculty	id
*/
void Program::optionFour(){
  // Find	and	display	faculty	information	given	the	faculty	id
  int userFactID;
  cout << "Enter Faculty ID: " << endl;
  cin >> userFactID;
  if (!facBST.contains(userFactID)){
    cout << "Faculty with given ID does not exist." << endl;
  } else {
    Faculty temp = facBST.find(userFactID);
    temp.print();
  }
  return;
}
/*
optionFive()
Given	a	student’s	id,	print	the	name	and	info	of	their	faculty	advisor
*/
void Program::optionFive(){
  // Given	a	student’s	id,	print	the	name	and	info	of	their	faculty	advisor
  int id;
  cout << "Enter Student ID: " << endl;
  cin >> id;
  if (!stuBST.contains(id)){
    cout << "Student with given ID does not exist." << endl;
  } else {
    int tempFactID;
    Student tempS = stuBST.find(id);
    tempFactID = tempS.getAdvisorID();
    if (!facBST.contains(tempFactID)){
      cout << "Faculty with given ID does not exist." << endl;
    } else {
      Faculty tempF = facBST.find(tempFactID);
      tempF.print();
    }
  }
  return;
}
/*
optionSix()
Given	a	faculty's	id,	print	the	name	and	info	of all the advisees
*/
void Program::optionSix(){
  int userFactID;
  cout << "Enter Faculty ID: " << endl;
  cin >> userFactID;
  if (!facBST.contains(userFactID)){
    cout << "Faculty with given ID does not exist." << endl;
  } else {
    Faculty temp = facBST.find(userFactID);
    for (int i = 0; i < temp.numOfStudents(); i++){
      int currID = temp.getAdviseesID(i);
      Student tempS = stuBST.find(currID);
      tempS.print();
    }
  }
  return;
}
/*
optionSeven()
Add	a	new	student
*/
void Program::optionSeven(){
  // Add	a	new	student
  int id;
  string name;
  string year;
  string major;
  double gpa;
  int adID;

  cout << "Enter ID: " << endl;
  cin >> id;
  cout << "Enter name: " << endl;
  cin >> name;
  cout << "Enter year: " << endl;
  cin >> year;
  cout << "Enter major: " << endl;
  cin >> major;
  cout << "Enter GPA: " << endl;
  cin >> gpa;
  cout << "Enter advisor's ID: " << endl;
  cin >> adID;
  if (!facBST.contains(adID)){
    cout << "Advisor does not exist. Student cannot be added." << endl;
    return;
  } else {
    Student tempStudent(id,name,year,major,gpa,adID);
    stuBST.insert(new TreeNode<Student>(tempStudent.getStudentID(),tempStudent));
    writeStudentFile(id,name,year,major,gpa,adID);
    return;
  }
}
/*
optionEight()
Remove student
*/
void Program::optionEight(){

  int id;
  cout << "Enter Student ID: " << endl;
  cin >> id;
  if (!stuBST.contains(id)){
    cout << "Student with given ID does not exist." << endl;
  } else {
    stuBST.remove(id);
  }
  return;
}
/*
optionNine()
Add	a	new	Factulty
*/
void Program::optionNine(){
  // Add	a	new	Factulty
  int id;
  string name;
  string level;
  string department;

  cout << "Enter ID: " << endl;
  cin >> id;
  cout << "Enter name: " << endl;
  cin >> name;
  cout << "Enter level: " << endl;
  cin >> level;
  cout << "Enter department: " << endl;
  cin >> department;

  Faculty tempFact(id,name,level,department);
  facBST.insert(new TreeNode<Faculty>(tempFact.getFacultyID(),tempFact));
  writeFacultyFile(id,name,level,department);
  return;
}
/*
optionTen()
Remove	Factulty member
*/
void Program::optionTen(){
  int id;
  cout << "Enter Faculty ID: " << endl;
  cin >> id;
  if (!stuBST.contains(id)){
    cout << "Faculty with given ID does not exist." << endl;
  } else {
    facBST.remove(id);
  }
  return;
}
/*
optionEleven()
Remove	Factulty member
*/
void Program::optionEleven(){
  // Change	a	student’s	advisor	given	the	student	id	and	the	new	faculty	id.
  int studID;
  int newFactID;
  cout << "Enter Student ID: " << endl;
  cin >> studID;
  if (!stuBST.contains(studID)){
    cout << "Student with given ID does not exist." << endl;
  } else {
    cout << "Enter New Advisor ID: " << endl;
    cin >> newFactID;
    if (!facBST.contains(newFactID)){
      cout << "Faculty with given ID does not exist." << endl;
    } else {
      Student temp = stuBST.find(studID);
      temp.setAdvisor(newFactID);
    }
  }
  return;
}
/*
optionTweleve()
Remove	an	advisee	from	a	faculty	member	given	the	ids
*/
void Program::optionTwelve(){
  // Remove	an	advisee	from	a	faculty	member	given	the	ids
  int userFactID;
  cout << "Enter Faculty ID: " << endl;
  cin >> userFactID;
  if (!facBST.contains(userFactID)){
    cout << "Faculty with given ID does not exist." << endl;
  } else {
    int userStudID;
    cout << "Enter Student ID to be removed: " << endl;
    cin >> userStudID;
    if (!stuBST.contains(userStudID)){
      cout << "Student with given ID does not exist." << endl;
    } else {
      Faculty temp = facBST.find(userFactID);
      for (int i = 0; i < temp.numOfStudents(); i++){
        temp.removeAdviseesID(i);
      }
    }
  }
  return;
}
/*
optionThirteen()
Rollback
*/
void Program::optionThirteen(){
  // Rollback
  return;
}
/*
optionFourteen()
Closes Program
*/
void Program::optionFourteen(){
  cout << "Goodbye" << endl;
  cout << endl;
}
/*
readStudentFile()
reads file to create student BST
*/
void Program::readStudentFile(){
  string line;
  int id;
  string name;
  string year;
  string major;
  double gpa;
  int advisor;
  ifstream stuFile;
  stuFile.open("studentTable.txt");
  if(!stuFile.is_open()){
    cout << "Error with file." << endl;
    return;
  }
  while (stuFile) {
    getline(stuFile, line);
    id = stoi(line);
    getline(stuFile, line);
    name = line;
    getline(stuFile, line);
    year = line;
    getline(stuFile, line);
    major = line;
    getline(stuFile, line);
    gpa = stoi(line);
    getline(stuFile, line);
    advisor = stoi(line);
    getline(stuFile, line);
    Student newStu(id,name,year,major,gpa,advisor);
    stuBST.insert(new TreeNode<Student>(newStu.getStudentID(),newStu));
    continue;
  }
  stuFile.close();
  //stuBST.printTree();
}
/*
readFacultyFile()
reads file to create faculty BST
*/
void Program::readFacultyFile(){
  string line;
  int numOfStuds;
  int id;
  string name;
  string level;
  string department;
  int adviseeID;
  ifstream facFile;
  facFile.open("facultyTable.txt");
  if(!facFile.is_open()){
    cout << "Error with file." << endl;
    return;
  }
  while (facFile) {
    getline(facFile, line);
    id = stoi(line);
    getline(facFile, line);
    name = line;
    getline(facFile, line);
    level = line;
    getline(facFile, line);
    department = line;
    getline(facFile, line);
    numOfStuds = stoi(line);
    Faculty newFac(id,name,level,department);
    facBST.insert(new TreeNode<Faculty>(newFac.getFacultyID(),newFac));
    for (int i = 0; i < numOfStuds; i++){
      getline(facFile, line);
      adviseeID = stoi(line);
      newFac.addAdvisees(adviseeID);
    }
    getline(facFile, line);
    continue;
  }
  facFile.close();
}
/*
writeStudentFile()
writes new students to file
@param int i, string n, string y, string m, double g, int a, the parameters of a student object
*/
void Program::writeStudentFile(int i, string n, string y, string m, double g, int a){
  ofstream newStudFile;
  newStudFile.open("studentTable.txt",ios_base::app);
  newStudFile << endl;
  newStudFile << i << endl;
  newStudFile << n << endl;
  newStudFile << y << endl;
  newStudFile << m << endl;
  newStudFile << g << endl;
  newStudFile << a << endl;
  newStudFile << endl;
  newStudFile.close();
}
/*
writeFacultyFile()
writes new faculty to file
@param int i, string a, string b, string c, the parameters of a faculty object
*/
void Program::writeFacultyFile(int i, string a, string b, string c){
  ofstream newFacFile;
  newFacFile.open("facultyTable.txt",ios_base::app);
  newFacFile << i << endl;
  newFacFile << a << endl;
  newFacFile << b << endl;
  newFacFile << c << endl;
  newFacFile << endl;
  newFacFile.close();
}
