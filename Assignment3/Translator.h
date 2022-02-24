/*
@file Translator.h
@brief header file for Translator class
@author Lauren Szlosek
*/
using namespace std;
#include <string>

class Translator{
public:
  // implement constructor and destructor
  /*
  Translator()
  constructor
  */
  Translator();
  /*
  ~Translator()
  destructor
  */
  ~Translator();
  /*
  translateEnglishWord()
  iterates over word to translate into Tutnese
  @param string s, word being translated
  @return string,  translated word
  */
  string translateEnglishWord(string word);
  /*
  translateEnglishSentence()
  iterates over sentence to translate into Tutnese
  @param string s, sentence being translated
  @return string,  translated sentence
  */
  string translateEnglishSentence(string sent);
};
