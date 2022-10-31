#include"InterfaceList.h"
#include"Exceptions.h"
#include<iostream>
#include<fstream>
using namespace std;

void InterfaceList::add(Interface* appUser) {
	interfaceMap.insert(pair<PersonalData*, Interface*>(appUser->getPersonalData(), appUser));
}

void InterfaceList::display() {
	for (const auto& elem : interfaceMap) {
		elem.second->display();
	}
}

Interface* InterfaceList::get(size_t index) {
	if (index > interfaceMap.size())
		throw container_out_of_bounds_exception(typeid(*this).name());
	iter = interfaceMap.begin();
	advance(iter, index);
	return iter->second;
}

void InterfaceList::remove(size_t index) {
	if (index > interfaceMap.size())
		throw container_out_of_bounds_exception(typeid(*this).name());
	iter = interfaceMap.begin();
	advance(iter, index);
	interfaceMap.erase(iter);
	cout << "\n  Удаление выполнено успешно!" << endl;
}

void InterfaceList::write() {
	ofstream fout;
	fout.open(fileName, ios::out);
	try {
		if (!fout.is_open())
			throw new file_opening_exception(fileName, true);
		fout << interfaceMap.size() << endl;
		//@Update
		for (const auto& elem : interfaceMap) {
			elem.second->write(fout);
		}
		fout.close();
	} catch (file_opening_exception* e) {
		cout << e << endl;
		fout.close();
	}
}

void InterfaceList::read() {
	ifstream fin;
	fin.open(fileName, ios::in);
	try {
		if (!fin.is_open())
			throw new file_opening_exception(fileName, false);
		size_t size;
		if (!(fin >> size))
			throw new empty_file_exception();
		//@Update
		for (const auto& elem : interfaceMap) {
			elem.second->read(fin);
		}
		fin.close();
	} catch (file_opening_exception* e) {
		cout << e << endl;
		fin.close();
	} catch (empty_file_exception* e) {
		cout << e->what() << endl;
		fin.close();
	}
}

Interface* InterfaceList::find(PersonalData* temp) {
	map<PersonalData*, Interface*>::iterator appUser = interfaceMap.find(temp);
	if (appUser == interfaceMap.end()) {
		throw no_such_element_exception();
	}
	return appUser->second;
}

bool InterfaceList::isExists(PersonalData* temp) {
	iter = interfaceMap.begin();
	return !(interfaceMap.find(temp) == interfaceMap.end());
}