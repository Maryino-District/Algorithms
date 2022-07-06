// MessageDecoderTask.cpp: ���������� ����� ����� ��� ����������� ����������.
/**
* ������� ������� ����� ����� ������������� �����, ����������� ��������. 
* ���������� ��� ������ �������������: ������� ���, ������ � ���������
* ����� ������ �� ������ 27 ���� ������� ����� � ��������, � ����
* ������� �����- ����������, �� ��. �������. 
* �������� �����- ������� �������. ����������� ���������� � ������
* ����� ��������� ����� �� ������ 27 ����� ����. ����� ���������� ��������.
* ���������� �������� ���������, ��������� ����������� ������� �����.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

void getNumberToInt();

int _tmain(int argc, _TCHAR* argv[])
{
	getNumberToInt();
	while(1);
	return 0;
}

char pickPunctuationMark(int number) {
	switch (number) {
		case 1: return '!'; break;
		default: return '.'; break;
	}
}
// ������� �������������� ������� � �����
int charToInt(char inputValue) {
	return inputValue - '0'; // ��� ��� "0" ���������� ��������� 48
}

int decode(int value) {
	return value % 27;
}

int checkStatus(int value) {
	return decode(value);
}
//
bool isChanged(int status) {
	return status == 0;
}

int changeMode(int currentMode) {
	return (currentMode+1)%3;
}

char numberToLetter(int number) {
	int currentMode = 0;
	int status = checkStatus(decode(number));
	if (isChanged(status)) currentMode = changeMode(currentMode); 
	
	switch (currentMode) {
		case 0: {
			cout << "decoded number is: " << number + 'A' - 1<< "\n";
			return number + 'A' - 1;
			break;
			};//ASCII = 64
		case 1: {
			cout << "decoded number is: " << number + 'a' - 1<< "\n";
			return number + 'a' - 1;
			break;
			};
		case 2: {
			cout << "decoded number is: " << pickPunctuationMark(number)<< "\n";
			return pickPunctuationMark(number);
			break;
			};
	}
}

void getNumberToInt() {
	char charDigit;
	int intDigit;
	do {
		charDigit = cin.get();
		intDigit = charToInt(charDigit);
		charDigit = cin.get();
		while(charDigit != ',' && charDigit != 10 ) {
			intDigit = intDigit*10 + charToInt(charDigit);
			charDigit  = cin.get();
		}
		numberToLetter(intDigit);
		cout << "nuumber entered: " << intDigit << "\n";
	} while (charDigit !=10);
}








