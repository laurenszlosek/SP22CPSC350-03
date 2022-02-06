/*
@file prices.cpp
@brief C++ program to print 3 ages from oldest to youngest
@author Lauren Szlosek
*/
#include <iostream>

int main(){
  int ageOne, ageTwo, ageThree;

  std::cout << "Enter the ages of three people, seperated by spaces: " << std::endl;
  std::cin >> ageOne >> ageTwo >> ageThree;

  if ((ageOne > ageTwo) && (ageOne > ageThree)){
    if (ageTwo > ageThree){
      std::cout << ageOne << " " << ageTwo << " " << ageThree << " " << std::endl;
    }else{
      std::cout << ageOne << " " << ageThree << " " << ageTwo << " " << std::endl;
    }
  } else if ((ageTwo > ageOne) && (ageTwo > ageThree)){
    if (ageThree > ageOne){
      std::cout << ageTwo << " " << ageThree << " " << ageOne << " " << std::endl;
    }else{
      std::cout << ageTwo << " " << ageOne << " " << ageThree << " " << std::endl;
    }
  } else if ((ageThree > ageOne) && (ageThree > ageTwo)){
    if (ageOne > ageTwo){
      std::cout << ageThree << " " << ageOne << " " << ageTwo << " " << std::endl;
    }else{
      std::cout << ageThree << " " << ageTwo << " " << ageOne << " " << std::endl;
    }
  }


  return 0;
}
