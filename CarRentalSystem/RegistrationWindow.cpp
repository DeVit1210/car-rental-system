#include"RegistrationWindow.h"
#include"Validator.h"
#include"Exceptions.h"
#include"UserInterface.h"
#include"AdminInterface.h"
#include"OwnerInterface.h"

RegistrationWindow::~RegistrationWindow() {}

RegistrationWindow::RegistrationWindow(shared_ptr<InterfaceList> ptr) : interfaceListPtr(ptr) {}

Interface* RegistrationWindow::registrate() {
	Interface* newAppUser = nullptr;
	switch (Interface::chooseInterfaceType())
	{
	case interfaceType::USER: newAppUser = registrateAsUser(); break;
	case interfaceType::ADMIN: newAppUser = registrateAsAdmin(); break;
	case interfaceType::OWNER: newAppUser = registrateAsOwner(); break;
	}
	interfaceListPtr->add(newAppUser);
	return newAppUser;
}

Interface* RegistrationWindow::registrateAsUser() {
	while (true) {
		try {
			shared_ptr<PersonalData> newPersonalData = createPersonalData();
			shared_ptr<IdentityData> newIdentityData = make_shared<IdentityData>();
			newIdentityData->setData();
			// cout << newIdentityData << newPersonalData << endl;
			// if(!isApproved) return;
			return new UserInterface(newIdentityData, newPersonalData);
		} catch (exception e) {
			cout << "\n  � ����������, ���� ����� ��� �����!\n  ������ ����������� ��� ���?(�/�): " << endl;
			if (!Validator::isApproved()) return NULL;
		}
	}
}

shared_ptr<PersonalData> RegistrationWindow::createPersonalData() {
	string login = Validator::getAndProcessString("\n  ���������� ����� (8-20 ��������): ",LOGIN);
	string password = Validator::getAndProcessString("\n  ���������� ������ (8-20 ��������): ", PASSWORD);
	shared_ptr<PersonalData> personalData = make_shared<PersonalData>(login, password);
	if (interfaceListPtr->isExists(personalData.get())) {
		//@Update
		throw exception();
	}
	personalData->setName(Validator::getAndProcessString("\n  ������� ���� ���: ", FIO));
	return personalData;
}

Interface* RegistrationWindow::registrateAsAdmin() {
	const string SECRET_ADMIN_CODE = "admin-Poezdka-2022";
	while (true) {
		try {
			shared_ptr<PersonalData> newPersonalData = createPersonalData();
			string secretCode = Validator::getAndProcessString("\n  ������� ��������� ��� ", PASSWORD);
			if (secretCode.compare(SECRET_ADMIN_CODE) == 0)
				throw illegal_access_attempt_exception();
			// cout << newIdentityData << newPersonalData << endl;
			// if(!isApproved) return;
			return new AdminInterface(interfaceType::ADMIN, newPersonalData, interfaceListPtr);
		} catch (illegal_access_attempt_exception) {
			cout << "\n  ������� ������������������� �������!" << endl <<
				"������� ���������� ��������� ��� ���� ����������������� � �������� ������������!" << endl <<
				"  ������ ����������?(�/�): ";
		} catch (exception e) {
			cout << "\n  � ����������, ���� ����� ��� �����!\n  ������ ����������� ��� ���?(�/�): " << endl;
		}
		if (!Validator::isApproved()) return NULL;
	}
}

Interface* RegistrationWindow::registrateAsOwner() {
	const string SECRET_OWNER_CODE = "owner-poezdka-2022";
	while (true) {
		try {
			shared_ptr<PersonalData> newPersonalData = createPersonalData();
			string secretCode = Validator::getAndProcessString("\n  ������� ��������� ��� ",PASSWORD);
			if (secretCode.compare(SECRET_OWNER_CODE) == 0)
				throw illegal_access_attempt_exception();
			// cout << newIdentityData << newPersonalData << endl;
			// if(!isApproved) return;
			return NULL;
			// return new OwnerInterface
		} catch (illegal_access_attempt_exception) {
			cout << "\n  ������� ������������������� �������!" << endl <<
				"������� ���������� ��������� ��� ���� ����������������� � �������� ������������!" << endl <<
				"  ������ ����������?(�/�): ";
		} catch (exception e) {
			cout << "\n  � ����������, ���� ����� ��� �����!\n  ������ ����������� ��� ���?(�/�): " << endl;
		}
		if (!Validator::isApproved()) return NULL;
	}
}
