/*
@file Translator.cpp
@brief Translator class to translate words and sentences
@author Lauren Szlosek
*/
#include "Translator.h"
#include "Model.h" // Since I create an object of the Model class, I have to include the Model header file here
#include <iostream>
/*
Translator()
constructor
*/
Translator::Translator(){}
/*
~Translator()
destructor
*//*
translateEnglishWord()
iterates over word to translate into Tutnese
@param string s, word being translated
@return string,  translated word
*/
Translator::~Translator(){}
/*
translateEnglishWord()
iterates over word to translate into Tutnese
@param string s, word being translated
@return string,  translated word
*/
string Translator::translateEnglishWord(string word){
  // here check each letter of word
  string transWord = "";
  Model model; // this is object of Model class to use translate functions
  // either call model's translateStringCharacter or translateDoubleCharacter function
   for (int i = 0; i <= word.length(); i++){
      //cout << word[i] << endl;
     // cout << word << endl;
    if (word[i] == word[i+1]){
      transWord += model.translateDoubleCharacter(word[i]);
      i++;
    } else {
      transWord += model.translateStringCharacter(word[i]);
    }
  }
  return transWord;
}
/*
translateEnglishSentence()
iterates over sentence to translate into Tutnese
@param string s, sentence being translated
@return string,  translated sentence
*/
string Translator::translateEnglishSentence(string sent){
  string word = "";
  string punct = "";
  string fullSentence = "";
  for (int i = 0; i <= sent.length(); i++){
    if ((sent[i] == ' ') || (sent[i] =='.') || (sent[i] =='?') || (sent[i] ==',') || (sent[i] ==';') ||(sent[i] =='"') || (sent[i] =='\n') || (sent[i] =='!') || (i == sent.length())){
      punct = sent[i];
      fullSentence += translateEnglishWord(word);
      fullSentence += sent[i];
      word = "";
    }
    else {
      word += sent[i];
    }
  }
  return fullSentence;
}
