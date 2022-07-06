// FigureTask.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

void printBottomPyramid(int pyramidHeight); 
void printTopPyramid(int pyramidHeight);

int _tmain(int argc, _TCHAR* argv[])
{
	int pyramidHeight = 4;
	printTopPyramid(pyramidHeight);
	printBottomPyramid(pyramidHeight);

	while(1);
	return 0;
}

void printTopPyramid(int pyramidHeight) {
	for (int i = 0; i < pyramidHeight; i++) {
		for (int k = 0; k <pyramidHeight - i-1; k++) {
			cout << " ";
		}

		for (int j = 0; j < (i+1)*2; j++) {
			cout << "#";
		}
		cout << "\n";
	}
}

void printBottomPyramid(int pyramidHeight) {
	for (int i = 0; i < pyramidHeight; i++) {
		for (int k = 0; k <i; k++) {
			cout << " ";
		}

		for (int j = 0; j < pyramidHeight*2 - i*2; j++) {
			cout << "#";
		}
		cout << "\n";
	}
}

