#include "FileProcessor.h"
#include "Translator.h"  // Since I create an object of the Translator class, I have to include the Translator header file here
#include <fstream>
#include <iostream>
using namespace std;

FileProcessor::FileProcessor(){}

FileProcessor::~FileProcessor(){}

void FileProcessor::processFile(string inputName, string outputName){
  string line;
  ifstream inputFile;
  ofstream outputFile;
  Translator converter;

  inputFile.open(inputName);
  outputFile.open(outputName);

  if (!inputFile.is_open()){
    std::cout << "Error with Input File Name." << std::endl;
  }

  if (!inputFile.is_open()){
    std::cout << "Error with Output File Name." << std::endl;
  }

  if (inputFile && outputFile){ //https://www.programmingwithbasics.com/2016/03/write-c-program-for-copy-one-file-to.html
    while (getline(inputFile,line)){
      //cout << "a" << endl;
      line = converter.translateEnglishSentence(line);
      //cout << "b" << endl;
      outputFile << line << endl;
      //cout << "c" << endl;
    }
  }

  inputFile.close();
  outputFile.close();

  return;
}
