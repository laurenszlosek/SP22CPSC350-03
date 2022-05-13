/*
@file Sorting.cpp
@brief Sorting class
@author Lauren Szlosek
*/
#include <iostream>
#include <algorithm>
#include <chrono>
#include "Sorting.h"
using namespace std;
using namespace std::chrono;

/*
Sorting()
Constructor
*/
Sorting::Sorting(){
  string fileName;
  time_t ctt = time(0);
  cout << "Enter File Name: " << endl;
  cin >> fileName;
  userFileName.open(fileName);
  if (!userFileName.is_open()){
    std::cout << "Error with Input File Name." << std::endl;
  }
  string lineOne;
  getline(userFileName,lineOne);
  sortSize = stoi(lineOne);

  string lineNext;
  int num;
  for (int i = 0; i < sortSize; i++){
    getline(userFileName,lineNext);
    num = stoi(lineNext);
    sortList.push_back(num);
  }
  auto start1 = high_resolution_clock::now();
  mergeSort(sortList, 0, sortSize - 1);
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
  cout << "Time taken by merge sort: " << duration1.count() << " microseconds" << endl;
  cout << endl;
  auto start2 = high_resolution_clock::now();
  selectionSort();
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2 - start2);
  cout << "Time taken by selection sort: " << duration2.count() << " microseconds" << endl;
  cout << endl;
  auto start3 = high_resolution_clock::now();
  shellSort();
  auto stop3 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(stop3 - start3);
  cout << "Time taken by shell sort: " << duration3.count() << " microseconds" << endl;
}
/*
~Sorting()
Sorting
*/
Sorting::~Sorting(){}
/*
mergeSort()
sorts vector through a merge sorting algorithm
@param vector<double>& v, int s, int e, numbers being sorted, starting size, and vector size
*/
void Sorting::mergeSort(vector<double>& numbers, int i, int j){
  if (i < j) {
		int k = (i + j) / 2;
		mergeSort(numbers, i, k);
		mergeSort(numbers, k + 1, j);
		merge(numbers, i, k, j);
	}
}
/*
merge()
combines the two sorted vectors
@param vector<double>& v, int s, int m, int e, numbers being sorted, starting size, half of the total size, and vector size
*/
void Sorting::merge(vector<double>& v, int s, int m, int e){ 
  vector<double> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}
/*
selectionSort()
sorts vector through a selection sorting algorithm
*/
void Sorting::selectionSort(){
  //cout << "selection" << endl;
  int i = 0;
  int j = 0;
  int indexSmall = 0;
  int temp = 0;

  for (int i = 0; i < sortSize - 1; i++){
    indexSmall = i;
    for (j = i +1; j < sortSize; j++){
      if (sortList.at(j) < sortList.at(indexSmall)){
        indexSmall = j;
      }
    }
    temp = sortList.at(i);
    sortList.at(i) = sortList.at(indexSmall);
    sortList.at(indexSmall) = temp;
  }
}
/*
selectionSort()
sorts vector through a shell sorting algorithm
*/
void Sorting::shellSort(){ // https://big-o.io/examples/shellsort/c++/
  for (int i = sortSize/2; i > 0; i /=2){
    for (int curr = i; curr < sortSize; curr++){
      int currIn = curr;
      int item = sortList[curr];

      while (currIn >= i && sortList[currIn - i] > item){
        sortList[currIn] = sortList[currIn - i];
        currIn -= i;
      }
      sortList[currIn] = item;
    }
  }
}
