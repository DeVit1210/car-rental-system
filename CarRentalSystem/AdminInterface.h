#pragma once
#include"Interface.h"
#include"InterfaceList.h"
#include<fstream>
class AdminInterface : public Interface {
	float salary;
	//CarList* carListPtr;
	shared_ptr<InterfaceList> interfaceListPtr;
	//ReportCreator* reportCreatorPtr;
	//ExpenseList* expensesListPtr;
	//IncomeList* incomeListPtr;
	//CompanyAccount* companyAccountPtr;
	//CarAddingScreen* carAddingScreenPtr;
	//CarRemovingScreen* carRemovingScreenPtr;
	//ExpenseAddingScreen* expenseAddingScreenPtr;
public:
	AdminInterface();
	// temporary constructor
	AdminInterface(interfaceType type, shared_ptr<PersonalData> personalDataPtr, shared_ptr<InterfaceList> ptr);

	//AdminInterface(CarList* carListPtr, PersonalData* personalDataPtr, Checking* checkingPtr, interfaceType type,
	//	InterfaceList* interfaceListPtr, ExpenseList* expensesListPtr, IncomeList* incomeListPtr);

	~AdminInterface();
	void setSalary(float salary);
	float getSalary();
	void interact() override;
	void interfaceMenu() override;
	void write(ofstream& fout) override;
	void read(ifstream& fin) override;
};