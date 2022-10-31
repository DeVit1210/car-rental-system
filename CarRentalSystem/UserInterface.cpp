#include "UserInterface.h"


UserInterface::UserInterface() {}

UserInterface::UserInterface(shared_ptr<IdentityData> identityDataPtr, shared_ptr<PersonalData> personalDataPtr) {
	this->identityDataPtr = identityDataPtr;
	this->personalDataPtr = personalDataPtr;
}

UserInterface::~UserInterface() {
	Interface::~Interface();
}

void UserInterface::interact() {
	//@Update
}

void UserInterface::interfaceMenu() {
	//@Update
}

void UserInterface::write(ofstream& fout) {
	fout << *(this->personalDataPtr);
	fout << *(this->identityDataPtr);
}

void UserInterface::read(ifstream& fin) {
	PersonalData data;
	fin >> data;
	personalDataPtr = make_shared<PersonalData>(data);
	IdentityData iData;
	fin >> iData;
	identityDataPtr = make_shared<IdentityData>(iData);
}

