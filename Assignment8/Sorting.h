/*
@file Sorting.h
@brief header file for Sorting class
@author Lauren Szlosek
*/
#include <fstream>
#include <vector>
using namespace std;

class Sorting{
public:
  ifstream userFileName;
  int sortSize;
  vector<double> sortList;
public:
  Sorting();
  ~Sorting();
private:
  void mergeSort(vector<double>& v, int s, int e);
  void selectionSort();
  void shellSort();
  void merge(vector<double>& v, int s, int m, int e);
};
