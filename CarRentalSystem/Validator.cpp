#include<iostream>
#include<string>
#include"Validator.h"
#include<regex>
#include<conio.h>
#include"Exceptions.h"
#include<map>

using namespace std;

map<stringType, ValidationData*> Validator::validation;

Validator::Validator() {
	validation.insert(pair<stringType, ValidationData*>(
		PASPORT, new ValidationData(
			"[A-Z]{2}\\d{7}","\n  Серия и номер паспорта должны быть введены в виде: 2 заглавные буквы + 7 цифр!\n  Попробуйте еще раз: ")));
	validation.insert(pair<stringType, ValidationData*>(
		DRIVING_LICENSE, new ValidationData(
			"\\d{10}", "\n  Номер водительского удостоверения должен содержать 10 цифр!\n  Попробуйте еще раз: ")));
	validation.insert(pair<stringType, ValidationData*>(
		CARD_NUMBER, new ValidationData(
			"\\d{16}", "\n  Номер карты должен содержать 16 цифр!\n  Попробуйте еще раз: ")));
	validation.insert(pair<stringType, ValidationData*>(
		MAKE, new ValidationData(
			"[A-ZА-Я]{1,4}[a-zа-я]*\\s?[A-ZА-Я]?[a-zа-я]*", "\n  Такой марки авто не существует!\n  Попробуйте еще раз: ")));
	validation.insert(pair<stringType, ValidationData*>(
		CARD_NUMBER, new ValidationData(
			"[A-ZА-Я]{1,4}[a-zа-я]*\\s?[A-ZА-Я]?[a-zа-я]*", "\n  Такой модели не существует!\n  Попробуйте еще раз: ")));
	validation.insert(pair<stringType, ValidationData*>(
		PASSWORD, new ValidationData(
			"(?=.*?[a-z])(?=.*?[A-Z])(?=.*?[0-9])[a-zA-Z0-9]{8,15}",
			"\n  Пароль должен состоять из 8-15 символов, содержать минимум одну прописную, заглавную буквы и цифру!\n  Попробуйте еще раз: ")));
	validation.insert(pair<stringType, ValidationData*>(
		LOGIN, new ValidationData(
		"(?=.*?[a-z])(?=.*?[A-Z])(?=.*?[0-9])[a-zA-Z0-9]{8,15}",
			"\n  Логин должен состоять из 8-15 символов, содержать минимум одну прописную, заглавную буквы и цифру!\n  Попробуйте еще раз: ")));
	validation.insert(pair<stringType, ValidationData*>(
		FIO, new ValidationData(
			"([А-Я]{1}[а-я]+\\s){2}[А-Я]{1}[а-я]+", "\n  Некоректный ввод ФИО!\n  Попробуйте еще раз: ")));
}

bool Validator::checkLength(string stringToCheck, size_t lowerBound, size_t upperBound) {
	try {
		if (stringToCheck.size() < lowerBound) 
			throw string_out_of_bounds_exception(lowerBound, true);
		if (stringToCheck.size() > upperBound)
			throw string_out_of_bounds_exception(upperBound, false);
		return true;
	} catch (string_out_of_bounds_exception e) {
		e.printException();
		return false;
	}
}

bool Validator::checkRange(int valueToCheck, size_t lowerBound, size_t upperBound) {
	return !(valueToCheck < lowerBound || valueToCheck > upperBound);
}

bool Validator::checkRangeWithMessage(int valueToCheck, size_t lowerBound, size_t upperBound) {
	try {
		if (valueToCheck < lowerBound || valueToCheck > upperBound)
			throw value_size_exception(lowerBound, upperBound);
		return true;
	} catch (value_size_exception e) {
		e.printException();
		return false;
	}
}

bool Validator::isInputValid(string stringToCheck, stringType type) {
	return isRegexMatches(stringToCheck, validation.find(type)->second);

}

string Validator::getAndProcessString(string message, stringType type) {
	cout << message;
	string str;
	while (true) {
		getline(cin, str);
		if (isInputValid(str, type))
			break;
	}
	return str;
}
int Validator::getValidNumber(int lowerBound, int upperBound, const char* message) {
	if (!strcmp(message, ""))
		cout << message;
	return getValidNumber(lowerBound, upperBound);
}

bool Validator::isRegexMatches(string stringToCheck, ValidationData* ptr) {
	if (!regex_match(stringToCheck, ptr->regExp)) {
		cout << ptr->messageIfNot;
		return false;
	}
	else return true;
}

bool Validator::isApproved() {
	//cout << " ";
	char symbol;
	cin >> symbol;
	return _getch() != 'н';
}

int Validator::getValidNumber(int lowerBound, int upperBound) {
	int value;
	while (true) {
		try {
			cin >> value;
			if (cin.fail())
				throw thread_fairure_exception();
			if (!Validator::checkRange(value, lowerBound, upperBound)) 
				throw value_size_exception(lowerBound, upperBound);
			cin.ignore(32767, '\n');
			return value;
		} catch (thread_fairure_exception e) {
			e.clear_bufer();
		} catch (value_size_exception e) {
			e.printException();
		}
	}
}


//Date Validator::getValidDate(string message) {
//	regex regEx("(0[1-9]|[1-2][0-9]|3[0-1])\/(0[1-9]|1[0-2])\/(19[4-9][0-9]|20[0-1][0-9]|202[0-2])");
//	cout << message;
//	string buffer;
//	Date newDate;
//	char symbol;
//	while (true) {
//		for (size_t i = 0; i < 8; i++) {
//			cin >> symbol;
//			cout << symbol;
//			if (i == 1 || i == 3)
//				cout << "/";
//		}
//		if (regex_match(buffer, regEx)) {
//			newDate.setDay(stoi(buffer.substr(0, 2)));
//			newDate.setMonth(stoi(buffer.substr(3, 2)));
//			newDate.setYear(stoi(buffer.substr(6, 4)));
//			break;
//		}
//		else cout << "Invalid input! Try again: ";
//	}
//	return newDate;
//}