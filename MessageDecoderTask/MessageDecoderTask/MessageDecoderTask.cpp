// MessageDecoderTask.cpp: определяет точку входа для консольного приложения.
/**
* Имеется входной поток целых положительных чисел, разделенных запятыми. 
* Сущетсвует три режима декодирования: верхний рег, нижний и пунтуация
* Целое взятое по модулю 27 есть позиция буквы в алфавите, а если
* текущий режим- пунктуация, то см. таблицу. 
* Исходный режим- верхний регистр. Преключение происходит в случае
* Когда введенное число по модулю 27 равно нулю. Смена происходит циклично.
* Необходимо написать программу, корректно считывающую входной текст.
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
// Фцнкция преобразование символа в число
int charToInt(char inputValue) {
	return inputValue - '0'; // Так как "0" кодируется значением 48
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








