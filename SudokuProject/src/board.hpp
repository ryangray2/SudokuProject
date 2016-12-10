#ifndef Grid_HPP
#define Grid_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Board {
  int game[9][9];
  string input;
public:
  Board();
  void printBoard();
  bool inRow(int row, int n);
  bool inCol(int col, int n);
  bool inBox(int row, int col, int n);
  bool isLegal(int row, int col,int n);
  bool findZero(int &row, int &col);
  bool solve();
  void getInput();
  void convertInput();
  void toUser();
  int charToInt(const char c);
  void replacement(int r, int c, int num);
};

#endif /* Grid_HPP */




