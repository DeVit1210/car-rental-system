#include "AuthorizationWindow.h"
#include"Validator.h"
#include"Exceptions.h"
#include<memory>

AuthorizationWindow::AuthorizationWindow(shared_ptr<InterfaceList> interfaceListPtr) {
	this->interfaceListPtr = interfaceListPtr;
}

AuthorizationWindow::~AuthorizationWindow() {}

Interface* AuthorizationWindow::logIn() {
	while (true) {
		loginToCheck = Validator::getAndProcessString("\n  Введите ваш логин: ", LOGIN);
		passwordToCheck = Validator::getAndProcessString("\n  Введите ваш пароль: ",PASSWORD);
		try {
			unique_ptr<PersonalData> temp = make_unique<PersonalData>(loginToCheck, passwordToCheck);
			return interfaceListPtr->find(temp.get());
		}
		//@Update
		catch (no_such_element_exception e) {
			cout << "\n  К сожалению, вы ввели неверный логин или пароль!\nХотите попробовать еще раз?(д/н): ";
		}
		if (!Validator::isApproved()) break;
		system("cls");
	}
}