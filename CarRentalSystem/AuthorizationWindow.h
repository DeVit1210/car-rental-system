#pragma once
#include<string>
#include"Interface.h"
#include"InterfaceList.h"
//#include"Car.h";
//#include"Expense.h"
//#include"Income.h"
#include<map>

using namespace std;

class AuthorizationWindow {
	shared_ptr<InterfaceList> interfaceListPtr;
	string loginToCheck;
	string passwordToCheck;
public:
	AuthorizationWindow(shared_ptr<InterfaceList> interfaceListPtr);
	~AuthorizationWindow();
	Interface* logIn();
};
