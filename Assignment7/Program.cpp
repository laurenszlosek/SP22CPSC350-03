/*
@file Program.cpp
@brief Program class
@author Lauren Szlosek
*/
#include "Program.h"
#include "BST.h" // bye
#include "Student.h" // bye
#include "Faculty.h" // bye
#include <iostream>

using namespace std;
/*
Program()
Constructor
*/
Program::Program(){
  startProgram();
}
/*
~Program()
Program
*/
Program::~Program(){}

void Program::startProgram(){
  // set up Tables
  BST<Student> stuBST;
  Student student1(20,"lauren","2001","SE",4.5,3);
  Student student2(20,"lauren","2001","SE",4.5,1);
  Student student3(20,"lauren","2001","SE",4.5,10);
  stuBST.insert(new TreeNode<Student>(student1.getStudentID(),student1));
  stuBST.insert(new TreeNode<Student>(student2.getStudentID(),student2));
  stuBST.insert(new TreeNode<Student>(student3.getStudentID(),student3));
  stuBST.printTree();

  BST<Faculty> facBST;
  Faculty fact1(12,"hi","bye", "no");
  Faculty fact2(12,"hi","bye", "no");
  Faculty fact3(12,"hi","bye", "no");
  facBST.insert(new TreeNode<Faculty>(fact1.getFacultyID(),fact1));
  facBST.insert(new TreeNode<Faculty>(fact2.getFacultyID(),fact2));
  facBST.insert(new TreeNode<Faculty>(fact3.getFacultyID(),fact3));
  facBST.printTree();

// 1. Print	all	students	and	their	information	(sorted	by	ascending	id	#)
// 2. Print	all	faculty	and	their	information	(sorted	by	ascending	id	#)
// 3. Find	and	display	student	information	given	the	students	id
// 4. Find	and	display	faculty	information	given	the	faculty	id
// 5. Given	a	student’s	id,	print	the	name	and	info	of	their	faculty	advisor
// 6. Given	a	faculty	id,	print	ALL	the	names	and	info	of	his/her	advisees.
// 7. Add	a	new	student
// 8. Delete	a	student	given	the	id
// 9. Add	a	new	faculty	member
// 10. Delete	a	faculty	member	given	the	id.
// 11. Change	a	student’s	advisor	given	the	student	id	and	the	new	faculty	id.
// 12. Remove	an	advisee	from	a	faculty	member	given	the	ids
// 13. Rollback
// 14. Exit
}
