#pragma once
#include<iostream>
#include<map>
#include"PersonalData.h"
//#include"Checking.h"
//#include"IdentityData.h"
//#include"List.h"
//#include"UserScreens.h"
//#include"AdminScreens.h"
//#include"Expense.h"
//#include"Income.h"

using namespace std;

enum class interfaceType {
	USER = 1,
	USER_WITH_SUBSCRIPTION = 0,
	ADMIN = 2,
	OWNER
};


class Interface {
protected:
	//const string INVALID_INPUT = "Invalid input! Try again: ";
	shared_ptr<PersonalData> personalDataPtr;
	interfaceType type;
	int choice;
public:
	Interface();
	Interface(interfaceType type, shared_ptr<PersonalData> personalDataPtr);
	~Interface();
	interfaceType getType() const;
	string typeToString();
	PersonalData* getPersonalData() const;
	virtual void interact() = 0;
	virtual void interfaceMenu() = 0;
	virtual void write(ofstream& fout) = 0;
	virtual void read(ifstream& fin) = 0;
	void display();
	static interfaceType chooseInterfaceType();

};
