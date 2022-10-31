#include "PersonalData.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include"PersonalData.h"
#include"Generator.h"
#include"Validator.h"

using namespace std;

PersonalData::PersonalData() {
	this->id = Generator::generateCode(6);
}

PersonalData::~PersonalData() {
}

void PersonalData::setid() {
	this->id = Generator::generateCode(6);
}

PersonalData::PersonalData(string login, string password) {
	this->login = login;
	this->password = password;
}

void PersonalData::setLogin(string login) { this->login = login; }

void PersonalData::setPassword(string password) { this->password = password; }

void PersonalData::setName(string name) { this->name = name; }

string PersonalData::getId() const { return this->id; }

string PersonalData::getLogin() const { return this->login; }

string PersonalData::getPassword() const { return this->password; }

string PersonalData::getName() const { return this->name; }

bool PersonalData::operator==(const PersonalData& obj) {
	return (login == obj.login && password == obj.password);
}

void PersonalData::setData() {
	setid();
	setLogin(Validator::getAndProcessString("\n  Придумайте логин: ",LOGIN));
	setPassword(Validator::getAndProcessString("\n  Придумайте пароль: ", PASSWORD));
	setName(Validator::getAndProcessString("\n  Введите ФИО: ", FIO));
}

void PersonalData::display() const {
	cout << setw(5) << this->id << setw(10) << this->name << setw(10) << this->login << setw(10) << this->password;
}

ostream& operator<<(ostream& out, const PersonalData& obj) {
	const char delimeter = ' ';
	out << obj.name << endl << obj.id << delimeter << obj.login << delimeter << obj.password << delimeter << endl;
	return out;
}

istream& operator>>(istream& in, PersonalData& obj) {
	string tempString;
	getline(in, tempString);
	obj.name = tempString;
	getline(in, tempString);
	istringstream stream(tempString);
	stream >> obj.id >> obj.login >> obj.password;
	return in;
}