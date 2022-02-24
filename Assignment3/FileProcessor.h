/*
@file FileProcessor.h
@brief header file for FileProcessor class
@author Lauren Szlosek
*/
#include <string>
using namespace std;

class FileProcessor{
public:
  /*
  FileProcessor()
  constructor
  */
  FileProcessor();
  /*
  ~FileProcessor()
  destructor
  */
  ~FileProcessor();
  /*
  processFile()
  Reads content from input file, translates the content into Tutnese, writes translatiion into output file
  @param string inputfile, string outputfile, the input and output file names
  */
  void processFile(string inputfile, string outputfile);
};
