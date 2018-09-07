//Richard Yeung
//Program that reads a text file with formulas and orders them by the number of carbon atoms and displays the formulas 

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct MolecularFormula {
	vector<string> name;
	int carbonAtoms;
	int hydrogenAtoms;
};

size_t findToken(const vector<MolecularFormula>& formulas, int carbonAtoms, int hydrogenAtoms) {
	for (size_t i = 0; i < formulas.size(); ++i) {
		if (formulas[i].carbonAtoms == carbonAtoms && formulas[i].hydrogenAtoms == hydrogenAtoms) {
			return i;
		}
	}
	return formulas.size();
}

int findHighestCarbonAtoms(const vector<MolecularFormula>& formulas) {
	int highest = formulas[0].carbonAtoms;
	for (size_t i = 0; i < formulas.size(); ++i) {
		if (formulas[i].carbonAtoms > highest) {
			highest = formulas[i].carbonAtoms;
		}
	}
	return highest;
}

void print(const vector<MolecularFormula>& formulas) {
	int highestCarbonAtoms = findHighestCarbonAtoms(formulas);
	for (int cAtoms = 1; cAtoms <= highestCarbonAtoms; ++cAtoms) {
		for (size_t i = 0; i < formulas.size(); ++i) {
			if (cAtoms == formulas[i].carbonAtoms) {
				cout << 'C' << formulas[i].carbonAtoms << 'H' << formulas[i].hydrogenAtoms;
				for (size_t n = 0; n < formulas[i].name.size(); ++n) {
					cout << " " + formulas[i].name[n];
				}
				cout << endl;
			}
		}
	}
}

int main()
{
	ifstream chemText("hydrocarbs.txt");

	if (!chemText) {
		cerr << "Could not open chem text.";
		exit(1);
	}

	vector<MolecularFormula> formulas;
	string name;
	char ignoreMe;
	int numCarbonAtoms;
	int numHydrogenAtoms;

	while (chemText >> name >> ignoreMe >> numCarbonAtoms >> ignoreMe >> numHydrogenAtoms){
		MolecularFormula formula;
		formula.carbonAtoms = numCarbonAtoms;
		formula.hydrogenAtoms = numHydrogenAtoms;
		size_t loc = findToken(formulas, formula.carbonAtoms, formula.hydrogenAtoms);
		if (loc == formulas.size()) {
			formula.name.push_back(name);
			formulas.push_back(formula);
		}
		else {
			formulas[loc].name.push_back(name);
		}
	}
	print(formulas);
}

