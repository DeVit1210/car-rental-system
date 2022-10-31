#include"StartWindow.h"
#include"Validator.h"
#include<iostream>
//temporary code
#include<fstream>
#include"UserInterface.h"
//temporary code

using namespace std;

void StartWindow::run() {
	//interfaceListPtr->read();
	//temporary code
	ifstream fin("fileTest.txt");
	Interface* i = new UserInterface();
	i->read(fin);
	//temporary code
	interfaceListPtr = make_shared<InterfaceList>();
	Interface* currentInterface = nullptr;
	cout << "\n  Вас привествует каршеринг POEZDKA!\n\n  1. Регистрация\n  2. Авторизация\n\n";
	switch (Validator::getValidNumber(1, 2))
	{
	case 1: registartionScreenPtr = make_unique<RegistrationWindow>(interfaceListPtr);
		currentInterface = registartionScreenPtr->registrate();
		break;
	case 2: authorizationScreenPtr = make_unique<AuthorizationWindow>(interfaceListPtr);
		currentInterface = authorizationScreenPtr->logIn();
		break;
	}
	// currentInterface->interact();
}

