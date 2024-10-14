#include<iostream>
using namespace std;

bool special_sym(char in) {
	string chars = "!#$ % &'*+-/=?^_`{|}~";

	for (int i = 0; i < chars.length(); i++) {
		if (chars[i] == in) return true;
	}
	return false;
}

bool check(string in, bool sp = false) {

	string lastchar;

	for (int i = 0; i < in.length(); i++) {    //смотрим, есть ли буквы и цифры
		if ((in[i] >= 'A' && in[i] <= 'Z') || 
				(in[i] >= 'a' && in[i] <= 'z') || 
					(in[i] >= '0' && in[i] <= '9') ||
						in[i] == '-') {
			continue;  
		}
		else if (in[i] == '.') {  //смотрим, чтобы точки не шли друг за другом
			if(in[i - 1] == '.')return false;
			continue;
		}
		else if (sp)                              // смотрим спец символы по необходимости
		{
			if (!special_sym(in[i])) return false;
			continue;
		}
		else {										//если символ недопустимый
			return false;
		}

	}

	return true;									//если все хорошо
}

bool leftCheck(string in) {

	if (in[0] == '.') return false;
	if (in[in.length() - 1] == '.') return false;
	if (in.length() > 64) return false;

	if (check(in, 1)) { return true; }
	else { return false; }

}

bool rightCheck(string in) {

	if (in[0] == '.') return false;
	if (in[in.length() - 1] == '.') return false;
	if (in.length() > 63) return false;

	if (check(in)) { return true; }
	else { return false; }
}

string email(string in) {

	int pos = 0;


	string left = "", right = "";


	for (pos; pos < in.length(); pos++) { //выделяем левую часть
		if (in[pos] == '@') {
			pos++;
			break;
		}
		else {
			left += in[pos];
		}
	}

	for (pos; pos < in.length(); pos++) { //выделяем правую часть и смотрим, чтобы не было собак
		if (in[pos] == '@') return "No";
		right += in[pos];
	}

	if (right.length() < 1) return "No";   //если нет собачек

	if (leftCheck(left) && rightCheck(right)) {
		return "Yes";
	}
	else {
		return "No";
	}

}


void main() {
	setlocale(LC_ALL, "rus");

	string input;
	
	cout << "Input: ";
	cin >> input;

	cout << email(input) << endl;

	//main();
}