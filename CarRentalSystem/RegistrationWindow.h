#pragma once
//#include"Interface.h";
//#include"Car.h";
//#include"Expense.h"
//#include"Income.h"
#include<map>
#include"InterfaceList.h"

class RegistrationWindow {
	shared_ptr<InterfaceList> interfaceListPtr;
	//CarList* carListPtr;
	//IncomeList* incomeListPtr;
	//ExpenseList* expenseListPtr;
public:
	//RegistrationScreen(InterfaceList* interfaceListPtr, CarList* carListPtr, IncomeList* incomeListPtr, ExpenseList* expenseListPtr);
	~RegistrationWindow();
	RegistrationWindow(shared_ptr<InterfaceList> interfaceListPtr);
	shared_ptr<PersonalData> createPersonalData();
	Interface* registrate();
	Interface* registrateAsUser();
	Interface* registrateAsAdmin();
	Interface* registrateAsOwner();
	//Interface* registrate();
};
