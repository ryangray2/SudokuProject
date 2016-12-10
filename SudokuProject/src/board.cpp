#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "board.hpp"

using namespace std;

Board::Board() {
  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 9; i++) {
      game[j][i] = 0;
    } // for
  } // for
  input = "";
} // Board

// Prints the board.
void Board::printBoard() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (col == 2 || col == 5) {
        cout << game[row][col] << " ";
        cout << "| ";
      } // if
      else {
        cout << game[row][col] << " ";
      } // else
    } // for
    if (row == 2 || row == 5) {
      cout << endl;
      cout << "---------------------";
      cout << endl;
    } // if
    else {
      cout << endl;
    } // else
  } // for
} // printBoard

// Checks if given number is already in given row.
bool Board::inRow(int row, int n) {
  for (int c = 0; c < 9; c++) {
    if (game[row][c] == n) {
      return true;
    } // if
  } // for
  return false;
} // inRow

// Checks if given number is already in given column.
bool Board::inCol(int col, int n) {
  for (int r = 0; r < 9; r++) {
    if (game[r][col] == n) {
      return true;
    } // if
  } // for
  return false;
} // inCol

// Checks if given number is already in given box.
bool Board::inBox(int boxRow, int boxCol, int n) {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (game[boxRow + r][boxCol + c] == n) {
        return true;
      } // if
    } // for
  } // for
  return false;
} // inBox

// Checks if given number is a legal play
bool Board::isLegal(int row, int col, int n) {
  if (inBox(row - (row % 3), col - (col % 3), n) ||
      inCol(col, n) ||
      inRow(row, n)) {
        return false;
      } // if
  return true;
} // isLegal

// Finds empty spots.
bool Board::findZero(int &row, int &col) {
  for (row = 0; row < 9; row++) {
    for (col = 0; col < 9; col++) {
      if (game[row][col] == 0) {
        return true;
      } // if
    } // for
  } // for
  return false;
} // findZero

// Solves the puzzle.
bool Board::solve() {
  int r;
  int c;
  if (findZero(r, c) == false) {
    return true;
  } // if
  for (int value = 1; value < 10; value++) {
    if (isLegal(r, c, value)) {
      game[r][c] = value;
      if (solve()) {
        return true;
      } // if
      game[r][c] = 0;
    } // if
  } // for
  return false;
} // solve

// Gets the input from the user.
void Board::getInput() {
  cout << "Enter the numbers on the board, from left to right, with no spaces." << endl;
  cout << "(Use zero for blank spaces)" << endl;
  cin >> input;
  if (input.size() > 81) {
    int diff = input.size() - 81;
    cout << endl;
    cout << diff << " too many numbers. Try again." << endl;
    getInput();
  } // if
  else if (input.size() < 81) {
    int diff2 = 81 - input.size();
    cout << endl;
    cout << diff2 << " numbers short. Try again." << endl;
    getInput();
  } // else if
} // getInput

// Converts the input from a string and puts the numbers on the board.
void Board::convertInput() {
  int strCount = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char temp = input[strCount];
      int x = charToInt(temp);
      game[i][j] = x;
      strCount++;
    } // for
  } // for
} // convertInput

// Replaces a number at a given spot.
void Board::replacement(int row, int col, int num) {
  int r = row - 1;
  int c = col - 1;
  game[r][c] = num;
} // replacement

// Function for the user.
void Board::toUser() {
  bool flag = false;
  string response;
  getInput();
  convertInput();
  while(!flag) {
    cout << endl;
    printBoard();
    cout << endl << "Is this correct (y or n)?";
    cin >> response;
    if (response == "y") {
      solve();
      cout << endl << "Solved puzzle:" << endl;
      printBoard();
      flag = true;
    } // if
    else {
      int tempRow, tempCol, tempVal;
      cout  << endl << "Where do you want to make a change?";
      cout << endl << "(Left-most column is 1, top row is 1)";
      cout << endl << endl << "row: ";
      cin >> tempRow;
      cout << endl << "column: ";
      cin >> tempCol;
      cout << endl << "Enter new value: ";
      cin >> tempVal;
      replacement(tempRow, tempCol, tempVal);
    } // else
  } // while
} // toUser

// Converts character to integer.
int Board::charToInt(const char c) {
    switch (c) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			return 0;
    } // switch
} // charToInt



















