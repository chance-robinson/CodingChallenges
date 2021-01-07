#include <iostream>
#include "NumberConversions.h"
using namespace std;

void to_modern() { //prompt for the roman numeral to modern numeral dialogue
	NumberConversions numerals;
	string user_input;
  	int modern;
	cin.ignore();
	cout << "Enter a roman numeral: ";
  	getline(cin, user_input);
	modern = numerals.roman_to_modern(user_input);
	while (modern < 0) { //if there was any sort of misinput or wrong formating, allows user to put in a new input
		cout << "Enter a valid roman numeral: ";
		getline(cin, user_input);
		modern = numerals.roman_to_modern(user_input);
	}
	cout << "In modern numerals this is the number: " << modern << endl;
}

void to_roman() { //prompt for the modern numeral to roman numeral dialogue
	NumberConversions numerals;
	string user_input;
  	int modern;
	int modern_numeral;
	string roman;
	cout << "Enter a modern numeral: ";
  	cin >> modern_numeral;
	roman = numerals.modern_to_roman(modern_numeral);
	cout << "In roman numerals this is the symbol: " << roman << endl;
}

void start() { //this is the opening dialogue to this program which allows you to select what numeral you would like to convert
	int option;
	cout << "Would you like to convert a Roman or Modern Numeral?";
	cout << "\n(Enter 1 for Roman or 2 for Modern): ";
	cin >> option;
	if (option == 1) {
		to_modern();
	}
	else if (option == 2) {
		to_roman();
	}
	else {
		cout << "\nTry again?" << endl;
		cout << "(Enter 1 for Yes or 2 for No): ";
		cin >> option;
		if (option == 1) {
			start();
		}
		else {
			exit(0);
		}
	}
}

void repeat() { //gives the user the option to keep playing an infinite amount of times
	int option;
	cout << "\nWould you like to go again?" << endl;
	cout << "(Enter 1 for Yes or 2 for No): ";
	cin >> option;
	if (option == 1) {
		start();
	}
	else {
		exit(0);
	}
}

int main() {
	start();
	while (true) {
		repeat();
	}
	return 0;
}