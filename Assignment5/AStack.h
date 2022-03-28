/*
@file AStack.h
@brief Stacks made from Arrays
@author Lauren Szlosek
*/
#include "Stack.h"
#include <stdexcept>
#include <iostream>

template <typename E>
class AStack : public Stack<E> {
private:
  int arraySize; // size of the array
  int top; // top element
  E* arrayStack; // Array holding list elements
public:
  AStack(int size);
  ~AStack();

  // insert element to stack
  // @param item: element to be inserted
  void push(E item);

  // remove item from stack
  E pop();

  // return top element on stack
  // @return top element
  E topElement();

  // check if stack is empty
  // @return true if empty
  bool isEmpty();

  // check if stack is full
  // @return true if full
  bool isFull();

  // returns length
  // @return number of items in stack
  int length();

};
/*
AStack()
Destructor
*/
template <typename E>
AStack<E>::~AStack(){
  delete[] arrayStack;
}
/*
AStack()
Constructor
*/
template <typename E>
AStack<E>::AStack(int size){
  arraySize = size;
  arrayStack = new E[arraySize];
  top = -1;
}
/*
push()
insert element to stack
@param item: element to be inserted
*/
template <typename E>
void AStack<E>::push(E item){
  if (isFull()){
    return;
  }
  arrayStack[++top] = item;
}
/*
pop()
remove item from stack
@param E: item being removed
*/
template <typename E>
E AStack<E>::pop(){
  if (!isEmpty()){
    return arrayStack[top--];
  }
}
/*
topElement()
return top element on stack
@return top element
*/
template <typename E>
E AStack<E>::topElement(){
  if (!isEmpty()){
    return arrayStack[top];
  }
}
/*
isEmpty()
checks to see if array is empty
@return bool
*/
template <typename E>
bool AStack<E>::isEmpty(){
  try {
    if (top == -1){
      throw std::invalid_argument("Stack is Empty");
      return true;
    } else {
      return false;
    }
  }
  catch (std::invalid_argument & excpt) {
    std::cout << "Exception: " << excpt.what() << std::endl;
  }
  return (top == -1);
}
/*
isFull()
checks to see if array is at max size
@return bool
*/
template <typename E>
bool AStack<E>::isFull(){
  if (top == arraySize){
    arraySize++;
    return true;
  } else {
    return false;
  }
  return (top == arraySize -1);
}
/*
length()
size of current stack
@return size
*/
template <typename E>
int AStack<E>::length(){
  return top + 1;
}
