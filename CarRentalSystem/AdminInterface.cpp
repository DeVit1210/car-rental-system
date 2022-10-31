#include"AdminInterface.h"
#include"InterfaceList.h"
#include"Interface.h"
#include"PersonalData.h"
#include<iostream>
#include<memory>

using namespace std;

AdminInterface::AdminInterface() {

}

// ask about built-in pointers
// problem : can not use shared_ptr as a parameter for constructor for some reason

AdminInterface::AdminInterface(interfaceType type, shared_ptr<PersonalData> personalDataPtr, shared_ptr<InterfaceList> ptr)
	: Interface(type, personalDataPtr) {
	this->interfaceListPtr = ptr;
}

AdminInterface::~AdminInterface() {}

void AdminInterface::setSalary(float salary) { this->salary = salary; }

float AdminInterface::getSalary() { return this->salary; }

void AdminInterface::interact() {
	//@Update
}

void AdminInterface::interfaceMenu() {
	//@Update
}

void AdminInterface::write(ofstream& fout) {
	//@Update
}

void AdminInterface::read(ifstream& fin) {
	//@Update
}

