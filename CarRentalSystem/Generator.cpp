#include "Generator.h"
#include<iostream>
#include<string>
#include<random>

using namespace std;

string Generator::generateCode(size_t size) {
	const static char digits[11] = "0123456789";
	srand(time(NULL));
	string code;
	for (size_t i = 0; i < size; i++) {
		code.append(to_string(digits[rand() % 11]));
	}
	return code;
}
