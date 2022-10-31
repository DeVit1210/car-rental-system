#include<iostream>
#include<iomanip>
#include<string>
#include"Interface.h"
#include"Validator.h"

using namespace std;

Interface::Interface() : type(interfaceType::USER), choice(0) {  }

Interface::Interface(interfaceType type, shared_ptr<PersonalData> personalDataPtr) : choice(0) {
	this->type = type;
	this->personalDataPtr = personalDataPtr;
}

Interface::~Interface() { }

interfaceType Interface::getType() const { return this->type; }

string Interface::typeToString() {
	switch (type) {
	case interfaceType::USER: return "user";
		break;
	case interfaceType::USER_WITH_SUBSCRIPTION: return "user with subscription";
		break;
	case interfaceType::ADMIN: return "admin";
		break;
	case interfaceType::OWNER: return "owner";
		break;
	}
}

void Interface::display() { cout << this->typeToString(); }

PersonalData* Interface::getPersonalData() const {
	return this->personalDataPtr.get();
}

interfaceType Interface::chooseInterfaceType() {
	cout << "\n  1. Зарегистрироваться как пользователь\n  2. Зарегистрироваться как администратор"
		"\n  3. Зарегистрироваться как владелец\n  " << endl;
	Validator v;
	int value = v.getValidNumber(1, 3);
	return static_cast<interfaceType>(Validator::getValidNumber(1, 3));

}