// multiTranslator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
int getDecValueFromStream();
int getDigitFromStream();
void translateDecValue();
void translateHexValue();
void translateBinValue();
bool isNotEndOfStream(int value);
string getStringValueFromStream();
void fromDecTranslator(int devided);
void fromAnyToDecTranslator(int any);
int getIntFromHexChar(int charValue);
int translate(int from, int to);

int _tmain(int argc, _TCHAR* argv[])
{
	translate(10,16);
	while(1);
	return 0;
}

/*
* Функции получания чисел из потока
*/
int getDecValueFromStream() {
	int digit = getDigitFromStream();
	int result = 0;
	while(isNotEndOfStream(digit)) {
		result = result*10 + digit;
		digit  = getDigitFromStream();
	}
	cout << "you get dec value = " << result << "\n";
	return result;
}

string getStringValueFromStream() {
	int digit = 0;
	char tmpChar;
	string result = "";
	digit = getDigitFromStream();
	while(isNotEndOfStream(digit)) {
		tmpChar = digit +48;
		cout << " " << tmpChar << "\n";
		digit = getDigitFromStream();
		result +=tmpChar;
	}
	cout << "result is " << result << "\n";
	return result;
}

// Получаем цифру из потока в инте
int getDigitFromStream() {
	return cin.get()-48;
}

/*
* Utils
*/
bool isNotEndOfStream(int value) {
	return value != -38;
} 

/*
* Функции перевода их 10 в остальные системы
*/
int getIntFromHexChar(int charValue) {
		switch(charValue) {
		case 49:
			return 10;
			break;
		case 50:
			return 11;
			break;
		case 51: 
			return 12;
			break;
		case 52: 
			return 13;
			break;
		case 53: 
			return 14;
			break;
		case 54: 
			return 15;
			break;
		default: 
			return 0;
			break;
		}
}

void fromDecTranslator(int devided) {
	int quotient = getDecValueFromStream();
	string result = "";
	int numberOfDigits = 0;
	while (quotient >= devided) {
		int tmpInt = quotient%devided;
		string tmpString = "";
		if (tmpInt > 9) {
			switch(tmpInt) {
				case 10:
					tmpString = "A";
					break;
				case 11:
					tmpString = "B";
					break;
				case 12: 
					tmpString = "C";
					break;
				case 13: 
					tmpString = "D";
					break;
				case 14: 
					tmpString = "E";
					break;
				case 15: 
					tmpString = "F";
					break;
				default: 
					tmpString = " ";
					break;
			}
     		result = tmpString + result;
			numberOfDigits++;
		} else {
			result = to_string(tmpInt) + result;
			numberOfDigits++;
		}
		quotient /= devided;
	}
	result = to_string(quotient) + result;
	cout << result << " is result of translation and number of digits is " << numberOfDigits;
}

/*
* Функции перевода из оюбой другой системы в десятичную
*/
void fromAnyToDecTranslator(int any) {
	int digit = getDigitFromStream();
	int result = 0;
	int power = 0;
	int counter = 1;
	int temp = 0;
	while(isNotEndOfStream(digit)) {
		if (digit > 9) {
			temp = getIntFromHexChar(digit);
			result = result*any + temp;
		} else {
			result = result*any + digit;
		}
		digit  = getDigitFromStream();
		if (isNotEndOfStream(digit)) {
			if (digit > 9) {
			temp = getIntFromHexChar(digit);
			result = result*any + temp;
			} else {
				result = result*any + digit;
			}
			digit  = getDigitFromStream();
		}		
	}
	cout << "\n" << result;
}

/*
* Функция переводчик из люблой системы отсчета в любую другую
*/
int translate(int from, int to) {
	if (to == 10) {
		fromAnyToDecTranslator(2);
		return 0;
	}
	switch(from) {
		case 2:
			fromAnyToDecTranslator(2);	
			fromDecTranslator(to);
			break;
		case 8: 
		    fromAnyToDecTranslator(8);	
			fromDecTranslator(to);
			break;
		case 10: 	
			fromDecTranslator(to);
			break;
		case 16: 
			fromAnyToDecTranslator(16);	
			fromDecTranslator(to);
			break;
	}
	return 0;
} 
	