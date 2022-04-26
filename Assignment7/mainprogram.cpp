#include "BST.h" // bye
#include "Student.h" // bye
#include "Faculty.h" // bye
#include <iostream>
using namespace std;

int main(){
  //creating BST object and running some functions
  BST<int> myBST;
  myBST.insert(new TreeNode<int>(2,2));
  myBST.insert(new TreeNode<int>(1,1));
  myBST.insert(new TreeNode<int>(10,10));
  myBST.insert(new TreeNode<int>(5,5));
  myBST.printTree();
  myBST.remove(5);
  myBST.printTree();
  myBST.remove(1);
  myBST.printTree();
  myBST.remove(2);
  myBST.printTree();
  cout << myBST.contains(10) << endl;
  myBST.remove(10);
  myBST.printTree();
  cout << myBST.contains(10) << endl;

  BST<Student> stuBST;
  Student student1(20,"lauren","2001","SE",4.5,3);
  Student student2(20,"lauren","2001","SE",4.5,1);
  Student student3(20,"lauren","2001","SE",4.5,10);
  stuBST.insert(new TreeNode<Student>(student1.getNum(),student1));
  stuBST.insert(new TreeNode<Student>(student2.getNum(),student2));
  stuBST.insert(new TreeNode<Student>(student3.getNum(),student3));
  stuBST.printTree();

  // Student student1(20,"lauren","2001","SE",4.5,0);
  // Student student2(69,"harry","1997","hot",2.3,100);
  // student1.print();
  // student2.print();
  // if (student1 > student2) {
  //   cout << "lauren is greater than harry" << endl;
  // }
  // Faculty fact1(12,"hi","bye", "no");
  // Faculty fact2(13,"hi2","bye2", "no2");
  // fact1.print();
  // fact2.print();

}
