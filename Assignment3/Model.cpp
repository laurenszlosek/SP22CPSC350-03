/*
@file Model.cpp
@brief Model class to translate each character
@author Lauren Szlosek
*/
#include "Model.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>

using namespace std;
/*
Model()
constructor
*/
Model::Model(){}
/*
~Model()
destructor
*/
Model::~Model(){}
/*
translateStringCharacter()
translate single character into Tutnese
@param character c, letter being translated
@return string, translated letter
*/
string Model::translateStringCharacter(char c){
  string transChar;
  bool isCaptalized = false;
  if (isupper(c)){
    //cout << "Captalized: " << c << endl;
    isCaptalized = true;
  }
  if (tolower(c) == 'a'){
    transChar =  "a";
  }
  if (tolower(c) == 'b'){
    transChar =  "bub";
  }
  if (tolower(c) == 'c'){
    transChar =  "cash";
  }
  if (tolower(c) == 'd'){
    transChar =  "dud";
  }
  if (tolower(c) == 'e'){
    transChar =  "e";
  }
  if (tolower(c) == 'f'){
    transChar =  "fuf";
  }
  if (tolower(c) == 'g'){
    transChar =  "gug";
  }
  if (tolower(c) == 'h'){
    transChar =  "hash";
  }
  if (tolower(c) == 'i'){
    transChar =  "i";
  }
  if (tolower(c) == 'j'){
    transChar =  "jay";
  }
  if (tolower(c) == 'k'){
    transChar =  "kuck";
  }
  if (tolower(c) == 'l'){
    transChar =  "lul";
  }
  if (tolower(c) == 'm'){
    transChar =  "mum";
  }
  if (tolower(c) == 'n'){
    transChar =  "nun";
  }
  if (tolower(c) == 'o'){
    transChar =  "o";
  }
  if (tolower(c) == 'p'){
    transChar =  "pub";
  }
  if (tolower(c) == 'q'){
    transChar =  "quack";
  }
  if (tolower(c) == 'r'){
    transChar =  "rug";
  }
  if (tolower(c) == 's'){
    transChar =  "sus";
  }
  if (tolower(c) == 't'){
    transChar =  "tut";
  }
  if (tolower(c) == 'u'){
    transChar =  "u";
  }
  if (tolower(c) == 'v'){
    transChar =  "vuv";
  }
  if (tolower(c) == 'w'){
    transChar =  "wack";
  }
  if (tolower(c) == 'x'){
    transChar =  "ex";
  }
  if (tolower(c) == 'y'){
    transChar =  "yub";
  }
  if (tolower(c) == 'z'){
    transChar =  "zub";
  }
  //xscout << "is? " << isCaptalized << endl;
  if (isCaptalized){
    //cout << "before: "<< transChar[0] << endl;
    transChar[0] = toupper(transChar[0]);
    //cout << "after: "<< transChar[0] << endl;
  }
  return transChar;
}
/*
translateDoubleCharacter()
translate repeated character into Tutnese
@param character c, letter being translated
@return string, translated letter
*/
string Model::translateDoubleCharacter(char c){
  string transChar;
  bool isCaptalized = false;
  if (isupper(c)){
    //cout << "Captalized: " << c << endl;
    isCaptalized = true;
  }
  if (tolower(c)== 'a'){
    transChar =  "squata";
  }
  if (tolower(c)== 'b'){
    transChar =  "squabub";
  }
  if (tolower(c)== 'c'){
    transChar =  "squacash";
  }
  if (tolower(c)== 'd'){
    transChar =  "squadud";
  }
  if (tolower(c)== 'e'){
    transChar =  "squate";
  }
  if (tolower(c)== 'f'){
    transChar =  "squafuf";
  }
  if (tolower(c)== 'g'){
    transChar =  "squagug";
  }
  if (tolower(c)== 'h'){
    transChar =  "squahash";
  }
  if (tolower(c)== 'i'){
    transChar =  "squasquati";
  }
  if (tolower(c)== 'j'){
    transChar =  "squajay";
  }
  if (tolower(c)== 'k'){
    transChar =  "squakuck";
  }
  if (tolower(c)== 'l'){
    transChar =  "squalul";
  }
  if (tolower(c)== 'm'){
    transChar =  "squamum";
  }
  if (tolower(c)== 'n'){
    transChar =  "squanun";
  }
  if (tolower(c)== 'o'){
    transChar =  "squato";
  }
  if (tolower(c)== 'p'){
    transChar =  "squapub";
  }
  if (tolower(c)== 'q'){
    transChar =  "squaquack";
  }
  if (tolower(c)== 'r'){
    transChar =  "squarug";
  }
  if (tolower(c)== 's'){
    transChar =  "squasus";
  }
  if (tolower(c)== 't'){
    transChar =  "squatut";
  }
  if (tolower(c)== 'u'){
    transChar =  "squatu";
  }
  if (tolower(c)== 'v'){
    transChar =  "squavuv";
  }
  if (tolower(c)== 'w'){
    transChar =  "squawack";
  }
  if (tolower(c)== 'x'){
    transChar =  "squaex";
  }
  if (tolower(c)== 'y'){
    transChar =  "squayub";
  }
  if (tolower(c)== 'z'){
    transChar =  "squazub";
  }
  //cout << "is? " << isCaptalized << endl;
  if (isCaptalized){
    //cout << "before: "<< transChar[0] << endl;
    transChar[0] = toupper(transChar[0]);
    //cout << "after: "<< transChar[0] << endl;
  }
  return transChar;
}
