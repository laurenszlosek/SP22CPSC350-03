#include "DLList.h"

template <typename E>
class Queue{
private:
  DLList<char> myQueue;
  // int arraySize; // size of the array
  // int top; // top element
  // E* arrayStack; // Array holding list elements
public:
  Queue();
  ~Queue();

  // insert element to stack
  // @param item: element to be inserted
  void enqueue(E item);

  // remove item from stack
  E dequeue();

  // return top element on stack
  // @return top element
  E showFirst();

  // check if stack is empty
  // @return true if empty
  E showLast();

  //void showList();
};

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
Queue<E>::Queue(){
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
Queue<E>::~Queue(){
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
void Queue<E>::enqueue(E item){
  myQueue.insertBack(item);
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
E Queue<E>::dequeue(){
  myQueue.removeFront();
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
E Queue<E>::showFirst(){
  myQueue.peekFront();
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
template <typename E>
E Queue<E>::showLast(){
  myQueue.peekBack();
}

/*
removeFront
Function removes a list node from the front of the list.
@return: item value at front.
*/
// template <typename E>
// E Queue<E>::showList(){
//   while (!myQueue.isEmpty()){
//     cout <<
//   }
// }
