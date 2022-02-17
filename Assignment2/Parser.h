/*
@file Parser.h
@brief header file for Parser class
@author Lauren Szlosek
*/
#ifndef PARSER_H
#define PARSER_H
class Parser
{
private:
  std::string userString;
  int countA = 0;
  int countB = 0;
  int countC = 0;
  int countD = 0;
  int countE = 0;
  int countF = 0;
  int countG = 0;
  int countH = 0;
  int countI = 0;
  int countJ = 0;
  int countK = 0;
  int countL = 0;
  int countM = 0;
  int countN = 0;
  int countO = 0;
  int countP = 0;
  int countQ = 0;
  int countR = 0;
  int countS = 0;
  int countT = 0;
  int countU = 0;
  int countV = 0;
  int countW = 0;
  int countX = 0;
  int countY = 0;
  int countZ = 0;
  int countElse = 0;
  int countTotal = 0;
  int countPairs = 0;

  void findPairs();
public:
  Parser();
  void sortString(std::string);
  void saveToFile();
};
#endif
