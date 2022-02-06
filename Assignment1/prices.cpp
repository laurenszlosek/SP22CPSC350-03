/*
@file prices.cpp
@brief C++ program to add user imput prices
@author Lauren Szlosek
*/
#include <iostream>
#include <string>

int main(){
  float uPrice;
  float total;

  while (uPrice >= 0){
    std::cout << "Enter price: " << std::endl;
    std::cin >> uPrice;
    if (uPrice < 0){
      break;
    }
    total += uPrice;
  }

  std::cout << "Total: $" << total << std::endl;
  return 0;
}
