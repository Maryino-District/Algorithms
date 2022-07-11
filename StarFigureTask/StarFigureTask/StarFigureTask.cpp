
#include "stdafx.h"
#include <iostream>
using namespace std;
void printTopPart(int height);
void printBottomPart(int height);
void printBase(int height);
int _tmain(int argc, _TCHAR* argv[])
{
	printTopPart(4);
	printBottomPart(4);
	while(1);
	return 0;
}

void printTopPart(int height) {
	for (int i = 0; i < height - 1; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}

		for (int j = 0; j <i+1; j++) {
			cout << "#";
		}

		for (int j = 0; j < height*(height-i-1); j++) {
			cout << " ";
		}

		for (int j = 0; j <i+1; j++) {
			cout << "#";
		}
		cout << "\n";
	}
	printBase(height);
	
}

void printBase(int height) {
	for (int i = 0; i<height-1; i++) {
		cout << " ";
	}
	for (int i = 0; i<2*height; i++) {
		cout << "#";
	}
	cout << "\n";
}

void printBottomPart(int height) {
	printBase(height);
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<height-i-2; j++) {
			cout << " ";	
		}
		
		for (int j = 0; j < height-i-1; j++) {
			cout << "#";
		}  

		for (int j = 0; j <height*(i+1); j++) {
			cout << " ";
		}
		
		for (int j = 0; j < height-i-1; j++) {
			cout << "#";
		}  
		
		cout << "\n";
	}
}
