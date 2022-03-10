/*
@file GameRules.cpp
@brief Implements the Game of Life
@author Lauren Szlosek
*/
#include "GameRules.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
/*
GameRules()
constructor
*/
GameRules::GameRules() : gameRows(rowDefault), gameCols(colDefault), genCount(genDefault){
  cout << endl;
  //askUser();
  playGame();
}
/*
~GameRules()
destructor
*/
GameRules::~GameRules(){
  for (int iRow = 0; iRow < this->gameRows; iRow++)
  {
    delete[] userInputGrid[iRow];
  }
  delete[] userInputGrid;
  userInputGrid = nullptr;
}
/*
playGame()
causes game play
calls the functions to play each game mode
*/
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
/*
initializeGrid()
initializes grid of pointers
*/
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
/*
initializeWorkingGrid()
ititializes second grid for game play
*/
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
/*
askUser()
prints out statements for user to pick game play settings
*/
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
    gridFromFile(userFile);
  } else if ((userAns == 'N') || (userAns == 'n')){
    string randFile;
    randFile = fileFromPercentage();
    gridFromFile(randFile);
  } else {
    cout <<  endl;
    cout << "No answer provided. Game Over. " << endl;
    cout <<  endl;
  }
  return;
}
/*
gridFromFile()
fills the grid based off of file parameter
@param string userImput, file being read
*/
void GameRules::gridFromFile(string userImput){
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
    }
  }
  printGrid();
}
/*
fileFromPercentage()
creates file based off of imputs from user
@return string, name of file
*/
string GameRules::fileFromPercentage(){
  ofstream generatedFile;
  int userRows;
  int userCols;
  int gridArea;
  double percentFilled;
  int numFilled;
  int randNum;
  string fileName = "generatedFile.txt";
  generatedFile.open(fileName);
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
/*
playClassicMode()
plays classic mode
*/
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
/*
playDonutMode()
plays donut mode
*/
void GameRules::playDonutMode(){
  bool isStable;
  for (int i = 0; i < gameRows; i++){ // maybe <
    for(int j = 0; j < gameCols; j++){ // maybe <
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
/*
playMirrorMode()
plays mirror mode
*/
void GameRules::playMirrorMode(){
  bool isStable;
  for (int i = 0; i < gameRows; i++){
    for(int j = 0; j < gameCols; j++){
       if ((this->userInputGrid[i][j] == 'V') && ((i == 1)||(i == gameRows-2)||(j==1)||(j==gameCols-2))){
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
/*
checkNeighbors()
iteraties over grid and checks for the rules of the game of life
@param int i, int j, position of grid that's being checked
*/
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
}
/*
printGrid)
prints out grid for each generation
*/
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
/*
isGameStable()
checks to see if the generations are stable
@return bool, game is either stable or not
*/
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
