#pragma once
#include<iostream>
#include<memory>
#include<string>
#include"RegistrationWindow.h"
#include"AuthorizationWindow.h"
#include"InterfaceList.h"
//#include"AdminScreens.h"
//#include"UserScreens.h"
//#include"Income.h"
//#include"Expense.h"
//#include"Interface.h"
//#include"Car.h"
//#include"AuthorizationAndRegistrationScreen.h"

class StartWindow {
	unique_ptr<RegistrationWindow> registartionScreenPtr;
	unique_ptr<AuthorizationWindow> authorizationScreenPtr;
	shared_ptr<InterfaceList> interfaceListPtr;
	//CarList* carListPtr;
	//IncomeList* incomeListPtr;
	//ExpenseList* expenseListPtr;
	//Report* reportPtr;
	//CompanyAccount* companyAccountPtr;
	//CarOrderScreen* carOrderPtr;
	//AccountReplenishmentScreen* accountReplenishmentPtr;
	//SubscriptionMakingScreen* subscriptionMakingPtr;
	//CarAddingScreen* carAddingPtr;
	//CarRemovingScreen* carRemovingPtr;
	//ExpenseAddingScreen* expenseAddingPtr;
	int choice;
public:
	void run();
};

