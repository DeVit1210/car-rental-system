#pragma once
#include<iostream>
#include<map>
#include"List.h"
#include"Interface.h"
#include"PersonalData.h"

using namespace std;

class InterfaceList : public List<Interface> {
private:
	const char* fileName = "appUsers.txt";
	map<PersonalData*, Interface*> interfaceMap;
	map<PersonalData*, Interface*>::iterator iter;
public:
	void add(Interface* _interface) override;
	void remove(size_t index) override;
	void read() override;
	void write() override;
	void display() override;
	Interface* get(size_t index) override;
	Interface* find(PersonalData*);
	bool isExists(PersonalData*);
};
