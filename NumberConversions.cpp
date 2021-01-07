#include "NumberConversions.h"
//assigns a value to each roman numeral
int NumberConversions::values_roman(char x) {
	if (x == 'I' || x == 'i') {
		return 1;
	}
	if (x == 'V' || x == 'v') {
		return 5;
	}
	if (x == 'X' || x == 'x') {
		return 10;
	}
	if (x == 'L' || x == 'l') {
		return 50;
	}
	if (x == 'C' || x == 'c') {
		return 100;
	}
	if (x == 'D' || x == 'd') {
		return 500;
	}
	if (x == 'M' || x == 'm') {
		return 1000;
	}
	else {
		return -1;
	}
};

//this function will convert a roman numeral to a modern numeral using the rules as given by this challenge
int NumberConversions::roman_to_modern(string user_input) {
	int value = 0; // initialize our value as zero each time we run this function
	for (int i = 0; i < user_input.length(); i++) {
		int char1 = values_roman(user_input[0 + i]);
		if (i+1 < user_input.length()) { //make sure there is a second roman numeral before continuing
			int char2 = values_roman(user_input[1 + i]);
			if (char1 < char2) { //subtractive notation if char1 is < char2
				value = value + (char2 - char1);
				i++;
			}
			else { //if char1 > char2 add char1 to value
				value = value + char1;
			}
			if (i > 1 && (char2 % 10 == 0) && ((char2 / char1) != 10)) { //confirm that rule 4 is being kept
				cout << "\t" << user_input << " is a violation of rule 4" << endl;
				return -1;
				break;
			}
		}
		else { //if there is not a second roman numeral, add the first to the total value
			value = value + char1;
		}
	}
	return value; //final value
};

string NumberConversions::modern_to_roman(int input) { //conversion of modern numerals to roman
	string roman_output = "";
	int initial = input;
	while (initial >= 1000) {
		initial = initial - 1000;
		roman_output.push_back('M');
	}
	while (initial >= 900) {
		initial = initial - 900;
		roman_output.push_back('C');
		roman_output.push_back('M');
	}
	while (initial >= 500) {
		initial = initial - 500;
		roman_output.push_back('D');
	}
	while (initial >= 400) {
		initial = initial - 400;
		roman_output.push_back('C');
		roman_output.push_back('D');
	}
	while (initial >= 100) {
		initial = initial - 100;
		roman_output.push_back('C');
	}
	while (initial >= 90) {
		initial = initial - 90;
		roman_output.push_back('X');
		roman_output.push_back('C');
	}
	while (initial >= 50) {
		initial = initial - 50;
		roman_output.push_back('L');
	}
	while (initial >= 40) {
		initial = initial - 40;
		roman_output.push_back('X');
		roman_output.push_back('L');
	}
	while (initial >= 10) {
		initial = initial - 10;
		roman_output.push_back('X');
	}
	while (initial >= 9) {
		initial = initial - 9;
		roman_output.push_back('I');
		roman_output.push_back('X');
	}
	while (initial >= 5) {
		initial = initial - 5;
		roman_output.push_back('V');
	}
	while (initial >= 4) {
		initial = initial - 4;
		roman_output.push_back('I');
		roman_output.push_back('V');
	}
	while (initial >= 1) {
		initial = initial - 1;
		roman_output.push_back('I');
	}
	return roman_output;
};