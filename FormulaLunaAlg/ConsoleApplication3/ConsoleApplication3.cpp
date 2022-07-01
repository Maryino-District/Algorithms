// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

/**
Используя исходное введенное число, увеличить вдвое значение каждой цифры.
Затем словжить значения отдельных цифр (учли удвоенное значение имеет две цифры, то сложить
эти цифры по отедльности). Идентификационный номер проходит проверку если получившаяся сумма
делится на десять. 
Нужно написать программу, которая принимает идентификационный номер произвольной длины
и определяет фо формуле Луна, действителен ли номер. Программа должна обрабатывать каждый символ
перед чтение следующего.
*/


#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int checkSum = repeatCin();
	validate(checkSum);

	while(1){
	}
	return 0;
}

int doubleDigitValue(int value) {
	int doubleDigit = value * 2;
	if (isBiggerThenTen(doubleDigit)) return 1 + doubleDigit % 10;
	return doubleDigit;
}

bool isBiggerThenTen(int value) {
	return value % 10 != 0;
}

// Функция, преобразующая введенное число в int
int charToInt(char num) {
	return num - '0';
}

//int calculateSum(){};

// Функция считывающая нужное число символов
int repeatCin() {
	char digit;
	int evenCheckSum = 0;
	int oddCheckSum = 0;
	int clk = 0;
	digit = cin.get();
	while(digit != 10) {
		if (clk %2 == 0) {
			oddCheckSum += charToInt(digit);
			evenCheckSum += doubleDigitValue(digit-'0');

		} else {
			oddCheckSum += doubleDigitValue(digit-'0');
			evenCheckSum += charToInt(digit);;
		}
		digit = cin.get();
		clk++;
	};
	if (isEven(clk-1)) return evenCheckSum;
	else return oddCheckSum;
}

bool isEven(int number) {
	if (number%2 == 0) return true;
	else return false;
}

bool validate(int checkSum) {
	if (checkSum%10 == 0) {
		cout << "valid";
	} else {
		cout << "not valid";
	}
}