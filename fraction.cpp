/*
			CS 215 - 004 - Lab 5

Author: Taylor Thomas
Date: 3/3/2020
Description:this program takes numerator and denominator input from the user and outputs the fraction,
decimal value and sum of the fractions that are made by the user's input.
*/

// compiler directives
#include <iomanip>;
#include <iostream>;
#include <string>;
#include <fstream>;
using namespace std;

struct frac {
	int numerator;
	int denomintor;
};

void PrintLogo() {
	cout << "+------------------------------+" << endl;
	cout << "|        FRACTION FUN          |" << endl;
	cout << "|      by Taylor Thomas        |" << endl;
	cout << "+------------------------------+" << endl;
}
// function asking user to enter numerator and denomminator to fraction
void AskFraction(frac &fraction) {
	int  num;
	int den;
	cout << "Enter value for numerator: ";
	cin >> num;
	cout << "Enter value for denominator: ";
	cin >> den;
	while (den == 0) {
		cout << "Enter non-zero denominator: ";
		cin >> den;
	}
	fraction.numerator = num;
	fraction.denomintor = den;
}

// convert the fraction into a decimal value given the fraction structure created
double DecimalValue(frac frac) {
	return 1.0 * frac.numerator / frac.denomintor;
}

//prints the fraction in string form given fraction class
string PrintFraction(frac frac) {
	string string1;
	string1 = to_string(frac.numerator) + "/" + to_string(frac.denomintor);
	return string1;
}

// adds fractions given fractions class
frac Add(frac frac1, frac frac2) {
	frac sumFrac;
	if (frac1.denomintor != frac2.denomintor) {
		sumFrac.numerator = (frac1.numerator * frac2.denomintor) + ((frac2.numerator * frac2.denomintor));
		sumFrac.denomintor = (frac1.denomintor * frac2.denomintor);
	}
	else {
		sumFrac.denomintor = frac1.denomintor;
		sumFrac.numerator = frac1.numerator + frac2.numerator;
	}
	return sumFrac;
}



int main() {
	frac userFrac1;
	frac userFrac2;
	double decimalValue1;

	PrintLogo();
	 AskFraction(userFrac1);
	 AskFraction(userFrac2);
	decimalValue1 = DecimalValue(userFrac1);
	string strFracSumNum = to_string(Add(userFrac1, userFrac2).numerator);
	string strFracSumDen = to_string(Add(userFrac1, userFrac2).denomintor);
	string strFrac1 = PrintFraction(userFrac1);
	string strFrac2 = PrintFraction(userFrac2);
	cout << "The Decimal Value of " << strFrac1 << " is " << decimalValue1 << endl;
	cout << strFrac1 << " + " << strFrac2 << " = " << strFracSumNum << "/" << strFracSumDen << endl;

	system("pause");



	return 0;
}
