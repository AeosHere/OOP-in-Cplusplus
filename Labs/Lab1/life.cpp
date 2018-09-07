//Richard Yeung
//This program is an implementation of "Conway's Game of Life"
//Using a starting text file with the first generation of cells, the program goes on for 10 generations and displays the population

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Reads the text file and transfers the lines of characters into a string vector (board)
//Changes the dashes to represent spaces
void setupBoard(vector<string>& board, string file) {
	ifstream openFile(file);

	if (!openFile) {
		cerr << "Could not open life.txt. \n";
		exit(1);
	}

	string lines;
	string border;
	while (openFile >> lines) {
		if (board.size() == 0) {
			for (size_t ch = 0; ch < lines.length() + 1; ++ch) {
				border += ' ';
			}
			board.push_back(border);
		}
		board.push_back(" " + lines + " ");
	}
	board.push_back(border);

	openFile.close();

	for (size_t r = 1; r < board.size() - 1; ++r) {
		for (int c = 1; c < board[r].length() - 1; ++c) {
			if (board[r][c] == '-') {
				board[r][c] = ' ';
			}
		}
	}
}

//Checks the number of live cells around the current cell at row and col
//Gets the number of live cells around and returns it
int getNumAliveNeighbors(const vector<string>& board, int row, int col) {
	int numAlive = 0;
	if (board[row - 1][col - 1] == '*') {
		numAlive += 1;
	}
	if (board[row - 1][col] == '*') {
		numAlive += 1;
	}
	if (board[row - 1][col + 1] == '*') {
		numAlive += 1;
	}
	if (board[row][col - 1] == '*') {
		numAlive += 1;
	}
	if (board[row][col + 1] == '*') {
		numAlive += 1;
	}
	if (board[row + 1][col - 1] == '*') {
		numAlive += 1;
	}
	if (board[row + 1][col] == '*') {
		numAlive += 1;
	}
	if (board[row + 1][col + 1] == '*') {
		numAlive += 1;
	}
	return numAlive;
}

//Runs the Game of Life Program based on how many generations
//Checks the number of live cells around the current row and cell and changes it to its appropriate cell type
void runProgram(int numGens, vector<string>& board, vector<string>& newBoard) {
	for (int generation = 0; generation < numGens; ++generation) {
		for (int r = 1; r < board.size() - 1; ++r) {
			cout << newBoard[r] << endl;
			for (int c = 1; c < board[r].length() - 1; ++c) {
				int numAlive = 0;
				numAlive = getNumAliveNeighbors(board, r, c);
				
				if (board[r][c] == ' ') {
					if (numAlive == 3) {
						newBoard[r][c] = '*';
					}
					else {
						newBoard[r][c] = ' ';
					}
				}
				else {
					if (numAlive == 3 || numAlive == 2) {
						newBoard[r][c] = '*';
					}
					else {
						newBoard[r][c] = ' ';
					}
				}
			}
		}
		board = newBoard;
		cout << "______________________" << endl;
	}
}

int main()
{
	vector<string> board;
	vector<string> newBoard;
	setupBoard(board, "life.txt");
	newBoard = board;
	runProgram(10, board, newBoard);
}

