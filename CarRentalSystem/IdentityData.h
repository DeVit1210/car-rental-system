#pragma once
#include<iostream>
#include<string>

using namespace std;

class IdentityData {
private:
	string passportSeries;
	string cardNumber;
	string drivingLicenseSeries;
	double moneyOnAccount;
public:
	IdentityData();
	~IdentityData();
	void setPassportSeries(string passport);
	void setCardNumber(string cardNumber);
	void setDrivingLicenseSeries(string drivingLicence);
	string getPassportSeries() const;
	string getCardNumber() const;
	string getDrivingLicenseSeries() const;
	void addMoney(double amount);
	void setData();
	void display() const;
	friend ostream& operator<<(ostream& out, const IdentityData& obj);
	friend istream& operator>>(istream& in, IdentityData& obj);
};