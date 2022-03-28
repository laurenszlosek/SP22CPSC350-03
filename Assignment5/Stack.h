/*
@file Stack.h
@brief Stack template
*/
template <typename E>
class Stack{
public:
  Stack() {} // Default constructor
  virtual ~Stack() {} // Base destructor

  // insert element to stack
  // @param item: element to be inserted
  virtual void push(E item) = 0;

  // remove item from stack
  virtual E pop() = 0;

  // return top element on stack
  // @return top element
  virtual E topElement() = 0;

  // check if stack is empty
  // @return true if empty
  virtual bool isEmpty() = 0;

  // check if stack is full
  // @return true if full
  virtual bool isFull() = 0;

  // returns length
  // @return number of items in stack
  virtual int length() = 0;

};
