/*
@file Game.h
@brief header file for Game class
@author Lauren Szlosek
*/
#include <string>
using namespace std;

class GameRules{
  static const int rowDefault = 0;
  static const int colDefault = 0;
  static const int genDefault = 0;
private:
  char** userInputGrid;
  char** workingGameGrid;
  int gameMode;
  int gameRes;
  int genCount;
  string outputFile;
  int gameRows;
  int gameCols;
public:
  GameRules();
  ~GameRules();
private:
  void askUser();
  void initializeGrid();
  void gridFromFile(string userImput);
  string fileFromPercentage();
  void playGame();
  void playClassicMode();
  void playDonutMode();
  void playMirrorMode();
  void checkNeighbors(int i, int j);
  void initializeWorkingGrid();
  bool isGameStable();
  void printGrid();
};
