# 2/8/22
## pointers
###### the & (reference) operator can be used the memory address of a variable
###### cout << x << endl; <- prints: x
###### cout << &x << endl; <- prints: 12421423 aka memory address
###### * (pointer (type*) / dereference (*variable)) can store memory address as its actual value
###### int* ptr = &x; <- prints: 12421423 aka memory address
###### *ptr = 25;
###### const char* work =  "hello"
###### pointer to a pointer - prints the value associated with the value associated with the address stored in z
## arrays
###### series of elements of the same data type
###### can be individually referenced using indexes
###### fixed size
######
###### dynamic array
###### int* array;
###### int size = 5;
###### array = new int[size];
###### delete[] array;
######
###### free up memory once the array is done
###### [2, 6, 7, 7, 4]
######
# 2/15/22
## algorithm analysis
###### data structures optimize data storage and organization
###### time complexity ~ T(n)
###### function describes the amount of time an algorithm takes
###### not real world time
###### T(n) = 2n+1
###### space complexity ~ S(n)
###### amount of memory an algorithm uses
###### S(n) = 2+n
######
###### T(n) ~ sort alg
###### T(n) - the sum of the time for min_idx + time for swap
###### - the sum of the time for min_idx + 4 (bc time of swap is 4)
###### - the sum of (2 (n - i - 1) + 4)
###### - 2n(n-1) + 2(n-1) - 2(sum)
###### - 2n(n-1) + 2(n-1) - 2(n-2)(n-1)/2
###### - 2n(n-1) + 2(n-1) - (n-2)(n-1)
###### - 2n^2 + 2n - n^2
###### - n^2 + 2n +3
###### Ts(n) ^
###### Tm(n) = 8nlog(n)
######
# 2/17/22
###### algo 1 - input -> num(int)((1))
######        - return num*2((2))
###### T(n) - 2
######
###### algo 2 - input -> nums(array)
######        - mx = 0((1))
######        - for i((1)) in nums
######        -   if i > mx((1))
######        -     mx = 0((1))
######        - return mx((1))
######        -
###### T(n) - 3n+2 <- worst case
###### T(n) - 2n+2 <- best case
###### T(n) - (3+2/2)n+2 <- average case
# 2/22/22
######
## Big O ~ the upper bound of growth rate
###### T(n) is in O(f(n)) is there exists two positive constants c and n-sub-0 such that,
###### T(n) <= cf(n) for all n >= n-sub-0
######
###### average of the algorithm working in any case (k has an equal distribution in every spot)
######
###### T(n) = n/2
###### n/2 <= c*n
###### 1/2 <= c & n-sub-0 = 1
###### ^for the average case
######
###### T(n) = 3n^2 + 5, best case
###### Is T(n) is O(n)?
###### 3n^2 + 5 <= c*n for all n>=n-sub-0
###### 3n <= c
###### ~not in big O~
######
###### lower bound or the smallest growth rate / big omega
###### T(n) >= cg(n) for all n >= n-sub-nod
###### how good things can be
######
###### BIG THETAAAA
###### c-sub-1 * h(n) ≤ T(n) ≤ c-sub-2 * h(n) for all n ≥ n-sub-0
######
## Linked Lists
######
###### template <typename E>
###### class List{
######  public:
######  
######  List() {} //constructor
######  virtual ~List() {} //base destructor
######  //clear list
######  virtual void clear() = 0;
######
######  // insert element at current location
######  // @param item: element to be inserted
######  virtual void insert(E item) = 0;
######  
######  
######
######
######
######
######
###### };
######
######
######
######
######
######
######
