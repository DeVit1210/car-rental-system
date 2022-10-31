#pragma once
#include<iostream>
#include<string>

using namespace std;

class PersonalData {
private:
	string id;
	string login;
	string password;
	string name;
public:
	PersonalData();
	PersonalData(string login, string password);
	~PersonalData();
	void setData();
	void setid();
	void setLogin(string login);
	void setPassword(string password);
	void setName(string name);
	string getId() const;
	void display() const;
	string getLogin() const;
	string getPassword() const;
	string getName() const;
	bool operator==(const PersonalData& obj);
	friend ostream& operator<<(ostream& out, const PersonalData& obj);
	friend istream& operator>>(istream& in, PersonalData& obj);
};
