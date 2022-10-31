#pragma once
#include<iostream>
#include<string>
//#include"Car.h"
//#include"Characteristics.h"
#include<regex>
#include<map>

enum stringType {
	LOGIN, PASSWORD, FIO, PASPORT, DRIVING_LICENSE, 
	CARD_NUMBER, MAKE, MODEL, LEVEL, BODY, MAX_SIZE
};

using namespace std;

class ValidationData {
public:
	regex regExp;
	string messageIfNot;
	ValidationData(string reg, string messageIfNot) {
		this->regExp.assign(reg);
		this->messageIfNot = messageIfNot;
	}
};

class Validator {
	static map<stringType, ValidationData*> validation;
public:
	Validator();
	static bool checkLength(string stringToCheck, size_t lowerBound, size_t upperBound);
	static bool checkRange(int value, size_t lowerBound, size_t upperBound);
	static bool checkRangeWithMessage(int value, size_t lowerBound, size_t upperBound);
	static string getAndProcessString(string message, stringType type);
	static int getValidNumber(int lowerBound, int upperBound, const char* message);
	// template<typename T>
	// static T getValidNumber(size_t lowerBound, size_t upperBound)
	static int getValidNumber(int lowerBound, int upperBound);
	static bool isInputValid(string stringToCheck, stringType type);
	static bool isRegexMatches(string stringToCheck, ValidationData* ptr);
	static bool isApproved();
};

