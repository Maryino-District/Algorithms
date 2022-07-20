#include "stdafx.h"
#include "iostream"
using namespace std;

int getInputDecVaue();
int translateFromDecToBinary(int decValue);
int getIntValueFromStream();

int _tmain(int argc, _TCHAR* argv[])
{
	int decValue = getInputDecVaue();
	translateFromDecToBinary(decValue);
	
	while(1);
	return 0;
}

int getIntValueFromStream() {
	return cin.get() - 48;
}

//
int getInputDecVaue() {
	int output = 0;
	int digit = getIntValueFromStream();
	while (digit != -38) {
		output += digit;
		digit = getIntValueFromStream();
		if (digit != -38) output *= 10;
	}
	cout << "\n" << output << " is input int" << "\n";
	return output;
}
 //
int translateFromDecToBinary(int decValue) {
	int quotient = decValue;
	int result = 1;
	int numberOfDigits = 0;
	while (quotient != 1) {
		if (quotient%2 == 0) {
			result +=  9 * pow(10,numberOfDigits);
			numberOfDigits++;
		} else {
			result +=  9 * pow(10,numberOfDigits) + 1 * pow(10,numberOfDigits);
			numberOfDigits++;
		}
		quotient /= 2;
	}
	for (int i = 0; i < 4 - (numberOfDigits+1) %4; i++) {
		cout << 0;
	}
	cout << result << " is result of translation";
	return result;
}