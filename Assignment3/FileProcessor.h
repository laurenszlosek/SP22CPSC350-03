/*
@file FileProcessor.h
@brief header file for FileProcessor class
@author Lauren Szlosek
*/
#include <string>
using namespace std;

class FileProcessor{
public:

  FileProcessor();

  ~FileProcessor();
  
  void processFile(string inputfile, string outputfile);
};
