// stack abstract class

template <typename E>
class Stack{
public:
  Stack() {} // default constructor
  virtual ~Stack() {} // base constructor

  // reinitializes stack
  virtual void clear() =0;

  // push an element onto the top of the stack
  // @param item: element being pushed
  virtual void push(const E& item) = 0;

  // remove elemnt from top of stack
  virtual E pop() = 0;

  // return a copy of the top element
  virtual E topValue = 0;

  // return the number of elements in the stack
  virtual int length() = 0;
};
