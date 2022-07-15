// BinaryTranslator.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
char getIntValueFromStream();
void toBinary(int number);
int power(int power);
int multiplyWithBase(int inputValue, int powerOfBase);

int _tmain(int argc, _TCHAR* argv[])
{
	int digit = 0;
	int counter = 3;
	int result = 0;
	digit = getIntValueFromStream();
	
	while(counter!=-1) {
		cout << digit << " is an input digit" << "\n";
		result += multiplyWithBase(digit, counter);
		digit = getIntValueFromStream();
		counter--;
		if(counter == -1 && digit != -38) {
			counter = 3;
			result *= 16;
		}
	};
	cout << result << " is result of translation from binary to dec" << "\n";
	while(1);
	return 0;
}

// ������� ������ �������� �� �������� ������ ���� Int
char getIntValueFromStream() {
	return cin.get() - 48;
}

// �������, ���������� ������ � ������ �������
int power(int power) {
	int temp = pow(2,power);
	return temp; 
}

// ������� ������������� ������ � ������ ������� � ����� �� �����
int multiplyWithBase(int inputValue, int powerOfBase) {
	return inputValue*power(powerOfBase);
}

