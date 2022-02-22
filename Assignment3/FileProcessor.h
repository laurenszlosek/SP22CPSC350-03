/*
@file FileProcessor.h
@brief header file for FileProcessor class
@author Lauren Szlosek
*/
#include <string>
using namespace std;

class FileProcessor{
public:
  // implement constructor and destructor
  FileProcessor();
  ~FileProcessor();
  void processFile(string inputfile, string outputfile);
};
