//hw01.cpp
//by Richard Yeung
//This program reads an encrypted text file and decrypts the contents and displays the decrypted message on screen

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//returns a decrypted letter (char) given an encrypted letter and encryption steps
char decryptChar(char letter, int numSteps) {
	//checks if the letter is not a white space or period
	if (letter != ' ' && letter != '.') {
		//checks if the letter is not uppercase and returns the letter if it is
		if (!isupper(letter)) {
			//wraps around the alphabets
			if (letter - numSteps < 'a') {
				return letter + (26 - numSteps);
			}
		}
		else {
			return letter;
		}
	}
}

//decrypts a line (string) given an encrypted line and encryption steps
void decryptLine(string& s, int numSteps) {
	//accesses the letters in the string and decrypts them
	for (size_t i = 0; i < s.size(); ++i) {
		s[i] = decryptChar(s[i], numSteps);
	}
}

int main()
{
	//opens the text file
	ifstream encryptedFile;
	encryptedFile.open("data.txt");

	//Check for error
	if (encryptedFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}

	//stores the number of steps and prints it out
	int numSteps;
	encryptedFile >> numSteps;
	cout << numSteps << endl;

	//obtains a line from the file and decrypts the line
	//the lines of letters are put into a vector to fix the reversed lines
	string line;
	vector<string> reverseLines;
	
	while (getline(encryptedFile, line)) {
		decryptLine(line, numSteps);
		reverseLines.push_back(line);
	}

	//loop from the back of the lines to display the flipped decrypted message normally
	for (size_t i = reverseLines.size() - 1; i > 0; --i) {
		cout << reverseLines[i] << endl;
	}

	//closes the file
	encryptedFile.close();
}

