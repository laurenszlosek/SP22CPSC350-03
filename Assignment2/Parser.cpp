/*
@file Parser.cpp
@brief Parser class to sort user's string and output to a file
@author Lauren Szlosek
*/
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include "Parser.h"
/*
Parser
Constructor
*/
Parser::Parser(){}
/*
sortString()
Counts the amount of each letter in user's string
@param string s, user's imput
*/
void Parser::sortString(std::string s){
  userString = s;
  for (int i = 0; i < s.length(); i++){
    char c = s[i];
    //tolower(c);
    //std::cout << "lower: " << c << std::endl;
    if (tolower(c) == 'a'){
      countA += 1;
      countTotal += 1;
      //std::cout << "CountA: " << countA << std::endl;
    }
    else if (tolower(c) == 'b'){
      countB += 1;
      countTotal += 1;
      //std::cout << "CountB: " << countB << std::endl;
    }
    else if (tolower(c) == 'c'){
      countC += 1;
      countTotal += 1;
      //std::cout << "CountC: " << countC << std::endl;
    }
    else if (tolower(c) == 'd'){
      countD += 1;
      countTotal += 1;
      //std::cout << "CountD: " << countD << std::endl;
    }
    else if (tolower(c) == 'e'){
      countE += 1;
      countTotal += 1;
      //std::cout << "CountE: " << countE << std::endl;
    }
    else if (tolower(c) == 'f'){
      countF += 1;
      countTotal += 1;
      //std::cout << "CountF: " << countF << std::endl;
    }
    else if (tolower(c) == 'g'){
      countG += 1;
      countTotal += 1;
      //std::cout << "CountG: " << countG << std::endl;
    }
    else if (tolower(c) == 'h'){
      countH += 1;
      countTotal += 1;
      //std::cout << "CountH: " << countH << std::endl;
    }
    else if (tolower(c) == 'i'){
      countI += 1;
      countTotal += 1;
      //std::cout << "CountI: " << countI << std::endl;
    }
    else if (tolower(c) == 'j'){
      countJ += 1;
      countTotal += 1;
      //std::cout << "CountJ: " << countJ << std::endl;
    }
    else if (tolower(c) == 'k'){
      countK += 1;
      countTotal += 1;
      //std::cout << "CountK: " << countK << std::endl;
    }
    else if (tolower(c) == 'l'){
      countL += 1;
      countTotal += 1;
      //std::cout << "CountL: " << countL << std::endl;
    }
    else if (tolower(c) == 'm'){
      countM += 1;
      countTotal += 1;
      //std::cout << "CountM: " << countM << std::endl;
    }
    else if (tolower(c) == 'n'){
      countN += 1;
      countTotal += 1;
      //std::cout << "CountN: " << countN << std::endl;
    }
    else if (tolower(c) == 'o'){
      countO += 1;
      countTotal += 1;
      //std::cout << "CountO: " << countO << std::endl;
    }
    else if (tolower(c) == 'p'){
      countP += 1;
      countTotal += 1;
      //std::cout << "CountP: " << countP << std::endl;
    }
    else if (tolower(c) == 'q'){
      countQ += 1;
      countTotal += 1;
      //std::cout << "CountQ: " << countQ << std::endl;
    }
    else if (tolower(c) == 'r'){
      countR += 1;
      countTotal += 1;
      //std::cout << "CountR: " << countR << std::endl;
    }
    else if (tolower(c) == 's'){
      countS += 1;
      countTotal += 1;
      //std::cout << "CountS: " << countS << std::endl;
    }
    else if (tolower(c) == 't'){
      countT += 1;
      countTotal += 1;
      //std::cout << "CountT: " << countT << std::endl;
    }
    else if (tolower(c) == 'u'){
      countU += 1;
      countTotal += 1;
      //std::cout << "CountU: " << countU << std::endl;
    }
    else if (tolower(c) == 'v'){
      countV += 1;
      countTotal += 1;
      //std::cout << "CountV: " << countV << std::endl;
    }
    else if (tolower(c) == 'w'){
      countW += 1;
      countTotal += 1;
      //std::cout << "CountW: " << countW << std::endl;
    }
    else if (tolower(c) == 'x'){
      countX += 1;
      countTotal += 1;
      //std::cout << "CountX: " << countX << std::endl;
    }
    else if (tolower(c) == 'y'){
      countY += 1;
      countTotal += 1;
      //std::cout << "CountY: " << countY << std::endl;
    }
    else if (tolower(c) == 'z'){
      countZ += 1;
      countTotal += 1;
      //std::cout << "CountZ: " << countZ << std::endl;
    }else{
      countElse += 1;
      //std::cout << "CountElse: " << countElse << std::endl;
    }
  }
  return;
}
/*
findPairs()
finds duplicate letters in a row
=*/
void Parser::findPairs(){
  for (int i = 0; i < userString.length(); i++){
    if (userString[i] == userString[i+1]){
      countPairs += 1;
    }
  }
}
/*
saveToFile()
prints content into output file
*/
void Parser::saveToFile(){
  std::ofstream file;
  file.open("output.txt");
  if (!file.is_open()){
    std::cout << "Error." << std::endl;
  }
  file << "a:" << countA << std::endl;
  file << "b:" << countB << std::endl;
  file << "c:" << countC << std::endl;
  file << "d:" << countD << std::endl;
  file << "e:" << countE << std::endl;
  file << "f:" << countF << std::endl;
  file << "g:" << countG << std::endl;
  file << "h:" << countH << std::endl;
  file << "i:" << countI << std::endl;
  file << "j:" << countJ << std::endl;
  file << "k:" << countK << std::endl;
  file << "l:" << countL << std::endl;
  file << "m:" << countM << std::endl;
  file << "n:" << countN << std::endl;
  file << "o:" << countO << std::endl;
  file << "p:" << countP << std::endl;
  file << "q:" << countQ << std::endl;
  file << "r:" << countR << std::endl;
  file << "s:" << countS << std::endl;
  file << "t:" << countT << std::endl;
  file << "u:" << countU << std::endl;
  file << "v:" << countV << std::endl;
  file << "w:" << countW << std::endl;
  file << "x:" << countX << std::endl;
  file << "y:" << countY << std::endl;
  file << "z:" << countZ << std::endl;
  file << "alphabets:" << countTotal << std::endl;
  file << "non-alphabets:" << countElse << std::endl;
  file << "average:" << (double)countTotal/26 << std::endl;
  findPairs();
  file << "pairs:" << countPairs;
  file.close();
  return;

}
