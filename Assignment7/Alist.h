#include "List.h"

template <typename E>
class Alist : public List<E> {
private:
  int maxSize; // Max size of the list
  int listSize; // number of elements in list right now
  int curr; // Position of current element
  E* listArray; // Array holding list elements
public:
  Alist(int size);
  ~Alist();

  void clear();

  // insert element at current location
  // @param item: element to be inserted
  void insert(E item);

  // append element at the end of the list
  // @param item: element to be inserted
  void append(E item);

  // remove and return the current element
  // @return the element that was removed
  E remove();

  // set the current position to the start of the list
  void moveToStart();

  // set the current position to the end of the list
  void moveToEnd();

  // move the current position one step to the left. No change if at beginning
  void prev();

  // move the current position one step to the right. No change if at end
  void next();

  // return the number of elements in the list
  int length();

  // return the position of the current element
  int currPos();

  // set current position
  // @param pos: the position to make current
  void moveToPos(int pos);

  // return the current element
  E getValue();

};

template <typename E>
Alist<E>::~Alist(){
  delete[] listArray;
} // Destructor

template <typename E>
Alist<E>::Alist(int size){
  maxSize = size;
  listSize = curr = 0;
  listArray = new E[maxSize];
} // Constructor


template <typename E>
void Alist<E>::clear(){
  delete[] listArray;
  listSize = curr = 0;
  listArray = new E[maxSize];
}

// insert element at current location
// @param item: element to be inserted
template <typename E>
void Alist<E>::insert(E item){
  //Assert(listSize < maxSize, "List capacity exceeded!");
  if(listSize > maxSize)
    return;
  for(int i=listSize;i>curr;i--){
    listArray[i] = listArray[i-1]; // shift elements up to make room
  }
  listArray[curr] = item;
  listSize++;
}

// append element at the end of the list
// @param item: element to be inserted
template <typename E>
void Alist<E>::append(E item){
  //Assert(listSize<maxSize,"List capacity exceeded!");
  listArray[listSize++] = item;
}

// remove and return the current element
// @return the element that was removed
template <typename E>
E Alist<E>::remove(){
  //Assert((curr>=0) && (curr < listSize), "No element!");
  E item = listArray[curr];
  for(int i=curr;i<listSize-1;i++){
    listArray[i] = listArray[i+1]; // shift elements back
  }
  listSize--;
  return item;
}

// set the current position to the start of the list
template <typename E>
void Alist<E>::moveToStart(){
  curr = 0;
}

// set the current position to the end of the list
template <typename E>
void Alist<E>::moveToEnd(){
  curr = listSize;
}

// move the current position one step to the left. No change if at beginning
template <typename E>
void Alist<E>::prev(){
  if(curr!=0)
    curr--;
}

// move the current position one step to the right. No change if at end
template <typename E>
void Alist<E>::next(){
  if(curr<listSize)
    curr++;
}

// return the number of elements in the list
template <typename E>
int Alist<E>::length(){
  return listSize;
}

// return the position of the current element
template <typename E>
int Alist<E>::currPos(){
  return curr;
}

// set current position
// @param pos: the position to make current
template <typename E>
void Alist<E>::moveToPos(int pos){
  //Assert((curr>=0) && (curr<=listSize),"Position out of bounds!");
  curr = pos;
}

// return the current element
template <typename E>
E Alist<E>::getValue(){
  //Assert ((curr>=0) && (curr<listSize) , "No current element!");
  return listArray[curr];
}
