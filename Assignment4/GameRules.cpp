/*
@file Game.cpp
@brief
@author Lauren Szlosek
*/
//#include "FileProcessor.h"
#include "GameRules.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
/*
FileProcessor()
constructor
*/
GameRules::GameRules() : gameRows(rowDefault), gameCols(colDefault), genCount(genDefault){
  cout << endl;
  //askUser();
  playGame();
}
/*
~FileProcessor()
destructor
*/
GameRules::~GameRules(){
  cout << "Destructor Called" << endl;
  for (int iRow = 0; iRow < this->gameRows; iRow++)
  {
    delete[] userInputGrid[iRow];
  }
  delete[] userInputGrid;
  userInputGrid = nullptr;
}

void GameRules::playGame(){
  askUser();
  initializeWorkingGrid();
  if (gameMode == 1){
    playClassicMode();
  }else if (gameMode == 2){
    playDonutMode();
  }else if (gameMode == 3){
    playMirrorMode();
  } else{
    cout << "Error: No Game Mode Entered" << endl;
  }
}

void GameRules::initializeGrid(){
  this->gameRows+=2;
  this->gameCols+=2;
  this->userInputGrid = new char* [this->gameRows];
  for (int iRow = 0; iRow < this->gameRows; iRow++){
    userInputGrid[iRow] = new char[this->gameCols];
  }
  for (int i = 0; i < this->gameRows; i++)
	{
		for (int j = 0; j < this->gameCols; j++)
		{
			this->userInputGrid[i][j] = '-';
		}
	}

	return;
}

void GameRules::initializeWorkingGrid(){
  this->workingGameGrid = new char* [this->gameRows];
  for (int iRow = 0; iRow < this->gameRows; iRow++){
    workingGameGrid[iRow] = new char[this->gameCols];
  }
  for (int i = 0; i < this->gameRows; i++)
	{
		for (int j = 0; j < this->gameCols; j++)
		{
			this->workingGameGrid[i][j] = '-';
		}
	}
	return;
}

void GameRules::askUser(){
  char userAns;
  string userGameGrid;
  cout << "Hello! Welcome to Game of Life" << endl;
  cout << endl;
  cout << "------------------- " << endl;
  cout << "Do you want to provide a map file? (Y/N)" << endl;
  cout << "------------------- " << endl;
  cin >> userAns;
  cout << endl;
  cout << "--Enter game mode-- " << endl;
  cout << "Type 1 for Classic Mode" << endl;
  cout << "Type 2 for Donut Mode" << endl;
  cout << "Type 3 for Mirror Mode" << endl;
  cout << "------------------- " << endl;
  cin >> gameMode;
  cout << endl;
  cout << "------------------- " << endl;
  cout << "Type 1 to see click to see each generation" << endl;
  cout << "Type 2 to print generations to a file" << endl;
  cout << "------------------- " << endl;
  cin >> gameRes;
  if (gameRes==2){
    cout << "------------------- " << endl;
    cout << "Enter output file name:" << endl;
    cout << "------------------- " << endl;
    cin >> outputFile;
  }
  cout << endl;

  if ((userAns == 'Y') || (userAns == 'y')){
    string userFile;
    cout << "------------------- " << endl;
    cout << "Enter file name with initial map file: " << endl;
    cout << "------------------- " << endl;
    cin >> userFile;
    cout << endl;
    gridFromUserFile(userFile);
  } else if ((userAns == 'N') || (userAns == 'n')){
    string randFile;
    randFile = gridFromPercentage();
    gridFromUserFile(randFile);
  }
  return;
}

void GameRules::gridFromUserFile(string userImput){
  ifstream userFileName;
  string lineOne;
  string lineTwo;
  string userGrid;
  userFileName.open(userImput);
  if (!userFileName.is_open()){
    std::cout << "Error with Input File Name." << std::endl;
  }
  getline(userFileName,lineOne);
  this->gameRows = stoi(lineOne); //https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/#:~:text=One%20effective%20way%20to%20convert,the%20integer%20version%20of%20it.
  getline(userFileName,lineTwo);
  this->gameCols = stoi(lineTwo);

  initializeGrid();
  for (int i = 0; i < gameRows-1; i++){
    getline(userFileName,userGrid);
    for (int j = 0; j < gameCols-1; j++){
      this->userInputGrid[i+1][j+1] =  userGrid[j];
      //cout << this->userInputGrid[i][j] << i << j << " ";
    }
    //cout << endl;
  }
  printGrid();
}

string GameRules::gridFromPercentage(){
  ofstream generatedFile;
  int userRows;
  int userCols;
  int gridArea;
  double percentFilled;
  int numFilled;
  int randNum;
  string fileName = "generatedFile.txt";
  generatedFile.open(fileName);//https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
  cout << "------------------- " << endl;
  cout << "Enter amount of rows: " << endl;
  cout << "------------------- " << endl;

  cin >> userRows;
  generatedFile << userRows << "\n";
  cout << "------------------- " << endl;
  cout << "Enter amount of columns: " << endl;
  cout << "------------------- " << endl;

  cin >> userCols;
  generatedFile << userCols << "\n";
  cout << "------------------- " << endl;
  cout << "Enter percentage (0-1) of space to be filled: " << endl;
  cout << "------------------- " << endl;

  cin >> percentFilled;
  percentFilled = percentFilled * 100;
  gridArea = userRows*userCols;
  numFilled = gridArea * percentFilled;

  for (int i = 0; i < userRows; i++){
    for (int j = 0; j < userCols; j++){
      randNum = rand() % 100 + 1;
      if (randNum < percentFilled){
        generatedFile << 'X';
      } else {
        generatedFile << '-';
      }
    }
    generatedFile << endl;
  }


  generatedFile.close();
  return fileName;
}

void GameRules::playClassicMode(){
  int genCount = 1;
  bool isStable;
  while (true){
    for (int i = 1; i < gameRows-1; i++){
      for(int j = 1; j < gameCols-1; j++){
        checkNeighbors(i,j);
      }
    }
    isStable = isGameStable();
    //cout << "Generation: " << genCount << endl;
    for (int i = 0; i < gameRows; i++){
      for(int j = 0; j < gameCols; j++){
        this->userInputGrid[i][j] = this->workingGameGrid[i][j];
      }
    }
    printGrid();
    if (isStable){
      cout << "------------------- " << endl;
      cout << "Game Over" << endl;
      cout << "------------------- " << endl;
      cout << endl;
      cout << "Click Enter to End Game" << endl;
      cout << endl;
      cin.ignore();
      break;
    }
  }
}

void GameRules::playDonutMode(){
  bool isStable;
  for (int i = 0; i < gameRows; i++){
    for(int j = 0; j < gameCols; j++){
      if (this->userInputGrid[i][j] == 'X'){
        this->userInputGrid[0][j] = 'X';
        this->userInputGrid[i][0] = 'X';
      }
    }
  }
  while (true){
    for (int i = 1; i < gameRows-1; i++){
      for(int j = 1; j < gameCols-1; j++){
        checkNeighbors(i,j);
      }
    }
    isStable = isGameStable();
    //cout << "Generation: " << genCount << endl;
    for (int i = 0; i < gameRows; i++){
      for(int j = 0; j < gameCols; j++){
        this->userInputGrid[i][j] = this->workingGameGrid[i][j];
      }
    }
    printGrid();
    if (isStable){
      cout << "------------------- " << endl;
      cout << "Game Over" << endl;
      cout << "------------------- " << endl;
      cout << endl;
      cout << "Click Enter to End Game" << endl;
      cout << endl;
      cin.ignore();
      break;
    }
  }
}

void GameRules::playMirrorMode(){
  bool isStable;
  for (int i = 0; i < gameRows; i++){
    for(int j = 0; j < gameCols; j++){
       if ((this->userInputGrid[i][j] == 'V') && ((i == 1)||(i == gameRows-1)||(j==1)||(j==gameCols-1))){
        cout << "V" << i << j << endl;
        this->userInputGrid[0][j] = 'X';
        this->userInputGrid[i][0] = 'X';
      }
    }
  }
  while (true){
    for (int i = 1; i < gameRows-1; i++){
      for(int j = 1; j < gameCols-1; j++){
        checkNeighbors(i,j);
      }
    }
    isStable = isGameStable();
    //cout << "Generation: " << genCount << endl;
    for (int i = 0; i < gameRows; i++){
      for(int j = 0; j < gameCols; j++){
        this->userInputGrid[i][j] = this->workingGameGrid[i][j];
      }
    }
    printGrid();
    if (isStable){
      cout << "------------------- " << endl;
      cout << "Game Over" << endl;
      cout << "------------------- " << endl;
      cout << endl;
      cout << "Click Enter to End Game" << endl;
      cout << endl;
      cin.ignore();
      break;
    }
  }
}

void GameRules::checkNeighbors(int i, int j){

  int neighborCounter = 0;
    if (this->userInputGrid[i-1][j-1] == 'X'){
      neighborCounter++;
    } if (this->userInputGrid[i-1][j] == 'X'){
      neighborCounter++;
    } if (this->userInputGrid[i-1][j+1] == 'X'){
      neighborCounter++;
    } if (this->userInputGrid[i][j-1] == 'X'){
      neighborCounter++;
    } if (this->userInputGrid[i][j+1] == 'X'){
      neighborCounter++;
    } if (this->userInputGrid[i+1][j-1] == 'X'){
      neighborCounter++;
    } if (this->userInputGrid[i+1][j] == 'X'){
      neighborCounter++;
    } if (this->userInputGrid[i+1][j+1] == 'X'){
      neighborCounter++;
    }

    if (neighborCounter <= 1){
      this->workingGameGrid[i][j] = '-'; //lonely
    } else if (neighborCounter == 2){
      this->workingGameGrid[i][j] = this->userInputGrid[i][j]; // stable
    } else if (neighborCounter == 3){
      this->workingGameGrid[i][j] = 'X'; // creation
    } else if (neighborCounter >= 4){
      this->workingGameGrid[i][j] = '-'; //overcrowded
    }
    // cout << "filling work: " << genCount << endl;
    // for (int i = 1; i < gameRows-1; i++){
    //   for(int j = 1; j < gameCols-1; j++){
    //     cout << this->workingGameGrid[i][j];
    //   }
    //   cout << endl;
    // }
}

void GameRules::printGrid(){
  ofstream userOutputFile;
  if (gameRes == 1){
    cout << "Generation: " << genCount << endl;
    for (int i = 1; i < gameRows-1; i++){
      for(int j = 1; j < gameCols-1; j++){
        cout << this->userInputGrid[i][j];
      }
      cout << endl;
    }
    cout << endl;
    cout << "Press enter to continue- " << endl;
    cin.ignore(); // https://stackoverflow.com/questions/903221/press-enter-to-continue
    genCount++;
  }
  if (gameRes == 2){

    userOutputFile.open(outputFile, fstream::app);
    userOutputFile << "Generation: " << genCount << endl;
    for (int i = 1; i < gameRows-1; i++){
      for(int j = 1; j < gameCols-1; j++){
        userOutputFile << this->userInputGrid[i][j];
      }
      userOutputFile << endl;
    }

    genCount++;
  }
  userOutputFile.close();
}

bool GameRules::isGameStable(){
  bool isStable = true;
  for (int i = 1; i < gameRows-1; i++){
    for(int j = 1; j < gameCols-1; j++){
      if (this->userInputGrid[i][j] != this->workingGameGrid[i][j]){
        isStable = false;
      }
    }
  }
  return isStable;
}
