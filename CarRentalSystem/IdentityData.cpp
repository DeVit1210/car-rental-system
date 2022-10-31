#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
#include"IdentityData.h"
#include"Validator.h"

using namespace std;

IdentityData::IdentityData() {
	this->moneyOnAccount = 0.0;
}

IdentityData::~IdentityData() {}

void IdentityData::setPassportSeries(string passport) { this->passportSeries = passport;}

void IdentityData::setCardNumber(string cardNumber) { this->cardNumber = cardNumber;}

void IdentityData::setDrivingLicenseSeries(string drivingLicense) { this->drivingLicenseSeries = drivingLicense;}

string IdentityData::getCardNumber() const { return this->cardNumber;}

string IdentityData::getDrivingLicenseSeries() const { return this->drivingLicenseSeries;}

string IdentityData::getPassportSeries() const { return this->passportSeries;}

void IdentityData::addMoney(double amount) { this->moneyOnAccount += amount; }

void IdentityData::setData() {
	setPassportSeries(Validator::getAndProcessString("\n  ¬ведите серию и номер паспорта (2 буквы + 6 цифр): ", PASPORT));
	setDrivingLicenseSeries(Validator::getAndProcessString("\n  ¬ведите номер вашего водительского удостоверени€: ", DRIVING_LICENSE));
	setCardNumber(Validator::getAndProcessString("\n  ¬ведите номер вашей карты: ", CARD_NUMBER));
}

//@Update
void IdentityData::display() const {
	cout << setw(5) << this->moneyOnAccount << setw(10) << this->cardNumber
		<< setw(10) << this->passportSeries << setw(10) << this->drivingLicenseSeries;
}


ostream& operator<<(ostream& out, const IdentityData& obj) {
	const char delimeter = ' ';
	out << obj.passportSeries << delimeter << obj.drivingLicenseSeries << delimeter <<
		obj.cardNumber << endl << obj.moneyOnAccount << endl;
	return out;
}

istream& operator>>(istream& in, IdentityData& obj) {
	string tempString;
	getline(in, tempString);
	istringstream stream(tempString);
	stream >> obj.passportSeries >> obj.drivingLicenseSeries >> obj.cardNumber;
	in >> obj.moneyOnAccount;
	return in;
}